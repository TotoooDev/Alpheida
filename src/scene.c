#include <scene.h>
#include <array.h>
#include <log.h>

#define NUM_SPRITES_MAX 128

typedef struct Scene {
    Array* sprites;
} Scene;

Scene* scene_new() {
    Scene* scene = (Scene*)malloc(sizeof(Scene));

    scene->sprites = array_new(NUM_SPRITES_MAX);

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

void scene_update(Scene* scene, float timestep) {
    for (unsigned int i = 0; i < array_get_num_elements(scene->sprites); i++) {
        Sprite* sprite = array_get(scene->sprites, i);
        sprite->update_function(sprite, timestep);
    }
}

void scene_render_sprites(Scene* scene, Window* window) {
    for (unsigned int i = 0; i < array_get_num_elements(scene->sprites); i++) {
        Sprite* sprite = array_get(scene->sprites, i);
        sprite->draw_function(sprite, window);
    }
}

