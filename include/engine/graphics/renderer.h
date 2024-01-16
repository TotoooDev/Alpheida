#ifndef RENDERER_H
#define RENDERER_H

#include <engine/graphics/color.h>
#include <engine/graphics/texture.h>
#include <engine/aabb.h>

typedef struct Renderer Renderer;

Renderer* renderer_new();
void renderer_delete(Renderer* renderer);

void renderer_clear(Color color);
void renderer_render_texture(Texture* texture, AABB* src, AABB* dest);
void renderer_render_full_texture(Texture* texture, AABB* dest);
void renderer_render_color(Color color, AABB* dest);

#endif
