#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <bits/types/sigset_t.h>

#include "signal_handler.h"

const SignalInfo signals[] = {
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
    {SIGWINCH, "Window changed", LOG_DEBUG},
};

const size_t signal_count = sizeof(signals) / sizeof(signals[0]);

static void log_signal(int sig)
{
	int i;
	for (i = 0; i < sizeof(signals); i++)
	{
		if (signals[i].signal == sig)
		{
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

	while (1)
	{
		int ret = sigwait(set, &sig);
		if (ret != 0)
		{
			fprintf(stderr, "sigwait failed: %s\n", strerror(ret));
			continue;
		}
		switch (sig)
		{
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

/* Create and start a new signal handler thread */
int initialize_signal_handler(pthread_t *signal_thread, sigset_t *set)
{
	if (signal_thread == NULL)
	{
		perror("Uninitialized signal_thread object");
		return EXIT_FAILURE;
	}
	if (set == NULL)
	{
		perror("Uninitialized sigset_t object");
		return EXIT_FAILURE;
	}

	sigemptyset(set);
	sigaddset(set, SIGINT);
	sigaddset(set, SIGTERM);
	sigaddset(set, SIGHUP);

	/* Block these signals in this thread (and thus all subsequently created threads) */
	if (pthread_sigmask(SIG_BLOCK, set, NULL) != 0)
	{
		perror("pthread_sigmask");
		return EXIT_FAILURE;
	}

	/* Start the signal listener thread */
	if (pthread_create(signal_thread, NULL, signal_handler, set) != 0)
	{
		perror("pthread_create");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
