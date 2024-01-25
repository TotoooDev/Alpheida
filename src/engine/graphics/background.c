#include <engine/graphics/background.h>
#include <stdlib.h>

typedef struct Background {
    Texture* texture;
    f32 offset_x, offset_y;
} Background;

Background* background_new(Texture* texture, f32 offset_x, f32 offset_y) {
    Background* bg = (Background*)malloc(sizeof(Background));

    bg->texture = texture;
    bg->offset_x = offset_x;
    bg->offset_y = offset_y;

    return bg;
}

void background_delete(Background* bg) {
    texture_delete(bg->texture);
    free(bg);
}

Texture* background_get_texture(Background* bg) {
    return bg->texture;
}

f32 background_get_offset_x(Background* bg) {
    return bg->offset_x;
}

f32 background_get_offset_y(Background* bg) {
    return bg->offset_y;
}

Texture* background_set_texture(Background* bg, Texture* texture) {
    texture_delete(bg->texture);
    bg->texture = texture;
}

void background_set_offset(Background* bg, f32 offset_x, f32 offset_y) {
    bg->offset_x = offset_x;
    bg->offset_y = offset_y;
}
