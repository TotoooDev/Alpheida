#include <engine/platform/config.h>
#ifdef SHRIMP_SWITCH

#include <engine/config.h>
#include <engine/app.h>
#include <engine/platform/platform.h>
#include <engine/platform/switch/switch_events.h>
#include <engine/platform/switch/switch_window.h>
#include <engine/log.h>
#include <switch.h>

static PadState pad_state;

void platform_init() {
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    padInitializeDefault(&pad_state);

    // initialize romfs
    Result result = romfsInit();
    log_assert(R_SUCCEEDED(result), "%08X: failed to initialize switch romfs!\n", result);

#ifdef SHRIMP_DEBUG
    // initialize nxlink for printf debugging
    // https://switch.homebrew.guide/homebrew_dev/app_dev.html#printf-debugging-through-nxlink
    socketInitializeDefault();
    nxlinkStdio();
#endif
}

void platform_update() {
    window_update_resolution(app_get_window());

    padUpdate(&pad_state);
    event_set_keys_down(padGetButtonsDown(&pad_state));

    HidAnalogStickState left_stick = padGetStickPos(&pad_state, 0);
    HidAnalogStickState right_stick = padGetStickPos(&pad_state, 1);
    event_set_left_joystick_state((f32)left_stick.x / (f32)JOYSTICK_MAX, (f32)left_stick.y / (f32)JOYSTICK_MAX);
    event_set_right_joystick_state((f32)right_stick.x / (f32)JOYSTICK_MAX, (f32)right_stick.y / (f32)JOYSTICK_MAX);
}

void platform_exit() {
#ifdef SHRIMP_DEBUG
    socketExit();
#endif

    romfsExit();
}

u32 platform_get_time() {
    return 1;
}

#endif

