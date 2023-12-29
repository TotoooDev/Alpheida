#include <platform/platform.h>

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

