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
        if (event.jbutton.button == JOY_PLUS)
            app_quit();
    }
}

NewScene* newscene_new() {
    NewScene* scene = (NewScene*)malloc(sizeof(NewScene*));

    PhysicsWorld* world = physics_new();    
    scene->scene = scene_new_physics(world);

    Texture* texture = texture_new(fs_get_path_romfs("images/cool_image.jpg"));
    Sprite* sprite = sprite_new(0, 0, 128, 128, texture);
    scene_add_sprite(scene->scene, sprite);
    physics_add_physics_object(world, sprite);

    Sprite* ground = sprite_new_color(0, 590, 1280, 10000, color_magenta());
    scene_add_sprite(scene->scene, ground);
    PhysicsObject* ground_physics = physics_add_physics_object(world, ground);
    ground_physics->takes_gravity = false;

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

