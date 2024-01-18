#ifndef RENDERER_H
#define RENDERER_H

#include <engine/graphics/camera.h>
#include <engine/graphics/color.h>
#include <engine/graphics/texture.h>
#include <engine/aabb.h>

typedef struct Renderer Renderer;

Renderer* renderer_new();
void renderer_delete(Renderer* renderer);

void renderer_clear(Renderer* renderer, Color color);
void renderer_set_camera(Renderer* renderer, Camera cam);
void renderer_render_texture(Renderer* renderer, Texture* texture, AABB* dest);
void renderer_render_color(Renderer* renderer, Color color, AABB* dest);

#endif
