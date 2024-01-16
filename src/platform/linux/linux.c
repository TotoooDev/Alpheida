#include <platform/config.h>

#ifdef SHRIMP_LINUX

#include <platform/platform.h>
#include <SDL2/SDL.h>

// there is not much to do here...

void platform_init() {

}

void platform_update() {

}

void platform_exit() {

}

u32 platform_get_time() {
    return SDL_GetTicks();
}

#endif
