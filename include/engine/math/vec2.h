#ifndef MATH_VEC2_H
#define MATH_VEC2_H

#include <engine/types.h>

typedef struct Vec2 {
    f32 x, y;
} Vec2;

Vec2 vec2_add(Vec2 a, Vec2 b);
Vec2 vec2_sub(Vec2 a, Vec2 b);
Vec2 vec2_mul(Vec2 vec, f32 x);
Vec2 vec2_div(Vec2 vec, f32 x);

f32 vec_length(Vec2 vec);
f32 vec2_dot(Vec2 a, Vec2 b);
Vec2 vec2_normalize(Vec2 vec);

#endif
