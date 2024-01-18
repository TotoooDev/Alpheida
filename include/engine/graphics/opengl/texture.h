#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

#include <engine/graphics/texture.h>
#include <engine/types.h>

void texture_bind(Texture* texture);
void texture_bind_active(Texture* texture, u32 active_texture);
u32 texture_get_id(Texture* texture);

#endif
