#ifndef COLOR_H
#define COLOR_H

#include <engine/types.h>

/**
 * A simple structure to represent an RGBA8 color (values ranging 0.0-1.0)
*/
typedef struct Color {
    f32 r; /** The red component of the color. */
    f32 g; /** The green component of the color. */
    f32 b; /** The blue component of the color. */
    f32 a; /** The alpha (transparency) component of the color. */
} Color;

/**
 * Creates a new color, but uses normalized f32 values (ranging 0.0-1.0).
 * @param r The red component of the color.
 * @param g The green component of the color.
 * @param b The blue component of the color.
 * @param a The alpha component of the color.
 * @returns The new color.
*/
Color color_new(f32 r, f32 g, f32 b, f32 a);

/**
 * @returns A black color
*/
Color color_black();

/**
 * @returns A white color
*/
Color color_white();

/**
 * @returns A red color
*/
Color color_red();

/**
 * @returns A green color
*/
Color color_green();

/**
 * @returns A blue color
*/
Color color_blue();

/**
 * @returns A yellow color
*/
Color color_yellow();

/**
 * @returns A magenta color
*/
Color color_magenta();

/**
 * @returns A cyan color
*/
Color color_cyan();

#endif

