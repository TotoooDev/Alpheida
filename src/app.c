#include <app.h>
#include <window.h>

typedef struct App {
    Window* window;
} App;

App* app_new(const char* name) {
    App* app = (App*)malloc(sizeof(App));
    
    app->window = window_new(name, 800, 600);

    return app;
}

void app_delete(App* app) {
    window_delete(app->window);
    free(app);
}

void app_run(App* app) {
    while (window_is_open(app->window)) {
        window_poll_events(app->window);
    }
}

