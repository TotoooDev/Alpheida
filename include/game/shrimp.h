#ifndef SHRIMP_H
#define SHRIMP_H

#include <sprite.h>
#include <scene.h>

typedef struct Shrimp {
    Sprite* sprite;
} Shrimp;

Shrimp* shrimp_new(Scene* scene);
void shrimp_delete(Shrimp* shrimp);

#endif
