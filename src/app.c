#include <app.h>
#include <timer.h>
#include <event.h>
#include <platform/platform.h>
#include <log.h>
#include <stdlib.h>

typedef struct App {
    Window* window;
    Scene* current_scene;

    bool is_running;
    
    f32 timestep;
    f32 last_time;
} App;

static App* app_instance = NULL;

void app_on_event(void* event, EventType event_type, void* user_pointer) {
    App* app = (App*)user_pointer;
    
    if (event_type == EVENT_TYPE_PLATFORM_QUIT)
        app->is_running = false;
}

void app_update_timestep() {
    f32 current_time = (f32)platform_get_time() * 0.001f;
    app_instance->timestep = current_time - app_instance->last_time;
    app_instance->last_time = current_time;
}

void app_create(const char* name) {
    log_assert(app_instance == NULL, "an application already exists!\n");

    app_instance = (App*)malloc(sizeof(App));

    app_instance->window = window_new(name, 1280, 720);
    app_instance->current_scene = NULL;
    app_instance->is_running = true;
    app_instance->timestep = 0.0f;
    app_instance->last_time = 0.0f;

    platform_init();

    event_add_function((void*)app_instance, app_on_event);
}

void app_delete() {
    platform_exit();
    window_delete(app_instance->window);
    free(app_instance);
}

Window* app_get_window() {
    return app_instance->window;
}

void app_run() {
    while (app_instance->is_running) {
        window_clear(app_instance->window);
        
        if (app_instance->current_scene) {
            scene_update(app_instance->current_scene, app_instance->timestep);
            scene_render_sprites(app_instance->current_scene, app_instance->window);
        }
        
        window_present(app_instance->window);

        app_update_timestep();
        
        platform_update();
        
        event_update();
    }
}

void app_quit() {
    app_instance->is_running = false;
}

void app_set_current_scene(Scene* scene) {
    app_instance->current_scene = scene;
}

