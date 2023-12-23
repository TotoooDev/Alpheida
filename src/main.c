#include <stdio.h>
#include <app.h>

int main(/*int argc, char* argv*/) {
    app_run(app_get());
    app_delete();
    return 0;
}
