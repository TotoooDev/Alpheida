#ifndef WINDOW_H
#define WINDOW_H

#include <SDL2/SDL.h>
#include <stdbool.h>

typedef struct Window Window;
typedef void(*EventFunction)(void* user_pointer, SDL_Event event);

Window* window_new(const char* title, int width, int height);
void window_delete(Window* window);

void window_add_event_function(void* user_pointer, EventFunction event_function);
void window_poll_events(Window* window);

bool window_is_open(Window* window);

#endif

