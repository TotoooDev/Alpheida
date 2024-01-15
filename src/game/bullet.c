#include <game/bullet.h>
#include <event.h>
#include <stdlib.h>

bool first_texture = true;
Texture* bullet_texture = NULL;

void bullet_event_function_delete_texture(void*, EventType event_type, void* user_pointer) {
    if (event_type == EVENT_TYPE_PLATFORM_QUIT && bullet_texture != NULL) {
        texture_delete(bullet_texture);
        bullet_texture = NULL;
    }
}

void bullet_update(Sprite* sprite, f32 timestep) {
    Bullet* bullet = (Bullet*)sprite->user_pointer;
    sprite->aabb->x += bullet->direction[0] * timestep;
    sprite->aabb->y += bullet->direction[1] * timestep;
}

Bullet* bullet_new(Scene* scene, Shrimp* shrimp) {
    if (first_texture) {
        bullet_texture = texture_new("images/bullet.png");
        first_texture = false;
    }

    Bullet* bullet = (Bullet*)malloc(sizeof(Bullet));
    bullet->direction[0] = 1.0f;
    bullet->direction[1] = 1.0f;

    bullet->sprite = sprite_new(
        shrimp->sprite->aabb->x,
        shrimp->sprite->aabb->y,
        shrimp->sprite->aabb->width,
        shrimp->sprite->aabb->height,
        bullet_texture
    );
    bullet->sprite->user_pointer = bullet;

    bullet->sprite->update_function = bullet_update;

    PhysicsObject* physics = physics_add_physics_object(scene_get_physics_world(scene), bullet->sprite);
    physics->is_trigger = true;
    physics->takes_gravity = false;

    event_add_function(bullet, bullet_event_function_delete_texture);

    return bullet;
}

void bullet_delete(Bullet* bullet) {
    sprite_delete(bullet->sprite);
}
