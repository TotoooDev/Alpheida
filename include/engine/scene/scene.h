#ifndef SCENE_H
#define SCENE_H

#include <engine/scene/sprite.h>
#include <engine/physics/physics.h>
#include <engine/graphics/camera.h>
#include <engine/types.h>

typedef struct Scene Scene;

Scene* scene_new();
Scene* scene_new_physics(PhysicsWorld* world);
void scene_delete(Scene* scene);

void scene_add_sprite(Scene* scene, Sprite* sprite);
void scene_remove_sprite(Scene* scene, Sprite* sprite);

Background* scene_get_background(Scene* scene);
void scene_set_background(Scene* scene, Background* bg);

void scene_set_physics_world(Scene* scene, PhysicsWorld* world);
PhysicsWorld* scene_get_physics_world(Scene* scene);

Camera* scene_get_camera(Scene* scene);

void scene_update(Scene* scene, f32 timestep);
void scene_render_background(Scene* scene, Renderer* renderer);
void scene_render_sprites(Scene* scene, Renderer* renderer);

#endif
