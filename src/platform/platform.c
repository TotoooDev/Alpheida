#include <platform/platform.h>
#include <log.h>

#include <config.h>

#ifdef SHRIMP_SWITCH
#include <platform/switch/switch_events.h>
#endif

#ifdef SHRIMP_LINUX
#include <platform/linux/linux_events.h>
#endif

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
#endif
#ifdef SHRIMP_SWITCH
    switch_process_events(event_type, event);
#endif
#ifdef SHRIMP_LINUX
    linux_process_events(event_type, event);
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

