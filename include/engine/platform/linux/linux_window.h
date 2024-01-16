#ifndef LINUX_WINDOW_H
#define LINUX_WINDOW_H

#include <engine/window.h>
#include <SDL2/SDL.h>

SDL_Window* linuxwindow_get_native_window(Window* window);
SDL_Renderer* linuxwindow_get_renderer(Window* window);

#endif
