#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <engine/graphics/texture.h>
#include <engine/types.h>

typedef struct Background Background;

Background* background_new(Texture* texture, f32 offset_x, f32 offset_y);
void background_delete(Background* bg);

Texture* background_get_texture(Background* bg);
f32 background_get_offset_x(Background* bg);
f32 background_get_offset_y(Background* bg);

Texture* background_set_texture(Background* bg, Texture* texture);
void background_set_offset(Background* bg, f32 offset_x, f32 offset_y);

#endif
