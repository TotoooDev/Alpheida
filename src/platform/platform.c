#include <platform/platform.h>

void platform_init() {
#ifdef TOTO_SWITCH
    switch_init();
#endif
}

void platform_update() {
#ifdef TOTO_SWITCH
    switch_update();
#endif
}

void platform_exit() {
#ifdef TOTO_SWITCH
    switch_exit();
#endif
}

