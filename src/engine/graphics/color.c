#include <engine/graphics/color.h>

Color color_new(f32 r, f32 g, f32 b, f32 a) {
    return (Color){
        (unsigned char)(r),
        (unsigned char)(g),
        (unsigned char)(b),
        (unsigned char)(a)
    };
}

Color color_black() {
    return (Color){ 0.0f, 0.0f, 0.0f, 1.0f };
}

Color color_white() {
    return (Color){ 1.0f, 1.0f, 1.0f, 1.0f };
}

Color color_red() {
    return (Color){ 1.0f, 0.0f, 0.0f, 1.0f };
}

Color color_green() {
    return (Color){ 0.0f, 1.0f, 0.0f, 1.0f };
}

Color color_blue() {
    return (Color){ 0.0f, 0.0f, 1.0f, 1.0f };
}

Color color_yellow() {
    return (Color){ 1.0f, 1.0f, 0.0f, 1.0f };
}

Color color_magenta() {
    return (Color){ 1.0f, 0.0f, 1.0f, 1.0f };
}

Color color_cyan() {
    return (Color){ 0.0f, 1.0f, 1.0f, 1.0f };
}
