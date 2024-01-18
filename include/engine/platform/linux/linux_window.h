#ifndef LINUX_WINDOW_H
#define LINUX_WINDOW_H

#include <engine/graphics/window.h>
#include <SDL2/SDL.h>

SDL_Window* linuxwindow_get_native_window(Window* window);

#endif
