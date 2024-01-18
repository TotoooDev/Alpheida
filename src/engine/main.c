#include <engine/app.h>
#include <game/main_scene.h>

int main(/*int argc, char* argv*/) {
    app_create("Alpheida: Deluxe Edition");

    MainScene* main_scene = mainscene_new();
    app_set_current_scene(main_scene->scene);

    app_run();

    app_delete();
    mainscene_delete(main_scene);

    return 0;
}
