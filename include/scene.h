#ifndef SCENE_H
#define SCENE_H

#include <sprite.h>

typedef struct Scene Scene;

Scene* scene_new();
void scene_delete(Scene* scene);

void scene_add_sprite(Scene* scene, Sprite* sprite);
void scene_remove_sprite(Scene* scene, Sprite* sprite);

void scene_update(Scene* scene, float timestep);
void scene_render_sprites(Scene* scene, Window* window);

#endif

