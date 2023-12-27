#include <config.h>
#ifdef TOTO_SWITCH

#include <platform/switch.h>
#include <log.h>
#include <switch.h>

static PadState pad;

void switch_init() {
    consoleInit(NULL);
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    padInitializeDefault(&pad);
    
    // initialize romfs
    Result result = romfsInit();
    log_assert(!R_FAILED(result), "%08X: failed to initialize switch romfs!\n", result);
    
    // initialize nxlink for printf debugging
    // https://switch.homebrew.guide/homebrew_dev/app_dev.html#printf-debugging-through-nxlink
    socketInitializeDefault();
    nxlinkStdio();
}

void switch_update() {
    padUpdate(&pad);
    consoleUpdate(NULL);
}

void switch_exit() {
    socketExit();
    
    romfsExit();
    consoleExit(NULL);
}

#endif

