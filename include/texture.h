#ifndef TEXTURE_H
#define TEXTURE_H

#include <SDL2/SDL.h>

typedef struct Texture Texture;

Texture* texture_new(const char* filename);
void texture_delete(Texture* texture);

SDL_Texture* texture_get_native_texture(Texture* texture);

#endif

