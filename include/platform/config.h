#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

#if defined(__SWITCH__)
    #define SHRIMP_SWITCH
#elif defined(__WII__)
    #define SHRIMP_WII
#else
    #define SHRIMP_LINUX
#endif

#endif
