#include <sprite.h>
#include <stdlib.h>

void default_update_function(Sprite* sprite, float timestep) {
    // do nothing lol
}

void default_draw_function(Sprite* sprite, Window* window) {
    // draw the sprite (easy)
    SDL_Rect dest_rect = { sprite->x, sprite->y, sprite->width, sprite->height };
    window_render_full_texture(window, sprite->texture, dest_rect);
}

Sprite* sprite_new(int x, int y, int width, int height, Texture* texture) {
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));

    sprite->x = x;
    sprite->y = y;
    sprite->width = width;
    sprite->height = height;
    sprite->texture = texture;

    sprite->update_function = default_update_function;
    sprite->draw_function = default_draw_function;

    return sprite;
}

void sprite_delete(Sprite* sprite) {
    free(sprite);
}

