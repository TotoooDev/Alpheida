#include <scene.h>
#include <log.h>

#define NUM_SPRITES_MAX 1024

typedef struct Scene {
    Sprite** sprites;
    unsigned int num_sprites;
} Scene;

Scene* scene_new() {
    Scene* scene = (Scene*)malloc(sizeof(Scene));

    scene->sprites = (Sprite**)malloc(sizeof(Sprite*) * NUM_SPRITES_MAX);
    for (unsigned int i = 0; i < NUM_SPRITES_MAX; i++)
        scene->sprites[i] = NULL;
    scene->num_sprites = 0;

    return scene;
}

void scene_delete(Scene* scene) {
    free(scene->sprites);
    free(scene);
}

void scene_add_sprite(Scene* scene, Sprite* sprite) {
    log_assert(scene->num_sprites <= NUM_SPRITES_MAX, "failed to add sprite to scene! sprite limit was reached.\n");
    scene->sprites[scene->num_sprites] = sprite;
    scene->num_sprites++;
}

void scene_remove_sprite(Scene* scene, Sprite* sprite) {
    // find the right sprite pointer
    int sprite_index = -1;
    for (int i = 0; i < scene->num_sprites; i++) {
        if (scene->sprites[i] == sprite) {
            sprite_index = i;
            break;
        }
    }
    log_assert(sprite_index != -1, "failed to find sprite in scene! maybe it's not in the scene?\n");

    // remove the sprite
    for (int i = sprite_index; i < scene->num_sprites; i++) {
        scene->sprites[i] = scene->sprites[i + 1];
    }
    scene->sprites[scene->num_sprites] = NULL;

    scene->num_sprites--;
}

void scene_update(Scene* scene, float timestep) {
    for (unsigned int i = 0; i < scene->num_sprites; i++) {
        Sprite* sprite = scene->sprites[i];
        sprite->update_function(sprite, timestep);
    }
}

void scene_render_sprites(Scene* scene, Window* window) {
    for (unsigned int i = 0; i < scene->num_sprites; i++) {
        Sprite* sprite = scene->sprites[i];
        sprite->draw_function(sprite, window);
    }
}

