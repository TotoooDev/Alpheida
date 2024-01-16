#ifndef SHRIMP_H
#define SHRIMP_H

#include <sprite.h>
#include <scene.h>
#include <aabb.h>
#include <math/vec2.h>

typedef struct Shrimp {
    Scene* scene;
    Sprite* sprite;
    AABB* hitbox;

    bool is_moving[2];
    f32 speed_multiplier;
    f32 speed;

    Vec2 cursor_pos;

    bool can_jump;
} Shrimp;

Shrimp* shrimp_new(Scene* scene);
void shrimp_delete(Shrimp* shrimp);

#endif
