#include <aabb.h>
#include <stdlib.h>

AABB* aabb_new(int x, int y, int width, int height) {
    AABB* aabb = (AABB*)malloc(sizeof(AABB));

    aabb->x = x;
    aabb->y = y;
    aabb->width = width;
    aabb->height = height;

    return aabb;
}

void aabb_delete(AABB* aabb) {
    free(aabb);
}

bool aabb_intersect(AABB* a, AABB* b) {
    return
        (a->x <= b->x + b->width  && a->x + a->width  >= b->x) &&
        (a->y <= b->y + b->height && a->y + a->height >= b->y);
}

