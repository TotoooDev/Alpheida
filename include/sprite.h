#ifndef SPRITE_H
#define SPRITE_H

#include <texture.h>
#include <color.h>
#include <physics.h>
#include <window.h>
#include <types.h>

typedef struct Sprite Sprite;

typedef void(*UpdateFunction)(Sprite*, f32);
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

Sprite* sprite_new(f32 x, f32 y, f32 width, f32 height, Texture* texture);
Sprite* sprite_new_color(f32 x, f32 y, f32 width, f32 height, Color color);
void sprite_delete(Sprite* sprite);

#endif

