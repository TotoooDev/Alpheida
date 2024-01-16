#include <engine/platform/config.h>

#ifdef SHRIMP_WII

#include <engine/platform/platform.h>

void platform_process_events(EventType* event_type, void* e) {
    *event_type = EVENT_TYPE_NONE;
}

#endif
