#ifndef LIFE_H
#define LIFE_H

#include <game/shrimp.h>
#include <engine/scene.h>
#include <engine/sprite.h>
#include <engine/graphics/text.h>

typedef struct Life {
    Sprite* sprite;
    Texture* heart_texture;
    Shrimp* shrimp;

    Font* font;
    Scene* scene;
} Life;

Life* life_new(Shrimp* shrimp, Scene* scene);
void life_delete(Life* life);

#endif
