#ifndef SPRITE_H
#define SPRITE_H

#include <engine/graphics/texture.h>
#include <engine/graphics/color.h>
#include <engine/graphics/renderer.h>
#include <engine/physics.h>
#include <engine/types.h>

typedef struct Sprite Sprite;

typedef void(*UpdateFunction)(Sprite*, f32);
typedef void(*DrawFunction)(Sprite*, Renderer*);

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

