#include <platform/platform.h>
#include <platform/sdl_events.h>
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

void platform_process_events(EventType* event_type, void* event) {
#ifdef SHRIMP_PLATFORMS_THAT_DONT_USE_SDL2_TO_HANDLE_EVENTS_THATS_A_LOT_I_THINK
#else
    sdl_process_events(event_type, event);
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
    *width = 1280;
    *height = 720;
#endif
}

