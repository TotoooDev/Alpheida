#ifndef DEBUG_H
#define DEBUG_H

#if !defined(NDEBUG)
    #define SHRIMP_DEBUG
#endif

#ifdef __SWITCH__
    #define SHRIMP_SWITCH
#endif

#endif

