#ifndef PLATFORM_H
#define PLATFORM_H

#include <event.h>
#include <types.h>

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

/**
 * @returns The number of milliseconds since the app is launched.
*/
u32 platform_get_time();

#endif

