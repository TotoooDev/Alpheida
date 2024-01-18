#ifndef PLATFORM_CONFIG_H
#define PLATFORM_CONFIG_H

#if defined(__SWITCH__)
    /**
     * Defined if the application is compiled for the Nintendo Switch.
    */
    #define SHRIMP_SWITCH
#elif defined(__WII__)
    /**
     * Defined if the application is compiled for the Wii.
    */
    #define SHRIMP_WII
#else
    /**
     * Defined if the application is compiled for Linux.
    */
    #define SHRIMP_LINUX
#endif

#endif
