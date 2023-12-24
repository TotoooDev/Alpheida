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

App* app_new(const char* name) {
    App* app = (App*)malloc(sizeof(App));
    
    app->window = window_new(name, 800, 600);
    app->current_scene = NULL;
    app->timestep = 0.0f;

    #ifdef TOTO_SWITCH
        switch_init();
    #endif

    return app;
}

void app_delete() {
    #ifdef TOTO_SWITCH
        switch_exit();
    #endif

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

        #ifdef TOTO_SWITCH
            switch_update();
        #endif

        // calculate the timestep
        float current_time = timer_get_time_ms();
        app_instance->timestep = current_time - app_instance->last_time;
        app_instance->last_time = current_time;
    }
}

void app_set_current_scene(Scene* scene) {
    app_get()->current_scene = scene;
}

