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

EventType platform_process_events(void* event) {
    if (keys_down & HidNpadButton_Plus) {
        ((KeyDownEvent*)event)->key = JOY_PLUS;
        return EVENT_TYPE_BUTTON_DOWN;
    }

    return EVENT_TYPE_NONE;
}

#endif
