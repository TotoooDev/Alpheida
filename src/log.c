#include <log.h>
#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void log_log(FILE* out, const char* msg, va_list parameters) {
#ifdef TOTO_DEBUG
    // print to stdout
    vfprintf(out, msg, parameters);

    // print to log file
    FILE* file = fopen(LOG_FILE_PATH, "w");
    log_assert(file != NULL, "failed to open log file! something is terribly wrong...\n");
    vfprintf(file, msg, parameters);
    fclose(file);
#endif
}

void log_info(const char* msg, ...) {
#ifdef TOTO_DEBUG
    va_list parameters;
    va_start(parameters, msg);
    log_log(stdout, msg, parameters);
    va_end(parameters);
#endif
}

void log_error(const char* msg, ...) {
#ifdef TOTO_DEBUG
    va_list parameters;
    va_start(parameters, msg);
    log_log(stderr, msg, parameters);
    va_end(parameters);
#endif
}

void log_assert(bool cond, const char* msg, ...) {
#ifdef TOTO_DEBUG
    if (!cond) {
        va_list parameters;
        va_start(parameters, msg);
        log_log(stderr, msg, parameters);
        va_end(parameters);
        abort();
    }
#endif
}
