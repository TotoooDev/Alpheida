#ifndef LINUX_TEXTURE_H
#define LINUX_TEXTURE_H

#include <texture.h>
#include <SDL2/SDL.h>

SDL_Texture* linuxtexture_get_native_texture(Texture* texture);

#endif
