#ifndef SPRITE_H
#define SPRITE_H

#include <engine/graphics/texture.h>
#include <engine/graphics/color.h>
#include <engine/graphics/renderer.h>
#include <engine/physics.h>
#include <engine/types.h>
#include <engine/cglm/cglm.h>

typedef struct Sprite Sprite;

typedef void(*UpdateFunction)(Sprite*, f32);
typedef void(*DrawFunction)(Sprite*, Renderer*);

typedef struct Sprite {
    vec2 pos;
    vec2 scale;
    f32 angle;

    Texture* texture;
    Color color;
    bool use_color;

    PhysicsObject* physics_object;

    UpdateFunction update_function;
    DrawFunction draw_function;
    void* user_pointer;
} Sprite;

Sprite* sprite_new(vec2 pos, vec2 scale, Texture* texture);
Sprite* sprite_new_color(vec2 pos, vec2 scale, Color color);
void sprite_delete(Sprite* sprite);

#endif
