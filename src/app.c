#include <app.h>

typedef struct App {
    Window* window;
} App;

static App* app_instance = NULL;

App* app_new(const char* name) {
    App* app = (App*)malloc(sizeof(App));
    
    app->window = window_new(name, 800, 600);

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

Window* app_get_window(App* app) {
    return app->window;
}

void app_run(App* app) {
    while (window_is_open(app->window)) {
        window_poll_events(app->window);
        window_clear(app->window);
        window_present(app->window);
    }
}

