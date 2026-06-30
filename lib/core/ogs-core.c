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

#include "ogs-core.h"

int __ogs_mem_domain;
int __ogs_sock_domain;
int __ogs_event_domain;
int __ogs_thread_domain;
int __ogs_tlv_domain;

static ogs_core_context_t self = {
    .log.pool = 8,
    .log.domain_pool = 64,
    .log.level = LOG_DEFAULT,

    .pkbuf.pool = 8,
    .pkbuf.config_pool = 8,

    .tlv.pool = 512,
};

void ogs_core_initialize(void)
{
    ogs_mem_init();
    ogs_pkbuf_init();
    ogs_socket_init();
    ogs_tlv_init();
}

void ogs_core_terminate(void)
{
    ogs_tlv_final();
    ogs_socket_final();
    ogs_pkbuf_final();
    ogs_mem_final();
}

ogs_core_context_t *ogs_core(void)
{
    return &self;
}
