#ifndef WINDOW_H
#define WINDOW_H

#include <texture.h>
#include <color.h>
#include <aabb.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Window Window;
typedef void(*EventFunction)(void* user_pointer, SDL_Event event);

Window* window_new(const char* title, int width, int height);
void window_delete(Window* window);

void window_clear(Window* window);
void window_present(Window* window);

void window_add_event_function(void* user_pointer, EventFunction event_function);
void window_poll_events(Window* window);

void window_render_texture(Window* window, Texture* texture, AABB* src, AABB* dest);
void window_render_full_texture(Window* window, Texture* texture, AABB* dest);
void window_render_color(Window* window, Color color, AABB* dest);

SDL_Window* window_get_native_window(Window* window);
SDL_Renderer* window_get_renderer(Window* window);
bool window_is_open(Window* window);

#endif

