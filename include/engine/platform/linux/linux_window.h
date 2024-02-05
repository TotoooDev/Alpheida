#ifndef LINUX_WINDOW_H
#define LINUX_WINDOW_H

#include <engine/graphics/window.h>
#include <SDL2/SDL.h>

/**
 * Returns the SDL handle of a window.
 * @param window The window to get the SDL handle from.
 * @return The `SDL_Window*` window associated with `window`.
*/
SDL_Window* linuxwindow_get_native_window(Window* window);

#endif
