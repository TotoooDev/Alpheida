#ifndef DEBUG_H
#define DEBUG_H

#if !defined(NDEBUG)
    #define TOTO_DEBUG
#endif

#ifdef __SWITCH__
    #define TOTO_SWITCH
#endif

#define LOG_FILE_PATH "alpheida.log"

#endif

