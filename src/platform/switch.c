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
    TOTO_ASSERT_VA(!R_FAILED(result), "%08X: failed to initialize switch romfs!\n", result);
}

void switch_update() {
    padUpdate(&pad);
    consoleUpdate(NULL);
}

void switch_exit() {
    romfsExit();
    consoleExit(NULL);
}

#endif

