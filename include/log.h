#ifndef LOG_H
#define LOG_H

#include <config.h>
#include <stdlib.h>
#include <stdio.h>

#ifdef TOTO_DEBUG
    #define TOTO_INFO(msg, ...) fprintf(stdout, msg"\n", ##__VA_ARGS__);
    #define TOTO_ERROR(msg, ...) fprintf(stderr, msg"\n", ##__VA_ARGS__);
    #define TOTO_ASSERT(cond, msg) if (!(cond)) { TOTO_ERROR(msg); abort(); }
    #define TOTO_ASSERT_VA(cond, msg, ...) if (!(cond)) { TOTO_ERROR(msg, ##__VA_ARGS__); abort(); }
#else
    #define TOTO_INFO(msg, ...)
    #define TOTO_ERROR(msg, ...)
    #define TOTO_ASSERT(cond, msg, ...)
#endif

#endif

