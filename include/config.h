#ifndef DEBUG_H
#define DEBUG_H

#if !defined(NDEBUG)
    #define SHRIMP_DEBUG
#endif

#if defined(__SWITCH__)
    #define SHRIMP_SWITCH
#elif defined(__WII__)
    #define SHRIMP_WII
#else
    #define SHRIMP_LINUX
#endif

#define AUDIO_FREQUENCY 48000
#define AUDIO_FORMAT AUDIO_S16SYS
#define AUDIO_NUM_CHANNELS 2
#define AUDIO_CHUNK_SIZE 2048

#endif

