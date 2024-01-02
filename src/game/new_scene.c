#include <game/new_scene.h>
#include <game/controller.h>
#include <sound.h>
#include <fs.h>
#include <window.h>
#include <platform/input.h>
#include <app.h>
#include <log.h>

typedef struct NewScene {
    Scene* scene;
    
    Sprite* sprite;
    Texture* sprite_texture;

    Sprite* ground;

    Sound* sound;
} NewScene;

void newscene_on_event(void* user_pointer, SDL_Event event) {
    NewScene* scene = (NewScene*)user_pointer;
    
    if (event.type == SDL_JOYBUTTONDOWN) {
        switch (event.jbutton.button) {
        case JOY_PLUS:
            app_quit();
            break;

        case JOY_A:
            sound_play(scene->sound);
            break;

        default:
            break;
        }
    }

    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_Z:
            sound_play(scene->sound);
            break;

        default:
            break;
        }
    }
}

NewScene* newscene_new() {
    NewScene* scene = (NewScene*)malloc(sizeof(NewScene));

    PhysicsWorld* world = physics_new();
    scene->scene = scene_new_physics(world);

    scene->sprite_texture = texture_new(fs_get_path_romfs("images/cool_image.jpg"));
    scene->sprite = sprite_new(0, 0, 128, 128, scene->sprite_texture);
    scene_add_sprite(scene->scene, scene->sprite);
    physics_add_physics_object(world, scene->sprite);

    scene->ground = sprite_new_color(0, 590, 1280, 10000, color_magenta());
    scene_add_sprite(scene->scene, scene->ground);
    PhysicsObject* ground_physics = physics_add_physics_object(world, scene->ground);
    ground_physics->takes_gravity = false;

    scene->sound = sound_new(fs_get_path_romfs("sounds/sound.mp3"));

    window_add_event_function((void*)(scene->sprite), controller_on_event);
    window_add_event_function((void*)scene, newscene_on_event);

    return scene;
}

void newscene_delete(NewScene* scene) {
    sprite_delete(scene->sprite);
    texture_delete(scene->sprite_texture);

    sprite_delete(scene->ground);

    sound_delete(scene->sound);

    physics_delete(scene_get_physics_world(scene->scene));
    scene_delete(scene->scene);
    free(scene);
}

Scene* newscene_get_scene(NewScene* scene) {
    return scene->scene;
}

