/**
 * Copyright (c) 2020 rxi
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the MIT license. See `log.c` for details.
 */

#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

typedef struct
{
    va_list ap;
    const char *fmt;
    const char *file;
    struct tm *time;
    void *udata;
    int line;
    int level;
} log_Event;

typedef void (*log_LogFn)(log_Event *ev);
typedef void (*log_LockFn)(bool lock, void *udata);

typedef enum log_level_e log_level_e;

enum log_level_e
{
    LOG_TRACE,
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR,
    LOG_FATAL,
    LOG_DEFAULT = LOG_INFO,
    LOG_FULL = LOG_TRACE,
};

#define log_trace(...) log_msg(LOG_TRACE, __VA_ARGS__)
#define log_debug(...) log_msg(LOG_DEBUG, __VA_ARGS__)
#define log_info(...) log_msg(LOG_INFO, __VA_ARGS__)
#define log_warn(...) log_msg(LOG_WARN, __VA_ARGS__)
#define log_error(...) log_msg(LOG_ERROR, __VA_ARGS__)
#define log_fatal(...) log_msg(LOG_FATAL, __VA_ARGS__)

// TODO: Do something with error
#define log_error_msg(lvl, err, ...) log_msg(lvl, __VA_ARGS__)
#define log_msg(lvl, ...) log_log(lvl, __FILE__, __LINE__, __VA_ARGS__)

const char *log_level_string(log_level_e level);
void log_set_lock(log_LockFn fn, void *udata);
void log_set_level_str(const char *level);
void log_set_level(log_level_e level);
void log_set_quiet(bool enable);
int log_add_callback(log_LogFn fn, void *udata, log_level_e level);
int log_add_fp(FILE *fp, log_level_e level);

void log_log(log_level_e level, const char *file, int line, const char *fmt, ...);

void log_hexdump(log_level_e level, const unsigned char *data, size_t len);

#define log_assert(expr)                                              \
    do                                                                \
    {                                                                 \
        if (likely(expr))                                             \
            ;                                                         \
        else                                                          \
        {                                                             \
            log_fatal("%s: Assertion `%s' failed.", OGS_FUNC, #expr); \
            ogs_abort();                                              \
        }                                                             \
    } while (0)

#define log_assert_if_reached()                            \
    do                                                     \
    {                                                      \
        log_fatal("%s: should not be reached.", OGS_FUNC); \
        ogs_abort();                                       \
    } while (0)

#define log_expect(expr)                                                \
    do                                                                  \
    {                                                                   \
        if (likely(expr))                                               \
            ;                                                           \
        else                                                            \
        {                                                               \
            log_error("%s: Expectation `%s' failed.", OGS_FUNC, #expr); \
        }                                                               \
    } while (0)

#endif
