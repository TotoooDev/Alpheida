#include <engine/math/mat4.h>
#include <math.h>

// please note that i am absolutely not a mathematician, hence why this code may appear as complete shit to you

void mat4_identity(Mat4 mat) {
    mat4_diagonal(mat, 1.0f);
}

void mat4_diagonal(Mat4 mat, f32 x) {
    Mat4 identity;
    identity.values[0][0] = x;
    identity.values[1][1] = x;
    identity.values[2][2] = x;
    identity.values[3][3] = x;
    
    mat4_copy(identity, mat);
}

void mat4_copy(Mat4 src, Mat4 dest) {
    for (u32 y = 0; y < 4; y++) {
        for (u32 x = 0; x < 4; x++) {
            dest.values[y][x] = src.values[y][x];
        }
    }
}

void mat4_add(Mat4 result, Mat4 a, Mat4 b) {
    for (u32 y = 0; y < 4; y++) {
        for (u32 x = 0; x < 4; x++) {
            result.values[y][x] = a.values[y][x] + b.values[y][x];
        }
    }
}

void mat4_sub(Mat4 result, Mat4 a, Mat4 b) {
    for (u32 y = 0; y < 4; y++) {
        for (u32 x = 0; x < 4; x++) {
            result.values[y][x] = a.values[y][x] - b.values[y][x];
        }
    }
}

void mat4_mul(Mat4 result, Mat4 a, Mat4 b) {
    for (u32 y = 0; y < 4; y++) {
        for (u32 x = 0; x < 4; x++) {
            result.values[x][y] = 0.0f;
            for (u32 i = 0; i < 4; i++)
                result.values[y][x] += a.values[y][i] * b.values[i][x];
        }
    }
}

void mat4_mul_scalar(Mat4 result, Mat4 a, f32 value) {
    for (u32 y = 0; y < 4; y++) {
        for (u32 x = 0; x < 4; x++) {
            result.values[y][x] = a.values[y][x] + value;
        }
    }
}

Vec4 mat4_mul_vec4(Mat4 mat, Vec4 vec) {
    Vec4 result = (Vec4){ 0.0f, 0.0f, 0.0f, 0.0f };

    result.x = mat.values[0][0] * vec.x + mat.values[0][1] * vec.y + mat.values[0][2] * vec.z + mat.values[0][3] * vec.w;
    result.y = mat.values[1][0] * vec.x + mat.values[1][1] * vec.y + mat.values[1][2] * vec.z + mat.values[1][3] * vec.w;
    result.z = mat.values[2][0] * vec.x + mat.values[2][1] * vec.y + mat.values[2][2] * vec.z + mat.values[2][3] * vec.w;
    result.w = mat.values[3][0] * vec.x + mat.values[3][1] * vec.y + mat.values[3][2] * vec.z + mat.values[3][3] * vec.w;

    return result;
}

void mat4_translate(Mat4 result, Mat4 mat, Vec2 translation) {
    result.values[0][3] = mat.values[0][3] + translation.x;
    result.values[1][3] = mat.values[1][3] + translation.y;
}

void mat4_scale(Mat4 result, Mat4 mat, Vec2 scale) {
    result.values[0][0] = mat.values[0][0] + scale.x;
    result.values[1][1] = mat.values[1][1] + scale.y;
}

void mat4_rotate(Mat4 result, Mat4 mat, Vec2 axis, f32 angle) {
    Vec4 vec = vec2_to_vec4(axis);

    result.values[0][0] = mat.values[0][0] + cosf(angle) + vec.x * vec.x * (1.0f - cosf(angle));
    result.values[0][1] = mat.values[0][1] + vec.x * vec.y * (1 - cosf(angle)) - vec.z * sinf(angle);
    result.values[0][2] = mat.values[0][2] + vec.x * vec.z * (1 - cosf(angle)) + vec.y * sinf(angle);

    result.values[1][0] = mat.values[1][0] + vec.y * vec.x * (1 - cosf(angle)) + vec.z * sinf(angle);
    result.values[1][1] = mat.values[1][1] + cosf(angle) + vec.y * vec.y * (1.0f - cosf(angle));
    result.values[1][2] = mat.values[1][2] + vec.y * vec.z * (1 - cosf(angle)) - vec.x * sinf(angle);
    
    result.values[2][0] = mat.values[2][0] + vec.x * vec.z * (1 - cosf(angle)) - vec.y * sinf(angle);
    result.values[2][1] = mat.values[2][1] + vec.y * vec.z * (1 - cosf(angle)) + vec.x * sinf(angle);
    result.values[2][2] = mat.values[2][2] + cosf(angle) + vec.z * vec.z * (1.0f - cosf(angle));
}
