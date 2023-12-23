#ifndef SPRITE_H
#define SPRITE_H

#include <texture.h>

typedef struct Sprite {
    int x, y;
    Texture* texture;
} Sprite;

Sprite* sprite_new(int x, int y, Texture* texture);
void sprite_delete(Sprite* sprite);

Texture* sprite_get_texture(Sprite* sprite);

#endif

