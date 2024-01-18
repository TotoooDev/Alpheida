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
 * Present what has been drawn to the window.
 * @param window The window to present to.
 * @note Drawing stuff without calling this function will display nothing.
*/
void window_present(Window* window);

#endif
