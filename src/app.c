#include <app.h>
#include <timer.h>
#include <config.h>
#ifdef TOTO_SWITCH
    #include <platform/switch.h>
#endif

typedef struct App {
    Window* window;
    Scene* current_scene;

    float timestep;
    float last_time;
} App;

static App* app_instance = NULL;

void app_platform_init() {
    #ifdef TOTO_SWITCH
        switch_init();
    #endif
}

void app_platform_update() {
    #ifdef TOTO_SWITCH
        switch_update();
    #endif
}

void app_platform_exit() {
    #ifdef TOTO_SWITCH
        switch_exit();
    #endif
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
    app->timestep = 0.0f;

    app_platform_init();

    return app;
}

void app_delete() {
    app_platform_exit();
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

        app_platform_update();

        app_update_timestep();
    }
}

void app_set_current_scene(Scene* scene) {
    app_get()->current_scene = scene;
}

