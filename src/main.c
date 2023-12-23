#include <stdio.h>
#include <app.h>
#include <game/new_scene.h>

int main(/*int argc, char* argv*/) {
    NewScene* scene = newscene_new();
    app_set_current_scene(newscene_get_scene(scene));

    app_run();
    app_delete();
    return 0;
}
