#include <config.h>
#ifdef TOTO_SWITCH

#include <platform/switch.h>
#include <log.h>
#include <switch.h>
#include <unistd.h>

void switch_init() {
    // initialize romfs
    Result result = romfsInit();
    log_assert(!R_FAILED(result), "%08X: failed to initialize switch romfs!\n", result);
    chdir("romfs:/");    
    // initialize nxlink for printf debugging
    // https://switch.homebrew.guide/homebrew_dev/app_dev.html#printf-debugging-through-nxlink
    socketInitializeDefault();
    nxlinkStdio();
}

void switch_update() {

}

void switch_exit() {
    socketExit();
    romfsExit();
}

#endif

