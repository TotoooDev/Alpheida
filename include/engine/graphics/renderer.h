#ifndef RENDERER_H
#define RENDERER_H

#include <engine/graphics/camera.h>
#include <engine/graphics/color.h>
#include <engine/graphics/texture.h>
#include <engine/graphics/text.h>
#include <engine/graphics/background.h>
#include <engine/cglm/cglm.h>

/**
 * The renderer API.
*/
typedef struct Renderer Renderer;

Renderer* renderer_new();
void renderer_delete(Renderer* renderer);

void renderer_clear(Renderer* renderer, Color color);
void renderer_set_camera(Renderer* renderer, Camera cam);
void renderer_render_texture(Renderer* renderer, Texture* texture, vec2 pos, vec2 scale, f32 angle);
void renderer_render_color(Renderer* renderer, Color color, vec2 pos, vec2 scale, f32 angle);
void renderer_render_text(Renderer* renderer, Font* font, const char* text, Color color, vec2 pos, f32 scale);
void renderer_render_background(Renderer* renderer, Background* bg);

#endif
