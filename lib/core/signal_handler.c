#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <bits/types/sigset_t.h>

#include "signal_handler.h"

const signal_info_t signals[] = {
    {SIGHUP, "Hangup", LOG_FATAL},
    {SIGINT, "Interrupt", LOG_FATAL},
    {SIGQUIT, "Quit", LOG_FATAL},
    {SIGILL, "Illegal instruction", LOG_FATAL},
    {SIGTRAP, "Trace/BPT trap", LOG_INFO},
    {SIGABRT, "Abort", LOG_FATAL},
    {SIGFPE, "Arithmetic exception", LOG_ERROR},
    {SIGKILL, "Killed", LOG_INFO},
    {SIGBUS, "Bus error", LOG_FATAL},
    {SIGSEGV, "Segmentation fault", LOG_FATAL},
    {SIGWINCH, "Window changed", LOG_INFO},
};

const size_t signal_count = sizeof(signals) / sizeof(signals[0]);

static void log_signal(int sig)
{
	int i;
	for (i = 0; i < sizeof(signals); i++) {
		if (signals[i].signal == sig) {
			log_log(signals[i].log_level, "Signal %d received (%s)", sig, signals[i].description);
			return;
		}
	}
	log_warn("Unrecognized signal %d received", sig);
}

static void *signal_handler(void *arg)
{
	sigset_t *set = (sigset_t *)arg;
	int sig;

	while (1) {
		int ret = sigwait(set, &sig);
		if (ret != 0) {
			log_error("sigwait failed: %s", strerror(ret));
			continue;
		}

		switch (sig) {
		case SIGTERM:
		case SIGINT:
			log_info("%s received", sig == SIGTERM ? "SIGTERM" : "SIGINT");

			return NULL;
		case SIGHUP:
			log_info("SIGHUP received");

			break;

		default:
			log_signal(sig);
			break;
		}
	}
	return NULL;
}

/* Defines which signals to listen for */
static void add_signals(sigset_t *set)
{
	sigemptyset(set);

	int i;
	for (i = 0; i < signal_count; i++) {
		sigaddset(set, signals[i].signal);
	}
	
}

/* Create and start a new signal handler thread */
int initialize_signal_handler(pthread_t *signal_thread, sigset_t *set)
{
	if (signal_thread == NULL)
	{
		log_error("Uninitialized signal_thread object");
		return EXIT_FAILURE;
	}
	if (set == NULL)
	{
		log_error("Uninitialized sigset_t object");
		return EXIT_FAILURE;
	}

	add_signals(set);

	/* Block these signals in this thread (and thus all subsequently created threads) */
	if (pthread_sigmask(SIG_BLOCK, set, NULL) != 0)
	{
		log_error("pthread_sigmask");
		return EXIT_FAILURE;
	}

	/* Start the signal listener thread */
	if (pthread_create(signal_thread, NULL, signal_handler, set) != 0)
	{
		log_error("pthread_create");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
