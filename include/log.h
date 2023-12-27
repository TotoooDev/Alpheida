#ifndef LOG_H
#define LOG_H

#include <stdbool.h>

void log_info(const char* msg, ...);
void log_error(const char* msg, ...);
void log_assert(bool cond, const char* msg, ...);

#endif

