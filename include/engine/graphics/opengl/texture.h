#ifndef OPENGL_TEXTURE_H
#define OPENGL_TEXTURE_H

#include <engine/graphics/texture.h>
#include <engine/types.h>

/**
 * Binds a texture for later use.
 * @param texture The texture to bind.
 * @note The texture slot defaults to 0 with this function. To specify a custom texture slot, use `texture_bind_active`.
*/
void texture_bind(Texture* texture);

/**
 * Binds a texture for later use.
 * @param texture The texture to bind.
 * @param active_texture The texture slot to use.
*/
void texture_bind_active(Texture* texture, u32 active_texture);

/**
 * Returns the OpenGL ID of the texture.
 * @param texture The texture to get the ID from.
 * @return The ID of `texture`.
*/
u32 texture_get_id(Texture* texture);

#endif
