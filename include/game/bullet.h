#ifndef BULLET_H
#define BULLET_H

#include <sprite.h>
#include <scene.h>
#include <game/shrimp.h>
#include <types.h>

typedef struct Bullet {
    Sprite* sprite;

    f32 direction[2];
} Bullet;

Bullet* bullet_new(Scene* scene, Shrimp* shrimp);
void bullet_delete(Bullet* bullet);

#endif
