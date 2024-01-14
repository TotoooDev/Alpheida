#include <color.h>

Color color_new(unsigned char r, unsigned char g, unsigned char b, unsigned char a) {
    return (Color){ r, g, b, a };
}

Color color_newf(f32 r, f32 g, f32 b, f32 a) {
    return (Color){
        (unsigned char)(r * 255.0f),
        (unsigned char)(g * 255.0f),
        (unsigned char)(b * 255.0f),
        (unsigned char)(a * 255.0f)
    };
}

Color color_black() {
    return (Color){ 0, 0, 0, 255 };
}

Color color_white() {
    return (Color){ 255, 255, 255, 255 };
}

Color color_red() {
    return (Color){ 255, 0, 0, 255 };
}

Color color_green() {
    return (Color){ 0, 255, 0, 255 };
}

Color color_blue() {
    return (Color){ 0, 0, 255, 0 };
}

Color color_yellow() {
    return (Color){ 255, 255, 0, 255 };
}

Color color_magenta() {
    return (Color){ 255, 0, 255, 255 };
}

Color color_cyan() {
    return (Color){ 0, 255, 255, 255 };
}

