#ifndef SHRIMP_H
#define SHRIMP_H

#include <sprite.h>
#include <scene.h>

typedef struct Shrimp {
    Sprite* sprite;

    bool is_moving[2];
    float speed_multiplier;
    float speed;

    bool can_jump;
} Shrimp;

Shrimp* shrimp_new(Scene* scene);
void shrimp_delete(Shrimp* shrimp);

#endif
