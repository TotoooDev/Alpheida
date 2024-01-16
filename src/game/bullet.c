#include <game/bullet.h>
#include <event.h>
#include <log.h>
#include <stdlib.h>

bool first_texture = true;
Texture* bullet_texture = NULL;

void bullet_event_function_delete_texture(void*, EventType event_type, void* user_pointer) {
    if (event_type == EVENT_TYPE_PLATFORM_QUIT && bullet_texture != NULL) {
        texture_delete(bullet_texture);
        bullet_texture = NULL;
    }
}

void bullet_on_collision(PhysicsObject* object, PhysicsObject* colliding_object, IntersectionAxis axis) {
    Bullet* bullet = (Bullet*)object->user_pointer;
    bullet_delete(bullet);
}

void bullet_update(Sprite* sprite, f32 timestep) {
    Bullet* bullet = (Bullet*)sprite->user_pointer;
    sprite->aabb->x += bullet->direction.x * bullet->speed * timestep;
    sprite->aabb->y += bullet->direction.y * bullet->speed * timestep;
}

Bullet* bullet_new(Scene* scene, f32 x, f32 y, Vec2 direction) {
    Bullet* bullet = (Bullet*)malloc(sizeof(Bullet));

    if (first_texture) {
        bullet_texture = texture_new("images/bullet.png");
        first_texture = false;
        event_add_function(bullet, bullet_event_function_delete_texture);
    }

    bullet->scene = scene;
    bullet->direction = direction;
    bullet->speed = 50.0f;

    bullet->sprite = sprite_new(x, y, 64.0f, 64.0f, bullet_texture);
    bullet->sprite->user_pointer = bullet;

    bullet->sprite->update_function = bullet_update;

    PhysicsObject* physics = physics_add_physics_object(scene_get_physics_world(scene), bullet->sprite);
    physics->is_trigger = true;
    physics->takes_gravity = false;
    physics->user_pointer = bullet;
    physics->on_collision = bullet_on_collision;
    physics->filter |= physics_add_filter(1);

    return bullet;
}

void bullet_delete(Bullet* bullet) {
    physics_remove_physics_object(scene_get_physics_world(bullet->scene), bullet->sprite->physics_object);
    scene_remove_sprite(bullet->scene, bullet->sprite);
    sprite_delete(bullet->sprite);
}
