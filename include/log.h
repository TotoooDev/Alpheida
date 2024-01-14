#ifndef LOG_H
#define LOG_H

#include <stdbool.h>

/**
 * Logs a message to stdout and into a file.
 * @param msg The message to log.
 * @param ... The arguments you can pass to format the string.
 * @note This calls `printf` internally, so the formatting is the same as for `printf`.
*/
void log_info(const char* msg, ...);

/**
 * Logs a message to stderr and into a file.
 * @param msg The message to log.
 * @param ... The arguments you can pass to format the string.
 * @note This calls `printf` internally, so the formatting is the same as for `printf`.
*/
void log_error(const char* msg, ...);

/**
 * Tests if a condition passes or not. If the condition does not pass, it logs a message and the program halts.
 * @param cond The condition to test.
 * @param msg The message to log if the condition does not pass.
 * @param ... More arguments to format the message.
*/
void log_assert(bool cond, const char* msg, ...);

#endif

