#include <scene.h>
#include <array.h>
#include <physics.h>
#include <log.h>
#include <stdlib.h>

#define NUM_SPRITES_MAX 128

typedef struct Scene {
    Array* sprites;
    PhysicsWorld* physics_world;
} Scene;

Scene* scene_new() {
    Scene* scene = (Scene*)malloc(sizeof(Scene));

    scene->sprites = array_new(NUM_SPRITES_MAX);
    scene->physics_world = NULL;

    return scene;
}

Scene* scene_new_physics(PhysicsWorld* world) {
    Scene* scene = scene_new();
    scene->physics_world = world;
    return scene;
}

void scene_delete(Scene* scene) {
    array_delete(scene->sprites);
    free(scene);
}

void scene_add_sprite(Scene* scene, Sprite* sprite) {
    array_add(scene->sprites, sprite);
}

void scene_remove_sprite(Scene* scene, Sprite* sprite) {
    array_remove(scene->sprites, sprite);
}

void scene_set_physics_world(Scene* scene, PhysicsWorld* world) {
    scene->physics_world = world;
}

PhysicsWorld* scene_get_physics_world(Scene* scene) {
    return scene->physics_world;
}

void scene_update(Scene* scene, f32 timestep) {
    for (u32 i = 0; i < array_get_num_elements(scene->sprites); i++) {
        Sprite* sprite = array_get(scene->sprites, i);
        if (sprite->update_function != NULL)
            sprite->update_function(sprite, timestep);
    }

    // bad timetstep handling i know
#ifdef SHRIMP_LINUX
    physics_update(scene->physics_world, timestep);
#else
    physics_update(scene->physics_world, 1.0f);
#endif
}

void scene_render_sprites(Scene* scene, Window* window) {
    for (u32 i = 0; i < array_get_num_elements(scene->sprites); i++) {
        Sprite* sprite = array_get(scene->sprites, i);
        if (sprite->draw_function != NULL)
            sprite->draw_function(sprite, window);
    }
}

