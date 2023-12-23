#ifndef APPLICATION_H
#define APPLICATION_H

#include <window.h>

typedef struct App App;

App* app_get();
void app_delete();

Window* app_get_window(App* app);

void app_run(App* app);

#endif

