#ifndef AABB_H
#define AABB_H

#include <stdbool.h>

/**
 * An Axis-Aligned Bounding Box (AABB) structure.
*/
typedef struct AABB {
    float x, y; /** The coordinates of the top-left corner of the AABB. */
    float width, height; /** The dimensions of the AABB. */
} AABB;

/**
 * An enumeration to represent in what axis two AABBs intersect.
 * @note Their names are relative to the first parameter of `aabb_get_intersection_axis`.
*/
typedef enum IntersectionAxis {
    INTERSECTION_AXIS_NONE,
    INTERSECTION_AXIS_POSITIVE_X,
    INTERSECTION_AXIS_NEGATIVE_X,
    INTERSECTION_AXIS_POSITIVE_Y,
    INTERSECTION_AXIS_NEGATIVE_Y
} IntersectionAxis;

/**
 * Creates a new AABB.
 * @param x The x component of the AABB's coordinates.
 * @param y The y component of the AABB's coordinates.
 * @param width The width of the AABB.
 * @param height The height of the AABB.
*/
AABB* aabb_new(float x, float y, float width, float height);

/**
 * Deletes an AABB.
*/
void aabb_delete(AABB* aabb);

/**
 * Tests if two AABBs intersect.
 * @param a The first AABB.
 * @param a The second AABB.
 * @returns `true` if the AABBs intersect, `false` otherwise.
*/
bool aabb_intersect(AABB* a, AABB* b);

/**
 * Returns the intersection axis of two AABBs.
 * @param a The first AABB.
 * @param a The second AABB.
 * @returns The intersection axis of `a` and `b`.
*/
IntersectionAxis aabb_get_intersection_axis(AABB* a, AABB* b);

#endif

