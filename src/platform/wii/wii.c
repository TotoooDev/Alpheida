#include <config.h>

#ifdef SHRIMP_WII

#include <wiiuse/wpad.h>

void wii_init() {
    WPAD_Init();
}

#endif
