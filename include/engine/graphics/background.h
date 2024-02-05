#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <engine/graphics/texture.h>
#include <engine/types.h>

/**
 * A background is just a texture that uses a special shader to make it use the whole screen space.
*/
typedef struct Background Background;

/**
 * Creates a new background.
 * @param texture The texture to use.
 * @param offset_x Unused for now
 * @param offset_y Unused for now
*/
Background* background_new(Texture* texture, f32 offset_x, f32 offset_y);

/**
 * Deletes a background.
 * @param bg The background to delete.
 * @note This also deletes the texture associated with the background.
*/
void background_delete(Background* bg);

/**
 * Returns the texture associated with the background.
 * @param bg The background to get the texture from.
 * @return The texture associated with `bg`.
*/
Texture* background_get_texture(Background* bg);
f32 background_get_offset_x(Background* bg);
f32 background_get_offset_y(Background* bg);

/**
 * Sets the texture of the background.
 * @param bg The background to modify.
 * @param texture The new texture of the background.
*/
void background_set_texture(Background* bg, Texture* texture);
void background_set_offset(Background* bg, f32 offset_x, f32 offset_y);

#endif
