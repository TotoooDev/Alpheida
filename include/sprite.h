#ifndef SPRITE_H
#define SPRITE_H

#include <texture.h>
#include <color.h>
#include <physics.h>
#include <window.h>

typedef struct Sprite Sprite;

typedef void(*UpdateFunction)(Sprite*, float);
typedef void(*DrawFunction)(Sprite*, Window*);

typedef struct Sprite {
    AABB* aabb;
    Texture* texture;
    Color color;
    bool use_color;

    PhysicsObject* physics_object;

    UpdateFunction update_function;
    DrawFunction draw_function;
    void* user_pointer;
} Sprite;

Sprite* sprite_new(float x, float y, float width, float height, Texture* texture);
Sprite* sprite_new_color(float x, float y, float width, float height, Color color);
void sprite_delete(Sprite* sprite);

#endif

