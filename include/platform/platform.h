#ifndef PLATFORM_H
#define PLATFORM_H

#include <event.h>

void platform_init();
void platform_update();
void platform_process_events(EventType* event_type, void* event);
void platform_exit();

#endif

