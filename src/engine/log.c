#include <engine/log.h>
#include <engine/platform/fs.h>
#include <engine/config.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

#define LOG_FILE_PATH "alpheida.log"

void log_log(FILE* out, const char* msg, va_list parameters) {
#ifdef SHRIMP_DEBUG
    // print to stdout
    vfprintf(out, msg, parameters);
#endif
}

void log_info(const char* msg, ...) {
#ifdef SHRIMP_DEBUG
    va_list parameters;
    va_start(parameters, msg);
    log_log(stdout, msg, parameters);
    va_end(parameters);
#endif
}

void log_error(const char* msg, ...) {
#ifdef SHRIMP_DEBUG
    va_list parameters;
    va_start(parameters, msg);
    log_log(stderr, msg, parameters);
    va_end(parameters);
#endif
}

void log_assert(bool cond, const char* msg, ...) {
    if (!cond) {
        va_list parameters;
        va_start(parameters, msg);
        log_log(stderr, msg, parameters);
        va_end(parameters);
        abort();
    }
}
