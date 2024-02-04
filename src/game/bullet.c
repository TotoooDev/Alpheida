#include <game/bullet.h>
#include <engine/event.h>
#include <engine/app.h>
#include <engine/log.h>
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
    bullet->delete_next_update = true;
}

void bullet_update(Sprite* sprite, f32 timestep) {
    Bullet* bullet = (Bullet*)sprite->user_pointer;
    sprite->pos[0] += bullet->direction[0] * bullet->speed * timestep;
    sprite->pos[1] += bullet->direction[1] * bullet->speed * timestep;

    if (sprite->pos[0] <= 0.0f || sprite->pos[0] >= window_get_width(app_get_window()))
        bullet->delete_next_update = true;
    if (sprite->pos[1] <= 0.0f || sprite->pos[1] >= window_get_height(app_get_window()))
        bullet->delete_next_update = true;

    if (bullet->delete_next_update)
        bullet_delete(bullet);
}

Bullet* bullet_new(Scene* scene, f32 x, f32 y, vec2 direction) {
    Bullet* bullet = (Bullet*)malloc(sizeof(Bullet));

    if (first_texture) {
        bullet_texture = texture_new("images/bullet.png");
        first_texture = false;
        event_add_function(bullet, bullet_event_function_delete_texture);
    }

    bullet->scene = scene;
    bullet->speed = 1000.0f;
    bullet->delete_next_update = false;
    glm_vec2_copy(direction, bullet->direction);

    vec2 pos = { x, y };
    vec2 scale = { 64.0f, 64.0f };
    bullet->sprite = sprite_new(pos, scale, bullet_texture);
    bullet->sprite->keep_texture_on_delete = true;
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
