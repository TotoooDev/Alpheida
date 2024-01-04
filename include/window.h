#ifndef WINDOW_H
#define WINDOW_H

#include <texture.h>
#include <color.h>
#include <aabb.h>
#include <stdbool.h>

typedef struct Window Window;

Window* window_new(const char* title, int width, int height);
void window_delete(Window* window);

void window_clear(Window* window);
void window_present(Window* window);

void window_render_texture(Window* window, Texture* texture, AABB* src, AABB* dest);
void window_render_full_texture(Window* window, Texture* texture, AABB* dest);
void window_render_color(Window* window, Color color, AABB* dest);

bool window_is_open(Window* window);

#endif
