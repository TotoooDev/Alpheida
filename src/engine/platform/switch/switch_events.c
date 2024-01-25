#include <engine/platform/config.h>

#ifdef SHRIMP_SWITCH

#include <engine/platform/platform.h>
#include <engine/platform/input.h>
#include <engine/platform/switch/switch_events.h>
#include <engine/types.h>
#include <switch.h>

static u64 keys_down = 0;

void event_set_keys_down(u64 keys) {
    keys_down = keys;
}

bool switch_process_button_down(void* event, u32 shrimp_button, u64 switch_button) {
    if (keys_down & switch_button) {
        ((KeyDownEvent*)event)->key = shrimp_button;
        keys_down ^= switch_button;
        return true;
    }
    return false;
}

// honestly, what the fuck is this
bool switch_process_buttons_down(void* event) {
    if (
        switch_process_button_down(event, JOY_A, HidNpadButton_A) ||
        switch_process_button_down(event, JOY_B, HidNpadButton_B) ||
        switch_process_button_down(event, JOY_X, HidNpadButton_X) ||
        switch_process_button_down(event, JOY_Y, HidNpadButton_Y) ||
        switch_process_button_down(event, JOY_LSTICK_BUTTON, HidNpadButton_StickL) ||
        switch_process_button_down(event, JOY_RSTICK_BUTTON, HidNpadButton_StickR) ||
        switch_process_button_down(event, JOY_L, HidNpadButton_L) ||
        switch_process_button_down(event, JOY_R, HidNpadButton_R) ||
        switch_process_button_down(event, JOY_L2, HidNpadButton_ZL) ||
        switch_process_button_down(event, JOY_R2, HidNpadButton_ZR) ||
        switch_process_button_down(event, JOY_PLUS, HidNpadButton_Plus) ||
        switch_process_button_down(event, JOY_MINUS, HidNpadButton_Minus) ||
        switch_process_button_down(event, JOY_LEFT, HidNpadButton_Left) ||
        switch_process_button_down(event, JOY_UP, HidNpadButton_Up) ||
        switch_process_button_down(event, JOY_RIGHT, HidNpadButton_Right) ||
        switch_process_button_down(event, JOY_DOWN, HidNpadButton_Down) ||
        switch_process_button_down(event, JOY_LSTICK_LEFT, HidNpadButton_StickLLeft) ||
        switch_process_button_down(event, JOY_LSTICK_UP, HidNpadButton_StickLUp) ||
        switch_process_button_down(event, JOY_LSTICK_RIGHT, HidNpadButton_StickLRight) ||
        switch_process_button_down(event, JOY_LSTCIK_DOWN, HidNpadButton_StickLDown) ||
        switch_process_button_down(event, JOY_RSTICK_LEFT, HidNpadButton_StickRLeft) ||
        switch_process_button_down(event, JOY_RSTICK_UP, HidNpadButton_StickRUp) ||
        switch_process_button_down(event, JOY_RSTICK_RIGHT, HidNpadButton_StickRRight) ||
        switch_process_button_down(event, JOY_RSTICK_DOWN, HidNpadButton_StickRDown) ||
        switch_process_button_down(event, JOY_LSL, HidNpadButton_LeftSL) ||
        switch_process_button_down(event, JOY_LSR, HidNpadButton_LeftSR) ||
        switch_process_button_down(event, JOY_RSL, HidNpadButton_RightSL) ||
        switch_process_button_down(event, JOY_RSR, HidNpadButton_RightSR)
    )
        return true;
    else
        return false;
}

EventType platform_process_events(void* event) {
    if (switch_process_buttons_down(event))
        return EVENT_TYPE_BUTTON_DOWN;

    return EVENT_TYPE_NONE;
}

#endif
