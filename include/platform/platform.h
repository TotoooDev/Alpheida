#ifndef PLATFORM_H
#define PLATFORM_H

#include <config.h>

#ifdef SHRIMP_SWITCH
#include <platform/switch.h>
#endif

void platform_init();
void platform_update();
void platform_exit();

void platform_get_window_size(int* width, int* height);

#endif

