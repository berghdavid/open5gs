/*
 * Copyright (C) 2025 by Juraj Elias <juraj.elias@gmail.com>
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

#ifndef LMF_NRPPA_PARSE_H
#define LMF_NRPPA_PARSE_H

#include "NRPPA-PDU.h"
#include "Cause.h"
#include "NRCellIdentifier.h"
#include "PLMN-Identity.h"
#include "ogs-core.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Parse NRPPa PDU */
int lmf_nrppa_parse_pdu(ogs_pkbuf_t *pkbuf, NRPPA_PDU_t *pdu);
void log_cause(const char *supi, Cause_t *cause);

/* Returns the complete 36-bit NR Cell Identity. */
uint64_t get_cell_id(const BIT_STRING_t *nci);

/* Returns the eNB-ID.
 */
uint32_t get_enb_id(const BIT_STRING_t *nci);

/* Returns the gNB-ID.
 * gnb_id_bits must be between 22 and 32.
 */
uint32_t get_gnb_id(const BIT_STRING_t *nci, unsigned gnb_id_bits);

/* Returns the Cell ID part (optional). */
uint16_t get_sector_id(const BIT_STRING_t *nci, unsigned gnb_id_bits);

#ifdef __cplusplus
}
#endif

#endif /* LMF_NRPPA_PARSE_H */
