#include <game/new_scene.h>
#include <game/controller.h>
#include <fs.h>
#include <window.h>
#include <platform/input.h>
#include <app.h>
#include <timer.h>
#include <log.h>

typedef struct NewScene {
    Scene* scene;
} NewScene;

void newscene_on_event(void* user_pointer, SDL_Event event) {
    if (event.type == SDL_JOYBUTTONDOWN) {
        log_info("button pressed: %d\n", event.jbutton.button);
        if (event.jbutton.button == JOY_PLUS)
            app_quit();
    }
}

void newscene_update_sprite(Sprite* sprite, float timestep) {
    float time = timer_get_time_s();
    sprite->color = color_newf(sinf(time), cosf(time + 3.14f), sinf(time + 1.5f), 1.0f);
}

NewScene* newscene_new() {
    NewScene* scene = (NewScene*)malloc(sizeof(NewScene*));

    scene->scene = scene_new();

    // Texture* texture = texture_new(fs_get_path_romfs("images/pp.jpg"));
    Sprite* sprite = sprite_new_color(0, 0, 128, 128, color_magenta());
    sprite->update_function = newscene_update_sprite;
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

