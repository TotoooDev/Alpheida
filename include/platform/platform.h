#ifndef PLATFORM_H
#define PLATFORM_H

#include <event.h>

/**
 * Initializes the platform.
*/
void platform_init();

/**
 * Updates the platform.
*/
void platform_update();

/**
 * Processes the platform's events.
*/
void platform_process_events(EventType* event_type, void* event);

/**
 * Exits the platform.
*/
void platform_exit();

#endif

