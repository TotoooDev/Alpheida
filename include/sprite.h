#ifndef SPRITE_H
#define SPRITE_H

#include <texture.h>
#include <window.h>

typedef struct Sprite Sprite;

typedef void(*UpdateFunction)(Sprite*, float);
typedef void(*DrawFunction)(Sprite*, Window*);

typedef struct Sprite {
    int x, y;
    int width, height;
    Texture* texture;

    UpdateFunction update_function;
    DrawFunction draw_function;
    void* user_pointer;
} Sprite;

Sprite* sprite_new(int x, int y, int width, int height, Texture* texture);
void sprite_delete(Sprite* sprite);

#endif

