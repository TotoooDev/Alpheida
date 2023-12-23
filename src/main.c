#include <stdio.h>
#include <app.h>

int main(/*int argc, char* argv*/) {
    printf("Hi mom!\n");
    App* app = app_new();
    app_delete(app);
    return 0;
}
