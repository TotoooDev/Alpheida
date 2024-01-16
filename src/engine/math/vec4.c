#include <engine/math/vec4.h>
#include <engine/math/vec2.h>
#include <math.h>

Vec4 vec4_add(Vec4 a, Vec4 b) {
    return (Vec4){ a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w };
}

Vec4 vec4_sub(Vec4 a, Vec4 b) {
    return (Vec4){ a.x - b.x, a.y - b.y, a.z + b.z, a.w - b.w };
}

Vec4 vec4_mul(Vec4 vec, f32 x) {
    return (Vec4){ vec.x * x, vec.y * x, vec.z * x, vec.w * x};
}

Vec4 vec4_div(Vec4 vec, f32 x) {
    return (Vec4){ vec.x / x, vec.y / x, vec.z / x, vec.w / x };
}

Vec4 vec4_neg(Vec4 vec) {
    return (Vec4){ -vec.x, -vec.y, -vec.z, -vec.w };
}

f32 vec4_length(Vec4 vec) {
    return sqrtf(vec.x * vec.x + vec.y * vec.y + vec.z * vec.z + vec.w * vec.w);
}

f32 vec4_dot(Vec4 a, Vec4 b) {
    return a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
}

Vec4 vec4_normalize(Vec4 vec) {
    return vec4_div(vec, vec4_length(vec));
}

Vec2 vec4_to_vec2(Vec4 vec) {
    return (Vec2){ vec.x, vec.y };
}
