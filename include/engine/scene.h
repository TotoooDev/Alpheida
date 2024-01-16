#ifndef SCENE_H
#define SCENE_H

#include <engine/sprite.h>
#include <engine/physics.h>
#include <engine/types.h>

typedef struct Scene Scene;

Scene* scene_new();
Scene* scene_new_physics(PhysicsWorld* world);
void scene_delete(Scene* scene);

void scene_add_sprite(Scene* scene, Sprite* sprite);
void scene_remove_sprite(Scene* scene, Sprite* sprite);

void scene_set_physics_world(Scene* scene, PhysicsWorld* world);
PhysicsWorld* scene_get_physics_world(Scene* scene);

void scene_update(Scene* scene, f32 timestep);
void scene_render_sprites(Scene* scene, Renderer* renderer);

#endif

