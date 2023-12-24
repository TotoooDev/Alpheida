#ifndef AABB_H
#define AABB_H

#include <stdbool.h>

typedef struct AABB {
    int x, y;
    int width, height;
} AABB;

AABB* aabb_new(int x, int y, int width, int height);
void aabb_delete(AABB* aabb);

bool aabb_intersect(AABB* a, AABB* b);

#endif

