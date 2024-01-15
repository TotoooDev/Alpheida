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
EventType platform_process_events(void* event);

/**
 * Exits the platform.
*/
void platform_exit();

#endif

