#include <app.h>
#include <timer.h>

typedef struct App {
    Window* window;
    Scene* current_scene;

    float timestep;
    float last_time;
} App;

static App* app_instance = NULL;

App* app_new(const char* name) {
    App* app = (App*)malloc(sizeof(App));
    
    app->window = window_new(name, 800, 600);
    app->current_scene = NULL;
    app->timestep = 0.0f;

    return app;
}

void app_delete() {
    window_delete(app_instance->window);
    free(app_instance);
}

App* app_get() {
    if (app_instance == NULL)
        app_instance = app_new("Alpheida");
    return app_instance;
}

Window* app_get_window() {
    return app_instance->window;
}

void app_run() {
    while (window_is_open(app_instance->window)) {
        window_poll_events(app_instance->window);
        window_clear(app_instance->window);
        
        if (app_instance->current_scene) {
            scene_update(app_instance->current_scene, app_instance->timestep);
            scene_render_sprites(app_instance->current_scene, app_instance->window);
        }
        
        window_present(app_instance->window);

        // calculate the timestep
        float current_time = timer_get_time_ms();
        app_instance->timestep = current_time - app_instance->last_time;
        app_instance->last_time = current_time;
    }
}

void app_set_current_scene(Scene* scene) {
    app_instance->current_scene = scene;
}

