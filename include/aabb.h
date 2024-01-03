#ifndef AABB_H
#define AABB_H

#include <stdbool.h>

typedef struct AABB {
    float x, y;
    float width, height;
} AABB;

typedef enum IntersectionAxis {
    NONE,
    POSITIVE_X,
    NEGATIVE_X,
    POSITIVE_Y,
    NEGATIVE_Y
} IntersectionAxis;

AABB* aabb_new(float x, float y, float width, float height);
void aabb_delete(AABB* aabb);

bool aabb_intersect(AABB* a, AABB* b);
IntersectionAxis aabb_get_intersection_axis(AABB* a, AABB* b);

#endif

