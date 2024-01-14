#ifndef SHRIMP_H
#define SHRIMP_H

#include <sprite.h>
#include <scene.h>
#include <aabb.h>
#include <types.h>

typedef struct Shrimp {
    Scene* scene;
    Sprite* sprite;
    AABB* hitbox;

    bool is_moving[2];
    f32 speed_multiplier;
    f32 speed;

    bool can_jump;
} Shrimp;

Shrimp* shrimp_new(Scene* scene);
void shrimp_delete(Shrimp* shrimp);

#endif
