#ifndef SHRIMP_H
#define SHRIMP_H

#include <engine/sprite.h>
#include <engine/scene.h>
#include <engine/aabb.h>
#include <engine/cglm/cglm.h>

typedef struct Shrimp {
    Scene* scene;
    Sprite* sprite;
    AABB* hitbox;

    i32 hp;

    bool is_moving[2];
    f32 speed_multiplier;
    f32 speed;
    f32 jump_force;

    vec2 cursor_pos;

    bool can_jump;
} Shrimp;

Shrimp* shrimp_new(Scene* scene);
void shrimp_delete(Shrimp* shrimp);

#endif
