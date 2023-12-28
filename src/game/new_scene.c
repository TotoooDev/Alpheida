#include <game/new_scene.h>
#include <game/controller.h>
#include <fs.h>
#include <window.h>
#include <platform/input.h>
#include <app.h>
#include <log.h>

#include <string.h>
#include <stdio.h>
#include <dirent.h>

typedef struct NewScene {
    Scene* scene;
} NewScene;

void newscene_on_event(void* user_pointer, SDL_Event event) {
    if (event.type == SDL_JOYBUTTONDOWN) {
        if (event.jbutton.button == JOY_PLUS)
            app_quit();
    }
}

NewScene* newscene_new() {
    NewScene* scene = (NewScene*)malloc(sizeof(NewScene*));

    scene->scene = scene_new();

    Texture* texture = texture_new(fs_get_path_romfs("images/pp.jpg"));
    Sprite* sprite = sprite_new(0, 0, 128, 128, texture);
    scene_add_sprite(scene->scene, sprite);

    window_add_event_function((void*)sprite, controller_on_event);
    window_add_event_function(NULL, newscene_on_event);

    return scene;
}

void newscene_delete(NewScene* scene) {
    scene_delete(scene->scene);
    free(scene);
}

Scene* newscene_get_scene(NewScene* scene) {
    return scene->scene;
}

