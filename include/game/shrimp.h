#ifndef SHRIMP_H
#define SHRIMP_H

#include <sprite.h>
#include <scene.h>
#include <aabb.h>

typedef struct Shrimp {
    Scene* scene;
    Sprite* sprite;
    AABB* hitbox;

    bool is_moving[2];
    float speed_multiplier;
    float speed;

    bool can_jump;
} Shrimp;

Shrimp* shrimp_new(Scene* scene);
void shrimp_delete(Shrimp* shrimp);

#endif
