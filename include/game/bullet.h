#ifndef BULLET_H
#define BULLET_H

#include <sprite.h>
#include <scene.h>
#include <math/vec2.h>

typedef struct Bullet {
    Sprite* sprite;
    Scene* scene;

    Vec2 direction;
    f32 speed;
} Bullet;

Bullet* bullet_new(Scene* scene, f32 x, f32 y, Vec2 direction);
void bullet_delete(Bullet* bullet);

#endif
