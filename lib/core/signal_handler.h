#ifndef SIGNAL_HANDLER_H
#define SIGNAL_HANDLER_H

#include <pthread.h>
#include <signal.h>
#include <stddef.h>

#include "log.h"

typedef struct signal_info_t signal_info_t;

struct signal_info_t {
    int signal;
    const char *description;
    int log_level;
};

extern const signal_info_t signals[];
extern const size_t signal_count;

int initialize_signal_handler(pthread_t *signal_thread, sigset_t *set);

#endif /* SIGNAL_HANDLER_H */
