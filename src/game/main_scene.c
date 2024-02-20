#include <game/main_scene.h>
#include <engine/event.h>
#include <engine/platform/input.h>
#include <engine/app.h>
#include <engine/platform/fs.h>
#include <stdlib.h>

void mainscene_on_event(void* e, EventType event_type, void* user_pointer) {
    if (event_type == EVENT_TYPE_BUTTON_DOWN) {
        ButtonDownEvent* event = (ButtonDownEvent*)e;
        switch (event->button) {
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
    physics_set_gravity(scene_get_physics_world(scene->scene), (vec2){ 0.0f, -20.0f });

    scene_set_background(scene->scene, background_new(texture_new(fs_get_path_romfs("images/shitty_background.png")), 0, 0));

    scene->shrimp = shrimp_new(scene->scene);

    scene->test_enemy = enemy_new(scene->scene, scene->shrimp, ENEMY_TYPE_OIL, (vec2){ 800.0f, 100.0f }, true);

    scene->life = life_new(scene->shrimp, scene->scene);

    vec2 pos = {0.0f, 0.0f};
    vec2 scale = {10000.0f, 10.0f};
    scene->ground = sprite_new_color(pos, scale, color_magenta());
    PhysicsObject* ground_physics = physics_add_physics_object(world, scene->ground);
    ground_physics->takes_gravity = false;
    ground_physics->moved_by_collision = false;
    ground_physics->filter = physics_set_all_filters();

    scene_add_sprite(scene->scene, scene->shrimp->sprite);
    scene_add_sprite(scene->scene, scene->test_enemy->sprite);
    scene_add_sprite(scene->scene, scene->ground);

    event_add_function(NULL, mainscene_on_event);

    return scene;
}

void mainscene_delete(MainScene* scene) {
    sprite_delete(scene->ground);
    life_delete(scene->life);
    shrimp_delete(scene->shrimp);
    enemy_delete(scene->test_enemy);
    scene_delete(scene->scene);
    free(scene);
}
