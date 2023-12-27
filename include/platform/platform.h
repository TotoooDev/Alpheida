#ifndef PLATFORM_H
#define PLATFORM_H

#include <config.h>

#ifdef TOTO_SWITCH
#include <platform/switch.h>
#endif

void platform_init();
void platform_update();
void platform_exit();

#endif

