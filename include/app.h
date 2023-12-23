#ifndef APPLICATION_H
#define APPLICATION_H

#include <window.h>
#include <scene.h>

typedef struct App App;

App* app_get();
void app_delete();

Window* app_get_window();

void app_run();

void app_set_current_scene(Scene* scene);

#endif

