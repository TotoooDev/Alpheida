#include <app.h>
#include <stdlib.h>

typedef struct App {
    int foo;
} App;

App* app_new() {
    App* app = (App*)malloc(sizeof(App));
    app->foo = 5;

    return app;
}

void app_delete(App* app) {
    free(app);
}

