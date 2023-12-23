#include <sprite.h>
#include <stdlib.h>

Sprite* sprite_new(int x, int y, Texture* texture) {
    Sprite* sprite = (Sprite*)malloc(sizeof(Sprite));

    sprite->x = x;
    sprite->y = y;
    sprite->texture = texture;

    return sprite;
}
