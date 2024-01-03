#include <app.h>

int main(/*int argc, char* argv*/) {
    app_create("Alpheida: Deluxe Edition");
    app_run();

    newscene_delete(scene);
    app_delete();
    return 0;
}
