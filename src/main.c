#include <stdio.h>
#include <app.h>

int main(/*int argc, char* argv*/) {
    App* app = app_new("Alpheida");
    app_run(app);
    app_delete(app);
    return 0;
}
