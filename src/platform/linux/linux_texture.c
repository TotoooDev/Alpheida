#include <config.h>

#ifdef SHRIMP_LINUX

#include <texture.h>
#include <platform/linux/linux_texture.h>
#include <app.h>
#include <platform/linux/linux_window.h>
#include <log.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Texture {
    SDL_Texture* texture;
} Texture;

Texture* texture_new(const char* filename) {
    Texture* texture = malloc(sizeof(Texture));

    SDL_Surface* surface = IMG_Load(filename);
    log_assert(surface != NULL, "failed to load image %s! img error: %s\n", filename, IMG_GetError());
    Window* window = app_get_window();
    texture->texture = SDL_CreateTextureFromSurface(linuxwindow_get_renderer(window), surface);
    log_assert(texture->texture != NULL, "failed to create texture for image %s! sdl error: %s\n", filename, SDL_GetError());
    SDL_FreeSurface(surface);

    return texture;
}

void texture_delete(Texture* texture) {
    SDL_DestroyTexture(texture->texture);
    free(texture);
}

SDL_Texture* linuxtexture_get_native_texture(Texture* texture) {
    return texture->texture;
}

#endif
