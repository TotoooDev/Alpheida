#ifndef WINDOW_H
#define WINDOW_H

#include <engine/graphics/texture.h>
#include <engine/graphics/color.h>
#include <engine/aabb.h>
#include <engine/types.h>
#include <stdbool.h>

/**
 * A wrapper around a window (or rather a screen for platforms that don't offer a windowing system, which is about every console ever).
*/
typedef struct Window Window;

/**
 * Create a new window.
 * @param title The title of the window.
 * @param width The width of the window.
 * @param height The height of the window.
 * @note The parameters are currently only used on platforms that offer a windowing system. This function will likely be changed in the future to take no parameters.
*/
Window* window_new(const char* title, i32 width, i32 height);

/**
 * Deletes a window.
 * @param window The window to delete.
*/
void window_delete(Window* window);

/**
 * Clears the window with a light grey color.
 * @param window The window to clear.
*/
void window_clear(Window* window);

/**
 * Present what has been drawn to the window.
 * @param window The window to present to.
 * @note Drawing stuff without calling this function will display nothing.
*/
void window_present(Window* window);

/**
 * Draws a textured AABB to the window.
 * @param window The window to draw to.
 * @param texture The texture to use.
 * @param src The rectangle shape to draw from the texture. To draw the full texture, use `window_render_full_texture`.
 * @param dest The AABB to draw to.
*/
void window_render_texture(Window* window, Texture* texture, AABB* src, AABB* dest);

/**
 * Draws a textured AABB to the window.
 * @param window The window to draw to.
 * @param texture The texture to use.
 * @param dest The AABB to draw to.
*/
void window_render_full_texture(Window* window, Texture* texture, AABB* dest);

/**
 * Draws a colored AABB to the window.
 * @param window The window to draw to.
 * @param color The color to use.
 * @param dest The AABB to draw to.
 * @note CURRENTLY BROKEN ON WII, THE QUAD IS NOT DRAWN AT ALL
*/
void window_render_color(Window* window, Color color, AABB* dest);

#endif
