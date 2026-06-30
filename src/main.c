/*
 * Copyright (C) 2019-2025 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include <signal.h>
#include <unistd.h>
#include <sys/stat.h>

#include "ogs-app.h"
#include "version.h"

static void show_version(void)
{
    printf("LMF %s\n\n", LMF_VERSION);
}

static void show_help(const char *name)
{
    printf("Usage: %s [options]\n"
           "Options:\n"
           "   -c filename    : set configuration file\n"
           "   -l filename    : set logging file\n"
           "   -e level       : set global log-level (default:info)\n"
           "   -m domain      : set log-domain (e.g. mme:sgw:gtp)\n"
           "   -d             : print lots of debugging information\n"
           "   -t             : print tracing information for developer\n"
           "   -D             : start as a daemon\n"
           "   -v             : show version number and exit\n"
           "   -h             : show this message and exit\n"
           "   -k             : use <id> config section\n"
           "\n",
           name);
}

static void terminate(void)
{
    app_terminate();

    ogs_app_terminate();
}

int main(int argc, const char *const argv[])
{
    /**************************************************************************
     * Starting up process.
     *
     * Keep the order of starting-up
     */
    int rv, i, opt;
    struct optparse options;
    struct
    {
        char *config_file;
        char *config_section;
        char *log_file;
        char *log_level;
        char *domain_mask;

        bool enable_debug;
        bool enable_trace;
    } optarg;
    const char *argv_out[argc + 1];

    memset(&optarg, 0, sizeof(optarg));

    optparse_init(&options, (char **)argv);
    while ((opt = optparse(&options, "vhDc:l:e:m:dtk:")) != -1)
    {
        switch (opt)
        {
        case 'v':
            show_version();
            return OGS_OK;
        case 'h':
            show_help(argv[0]);
            return OGS_OK;
        case 'D':
#if !defined(_WIN32)
        {
            pid_t pid;
            pid = fork();

            log_assert(pid >= 0);

            if (pid != 0)
            {
                /* Parent */
                return EXIT_SUCCESS;
            }
            /* Child */

            setsid();
            umask(027);
        }
#else
            printf("%s: Not Support in WINDOWS", argv[0]);
#endif
        break;
        case 'c':
            optarg.config_file = options.optarg;
            break;
        case 'l':
            optarg.log_file = options.optarg;
            break;
        case 'e':
            optarg.log_level = options.optarg;
            break;
        case 'm':
            optarg.domain_mask = options.optarg;
            break;
        case 'd':
            optarg.enable_debug = true;
            break;
        case 't':
            optarg.enable_trace = true;
            break;
        case 'k':
            optarg.config_section = options.optarg;
            break;
        case '?':
            fprintf(stderr, "%s: %s\n", argv[0], options.errmsg);
            show_help(argv[0]);
            return OGS_ERROR;
        default:
            fprintf(stderr, "%s: should not be reached\n", OGS_FUNC);
            return OGS_ERROR;
        }
    }

    if (optarg.enable_debug)
        optarg.log_level = (char *)"debug";
    if (optarg.enable_trace)
        optarg.log_level = (char *)"trace";

    i = 0;
    argv_out[i++] = argv[0];

    if (optarg.config_file)
    {
        argv_out[i++] = "-c";
        argv_out[i++] = optarg.config_file;
    }
    if (optarg.log_file)
    {
        argv_out[i++] = "-l";
        argv_out[i++] = optarg.log_file;
    }
    if (optarg.log_level)
    {
        argv_out[i++] = "-e";
        argv_out[i++] = optarg.log_level;
    }
    if (optarg.domain_mask)
    {
        argv_out[i++] = "-m";
        argv_out[i++] = optarg.domain_mask;
    }
    if (optarg.config_section)
    {
        argv_out[i++] = "-k";
        argv_out[i++] = optarg.config_section;
    }

    argv_out[i] = NULL;

    pthread_t signal_thread;
    sigset_t set;

    initialize_signal_handler(&signal_thread, &set);

    rv = ogs_app_initialize(LMF_VERSION, DEFAULT_CONFIG_FILENAME, argv_out);
    if (rv != OGS_OK)
    {
        if (rv == OGS_RETRY)
            return EXIT_SUCCESS;

        log_fatal("Open5GS initialization failed. Aborted");
        return OGS_ERROR;
    }

    rv = app_initialize(argv_out);
    if (rv != OGS_OK)
    {
        if (rv == OGS_RETRY)
            return EXIT_SUCCESS;

        log_fatal("Open5GS initialization failed. Aborted");
        return OGS_ERROR;
    }

    atexit(terminate);
    pthread_join(signal_thread, NULL);

    log_info("Open5GS daemon terminating...");

    return OGS_OK;
}
