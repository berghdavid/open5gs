/*
 * Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>
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

#include "core-config-private.h"

#include "ogs-core.h"

char *ogs_env_get(const char *envvar)
{
#ifdef HAVE_GETENV
    return getenv(envvar);
#else
    return NULL;
#endif
}


int ogs_env_set(const char *envvar, const char *value)
{
#if defined(HAVE_SETENV)

    if (0 > setenv(envvar, value, 1)) {
        log_error("setenv() failed");
        return OGS_ERROR;
    }
    return OGS_OK;

#elif defined(HAVE_PUTENV)

    char buf[OGS_HUGE_LEN];

    if (ogs_snprintf(buf, OGS_HUGE_LEN, "%s=%s", envvar, value) < 0) {
        log_error("snprintf() failed");
        return OGS_ERROR; 
    }
    if (0 > putenv(buf)) {
        log_error("putenv() failed");
        return OGS_ERROR;
    }
    return OGS_OK;

#else
    log_error("Not implemented");
    return OGS_ERROR;
#endif
}


int ogs_env_delete(const char *envvar)
{
#ifdef HAVE_UNSETENV

    if (0 > unsetenv(envvar)) {
        log_error("unsetenv() failed");
        return OGS_ERROR; 
    }
    return OGS_OK;

#else
    /* hint: some platforms allow envvars to be unset via
     *       putenv("varname")...  that isn't Single Unix spec,
     *       but if your platform doesn't have unsetenv() it is
     *       worth investigating and potentially adding a
     *       configure check to decide when to use that form of
     *       putenv() here
     */
    log_error("Not implemented");
    return OGS_ERROR;
#endif
}
