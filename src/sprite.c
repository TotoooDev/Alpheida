#include <sprite.h>
#include <stdlib.h>

void default_update_function(Sprite* sprite, float timestep) {
    // do nothing lol
}

void default_draw_function(Sprite* sprite, Window* window) {
    // draw the sprite (easy)
    window_render_full_texture(window, sprite->texture, sprite->aabb);
}

Sprite* sprite_new(int x, int y, int width, int height, Texture* texture) {
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));

    sprite->aabb = aabb_new(x, y, width, height);
    sprite->texture = texture;

    sprite->update_function = default_update_function;
    sprite->draw_function = default_draw_function;

    return sprite;
}

void sprite_delete(Sprite* sprite) {
    aabb_delete(sprite->aabb);
    free(sprite);
}

