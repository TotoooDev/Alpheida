#include <app.h>
#include <timer.h>
#include <platform/platform.h>
#include <log.h>

typedef struct App {
    Window* window;
    Scene* current_scene;

    bool is_running;
    
    float timestep;
    float last_time;
} App;

static App* app_instance = NULL;

void app_event_functions(void* user_pointer, SDL_Event event) {
    App* app = (App*)user_pointer;
    
    if (event.type == SDL_QUIT)
        app->is_running = false;
}

void app_update_timestep() {
    float current_time = timer_get_time_ms();
    app_get()->timestep = current_time - app_get()->last_time;
    app_get()->last_time = current_time;
}

App* app_new(const char* name) {
    App* app = (App*)malloc(sizeof(App));
    
    app->window = window_new(name, 800, 600);
    app->current_scene = NULL;
    app->is_running = true;
    app->timestep = 0.0f;
    app->last_time = 0.0f;

    platform_init();

    return app;
}

void app_delete() {
    platform_exit();
    window_delete(app_instance->window);
    free(app_instance);
}

App* app_get() {
    if (app_instance == NULL)
        app_instance = app_new("Alpheida");
    return app_instance;
}

Window* app_get_window() {
    return app_get()->window;
}

void app_run() {
    app_get();

    while (window_is_open(app_instance->window)) {
        window_poll_events(app_instance->window);
        window_clear(app_instance->window);
        
        if (app_instance->current_scene) {
            scene_update(app_instance->current_scene, app_instance->timestep);
            scene_render_sprites(app_instance->current_scene, app_instance->window);
        }
        
        window_present(app_instance->window);

        app_update_timestep();
        
        platform_update();
    }
}

void app_set_current_scene(Scene* scene) {
    app_get()->current_scene = scene;
}

