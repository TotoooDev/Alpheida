#ifndef COLOR_H
#define COLOR_H

typedef struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;

Color color_new(unsigned char r, unsigned char g, unsigned char b, unsigned char a);
Color color_newf(float r, float g, float b, float a);

Color color_black();
Color color_white();
Color color_red();
Color color_green();
Color color_blue();
Color color_yellow();
Color color_magenta();
Color color_cyan();

#endif

