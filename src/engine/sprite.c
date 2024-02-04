#include <engine/sprite.h>
#include <stdlib.h>

void sprite_default_draw_function(Sprite* sprite, Renderer* renderer) {
    // draw the sprite (easy)
    if (sprite->use_color || sprite->texture == NULL)
        renderer_render_color(renderer, sprite->color, sprite->pos, sprite->scale, sprite->angle);
    else
        renderer_render_texture(renderer, sprite->texture, sprite->pos, sprite->scale, sprite->angle);
}

Sprite* sprite_new(vec2 pos, vec2 scale, Texture* texture) {
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));

    glm_vec2_copy(pos, sprite->pos);
    glm_vec2_copy(scale, sprite->scale);
    sprite->angle = 0.0f;

    sprite->texture = texture;
    sprite->keep_texture_on_delete = false;
    sprite->color = color_magenta();
    sprite->use_color = false;

    sprite->update_function = NULL;
    sprite->draw_function = sprite_default_draw_function;
    sprite->user_pointer = NULL;

    return sprite;
}

Sprite* sprite_new_color(vec2 pos, vec2 scale, Color color) {
    Sprite* sprite = sprite_new(pos, scale, NULL);
    sprite->color = color;
    sprite->use_color = true;
    return sprite;
}

void sprite_delete(Sprite* sprite) {
    if (sprite->texture != NULL && !sprite->keep_texture_on_delete)
        texture_delete(sprite->texture);
    free(sprite);
}
