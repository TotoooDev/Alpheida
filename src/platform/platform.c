#include <platform/platform.h>
#include <log.h>

void platform_init() {
#ifdef SHRIMP_SWITCH
    switch_init();
#endif
}

void platform_update() {
#ifdef SHRIMP_SWITCH
    switch_update();
#endif
}

void platform_exit() {
#ifdef SHRIMP_SWITCH
    switch_exit();
#endif
}

void platform_get_window_size(int* width, int* height) {
#ifdef SHRIMP_SWITCH
    *width = SWITCH_WINDOW_WIDTH;
    *height = SWITCH_WINDOW_HEIGHT;
#else
    *width = 800;
    *height = 600;
#endif
}

