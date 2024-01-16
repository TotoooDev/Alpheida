#ifndef MATH_VEC4_H
#define MATH_VEC4_H

#include <engine/types.h>

typedef struct Vec4 {
    f32 x, y, z, w;
} Vec4;

typedef struct Vec2 Vec2;

Vec4 vec4_add(Vec4 a, Vec4 b);
Vec4 vec4_sub(Vec4 a, Vec4 b);
Vec4 vec4_mul(Vec4 vec, f32 x);
Vec4 vec4_div(Vec4 vec, f32 x);
Vec4 vec4_neg(Vec4 vec);

f32 vec4_length(Vec4 vec);
f32 vec4_dot(Vec4 a, Vec4 b);
Vec4 vec4_normalize(Vec4 vec);

Vec2 vec4_to_vec2(Vec4 vec);

#endif
