#include <platform/config.h>

#ifdef SHRIMP_WII

#include <platform/platform.h>
#include <app.h>
#include <wiiuse/wpad.h>

void platform_init() {
    WPAD_Init();
}

void platform_update() {
    WPAD_ScanPads();

    // temp
    if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)
        app_quit();
}

void platform_exit() {
    
}

u32 platform_get_time() {
    
}

#endif
