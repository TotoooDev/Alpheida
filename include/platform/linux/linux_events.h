#ifndef LINUX_EVENTS_H
#define LINUX_EVENTS_H

#include <event.h>

void linux_process_events(EventType* event_type, void* event);

#endif
