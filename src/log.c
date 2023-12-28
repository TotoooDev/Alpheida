#include <log.h>
#include <fs.h>
#include <config.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void log_log(FILE* out, const char* msg, va_list parameters) {
#ifdef TOTO_DEBUG
    // print to stdout
    vfprintf(out, msg, parameters);

    // print to log file
    FILE* file = fopen(fs_get_path(LOG_FILE_PATH), "a+");
    // i would love to use log_assert here but log_assert calls log_log so it's not a good idea lol
    if (file == NULL)
        fprintf(file, "failed to open log file %s! something is terribly wrong...\n", LOG_FILE_PATH);
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
