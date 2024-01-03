#include <game/main_scene.h>
#include <platform/input.h>
#include <app.h>

void mainscene_on_event(void* user_pointer, SDL_Event event) {
    if (event.type == SDL_JOYBUTTONDOWN) {
        switch (event.jbutton.button) {
        case JOY_PLUS:
            app_quit();
            break;
        default:
            break;
        }
    }
}

MainScene* mainscene_new() {
    MainScene* scene = (MainScene*)malloc(sizeof(MainScene));

    PhysicsWorld* world = physics_new();
    scene->scene = scene_new_physics(world);

    scene->shrimp = shrimp_new(scene->scene);

    scene->ground = sprite_new_color(0.0f, 550.0f, 1000000.0f, 1000000.0f, color_black());
    PhysicsObject* ground_physics = physics_add_physics_object(world, scene->ground);
    ground_physics->takes_gravity = false;

    scene_add_sprite(scene->scene, scene->shrimp->sprite);
    scene_add_sprite(scene->scene, scene->ground);

    window_add_event_function(NULL, mainscene_on_event);

    return scene;
}

void mainscene_delete(MainScene* scene) {
    sprite_delete(scene->ground);
    shrimp_delete(scene->shrimp);
    physics_delete(scene_get_physics_world(scene->scene));
    scene_delete(scene->scene);
    free(scene);
}
