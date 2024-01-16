#include <engine/math/vec2.h>
#include <math.h>

Vec2 vec2_add(Vec2 a, Vec2 b) {
    return (Vec2){ a.x + b.x, a.y + b.y };
}

Vec2 vec2_sub(Vec2 a, Vec2 b) {
    return (Vec2){ a.x - b.x, a.y - b.y };
}

Vec2 vec2_mul(Vec2 vec, f32 x) {
    return (Vec2){ vec.x * x, vec.y * x };
}

Vec2 vec2_div(Vec2 vec, f32 x) {
    return (Vec2){ vec.x / x, vec.y / x };
}

f32 vec_length(Vec2 vec) {
    return sqrtf(vec.x * vec.x + vec.y * vec.y);
}

f32 vec2_dot(Vec2 a, Vec2 b) {
    return a.x * b.x + a.y * b.y;
}

Vec2 vec2_normalize(Vec2 vec) {
    return vec2_div(vec, vec_length(vec));
}
