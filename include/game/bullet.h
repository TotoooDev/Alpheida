#ifndef BULLET_H
#define BULLET_H

#include <engine/sprite.h>
#include <engine/scene.h>
#include <engine/cglm/cglm.h>

typedef struct Bullet {
    Sprite* sprite;
    Scene* scene;

    vec2 direction;
    f32 speed;

    bool delete_next_update;
} Bullet;

Bullet* bullet_new(Scene* scene, f32 x, f32 y, vec2 direction);
void bullet_delete(Bullet* bullet);

#endif
