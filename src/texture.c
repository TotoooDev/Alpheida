#include <texture.h>
#include <app.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct Texture {
    SDL_Texture* texture;
} Texture;

Texture* texture_new(const char* filename) {
    Texture* texture = malloc(sizeof(Texture));

    SDL_Surface* surface = IMG_Load(filename);
    Window* window = app_get_window(app_get());
    texture->texture = SDL_CreateTextureFromSurface(window_get_renderer(window), surface);
    SDL_FreeSurface(surface);

    return texture;
}

void texture_delete(Texture* texture) {
    SDL_DestroyTexture(texture->texture);
    free(texture);
}

SDL_Texture* texture_get_native_texture(Texture* texture) {
    return texture->texture;
}
