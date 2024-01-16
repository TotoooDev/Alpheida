#ifndef MATH_MAT4_H
#define MATH_MAT4_H

#include <engine/math/vec4.h>
#include <engine/math/vec2.h>
#include <engine/types.h>

typedef struct Mat4 {
    f32 values[16];
} Mat4;

void mat4_identity(Mat4* mat);
void mat4_diagonal(Mat4* mat, f32 x);
void mat4_copy(Mat4* src, Mat4* dest);

void mat4_add(Mat4* result, Mat4* a, Mat4* b);
void mat4_sub(Mat4* result, Mat4* a, Mat4* b);
void mat4_mul(Mat4* result, Mat4* a, Mat4* b);
void mat4_mul_scalar(Mat4* result, Mat4* a, f32 value);
Vec4 mat4_mul_vec4(Mat4* mat, Vec4 vec);

void mat4_translate(Mat4* result, Mat4* mat, Vec2 translation);
void mat4_scale(Mat4* result, Mat4* mat, Vec2 scale);
void mat4_rotate(Mat4* result, Mat4* mat, Vec2 axis, f32 angle);

#endif
