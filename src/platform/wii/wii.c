#include <platform/config.h>

#ifdef SHRIMP_WII

#include <app.h>
#include <wiiuse/wpad.h>

void wii_init() {
    WPAD_Init();
}

void wii_update() {
    WPAD_ScanPads();

    // temp
    if (WPAD_ButtonsDown(0) & WPAD_BUTTON_HOME)
        app_quit();
}

#endif
