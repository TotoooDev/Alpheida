#include <game/bullet.h>
#include <event.h>
#include <stdlib.h>

bool first_texture = true;
Texture* bullet_texture = NULL;

void bullet_event_function_delete_texture(void*, EventType event_type, void*) {
    if (event_type == EVENT_TYPE_PLATFORM_QUIT)
        texture_delete(bullet_texture);
}

Bullet* bullet_new(Scene* scene, Shrimp* shrimp) {
    if (first_texture) {
        bullet_texture = texture_new("images/bullet.png");
        first_texture = false;
    }

    Bullet* bullet = (Bullet*)malloc(sizeof(Bullet));

    bullet->sprite = sprite_new(
        shrimp->sprite->aabb->x,
        shrimp->sprite->aabb->y,
        shrimp->sprite->aabb->width,
        shrimp->sprite->aabb->height,
        bullet_texture
    );

    event_add_function(NULL, bullet_event_function_delete_texture);

    return bullet;
}

void bullet_delete(Bullet* bullet) {
    sprite_delete(bullet->sprite);
}
