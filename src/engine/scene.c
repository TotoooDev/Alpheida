#include <engine/scene.h>
#include <engine/array.h>
#include <engine/physics.h>
#include <engine/graphics/background.h>
#include <engine/log.h>
#include <stdlib.h>

#define NUM_SPRITES_MAX 128

typedef struct Scene {
    Array* sprites;
    Background* background;
    PhysicsWorld* physics_world;
    Camera cam;
} Scene;

Scene* scene_new() {
    Scene* scene = (Scene*)malloc(sizeof(Scene));

    scene->sprites = array_new(NUM_SPRITES_MAX);
    scene->physics_world = NULL;
    scene->cam = (Camera){ { 0.0f, 0.0f }, 0.0f };

    return scene;
}

Scene* scene_new_physics(PhysicsWorld* world) {
    Scene* scene = scene_new();
    scene->physics_world = world;
    return scene;
}

void scene_delete(Scene* scene) {
    if (scene->background != NULL)
        background_delete(scene->background);
    array_delete(scene->sprites);
    free(scene);
}

void scene_add_sprite(Scene* scene, Sprite* sprite) {
    array_add(scene->sprites, sprite);
}

void scene_remove_sprite(Scene* scene, Sprite* sprite) {
    array_remove(scene->sprites, sprite);
}

Background* scene_get_background(Scene* scene) {
    return scene->background;
}

void scene_set_background(Scene* scene, Background* bg) {
    scene->background = bg;
}

void scene_set_physics_world(Scene* scene, PhysicsWorld* world) {
    scene->physics_world = world;
}

PhysicsWorld* scene_get_physics_world(Scene* scene) {
    return scene->physics_world;
}

Camera* scene_get_camera(Scene* scene) {
    return &scene->cam;
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

void scene_render_background(Scene* scene, Renderer* renderer) {
    if (scene->background != NULL)
        renderer_render_background(renderer, scene->background);
}

void scene_render_sprites(Scene* scene, Renderer* renderer) {
    renderer_set_camera(renderer, scene->cam);

    for (u32 i = 0; i < array_get_num_elements(scene->sprites); i++) {
        Sprite* sprite = array_get(scene->sprites, i);
        if (sprite->draw_function != NULL)
            sprite->draw_function(sprite, renderer);
    }
}
