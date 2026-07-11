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

#include "nrppa-parse.h"

int lmf_nrppa_parse_pdu(ogs_pkbuf_t *pkbuf, NRPPA_PDU_t *pdu)
{
    log_assert(pkbuf);
    
    if (pkbuf->len < 6) {
        log_error("NRPPa PDU too short (%u bytes)", pkbuf->len);
        return OGS_ERROR;
    }
    
    log_info("Parsing NRPPa PDU (%u bytes)", pkbuf->len);
    log_hexdump(LOG_INFO, pkbuf->data, pkbuf->len);

    asn_dec_rval_t dec_ret = aper_decode(NULL, &asn_DEF_NRPPA_PDU, (void**)&pdu,
        pkbuf->data, pkbuf->len, 0, 0);
    if (dec_ret.code == RC_OK) {
        return OGS_OK;
    }
    return OGS_ERROR;
}

void log_cause(const char *supi, Cause_t *cause)
{
    log_assert(supi != NULL);

    if (!cause) {
        log_error("[%s] Undefined cause", supi);
        return;
    }

    switch (cause->present) {
        case Cause_PR_NOTHING:
            log_warn("[%s] Undefined cause group choice [0]", supi);
            break;

        case Cause_PR_radioNetwork:
            switch (cause->choice.radioNetwork) {
                case CauseRadioNetwork_unspecified:
                    log_warn("[%s] Radio Network cause: Undefined [0]", supi);
                    break;
                case CauseRadioNetwork_requested_item_not_supported:
                    log_warn("[%s] Radio Network cause: Requested item not supported", supi);
                    break;
                case CauseRadioNetwork_requested_item_temporarily_not_available:
                    log_warn("[%s] Radio Network cause: Requested item temporarily unavailable", supi);
                    break;
                case CauseRadioNetwork_serving_NG_RAN_node_changed:
                    log_warn("[%s] Radio Network cause: Serving NG-RAN node changed", supi);
                    break;
                case CauseRadioNetwork_requested_item_not_supported_on_time:
                    log_warn("[%s] Radio Network cause: Requested item not supported on time", supi);
                    break;
                default:
                    log_error("[%s] Radio Network cause: Unrecognized [%ld]", supi, cause->choice.radioNetwork);
                    break;
            }
            break;

        case Cause_PR_protocol:
            switch (cause->choice.protocol) {
                case CauseProtocol_transfer_syntax_error:
                    log_warn("[%s] Protocol cause: Transfer syntax error", supi);
                    break;
                case CauseProtocol_abstract_syntax_error_reject:
                    log_warn("[%s] Protocol cause: Abstract syntax error reject", supi);
                    break;
                case CauseProtocol_abstract_syntax_error_ignore_and_notify:
                    log_warn("[%s] Protocol cause: Abstract syntax error ignore and notify", supi);
                    break;
                case CauseProtocol_message_not_compatible_with_receiver_state:
                    log_warn("[%s] Protocol cause: Message not compatible with receiver", supi);
                    break;
                case CauseProtocol_semantic_error:
                    log_warn("[%s] Protocol cause: Semantic error", supi);
                    break;
                case CauseProtocol_unspecified:
                    log_warn("[%s] Protocol cause: Unspecified", supi);
                    break;
                case CauseProtocol_abstract_syntax_error_falsely_constructed_message:
                    log_warn("[%s] Protocol cause: Abstract syntax error falsely constructed message", supi);
                    break;
                default:
                    log_error("[%s] Protocol cause: Unrecognized [%ld]", supi, cause->choice.radioNetwork);
                    break;
            }
            break;

        case Cause_PR_misc:
            switch (cause->choice.misc) {
                case CauseMisc_unspecified:
                    log_warn("[%s] Miscellaneous cause: Unspecified", supi);
                    break;
                default:
                    log_error("[%s] Miscellaneous cause: Unrecognized [%ld]", supi, cause->choice.radioNetwork);
                    break;
            }
            break;

        case Cause_PR_choice_Extension:
            log_warn("[%s] Miscellaneous cause: Unspecified", supi);
            break;

        default:
            log_error("[%s] Unrecognized cause group choice [%d]", supi, cause->present);
            break;
    }
}

/* Read up to 64 bits from a BIT STRING (MSB first). */
static uint64_t bitstring_to_uint64(const BIT_STRING_t *bs)
{
    uint64_t value = 0;
    size_t i;

    for (i = 0; i < bs->size; i++) {
        value = (value << 8) | bs->buf[i];
    }

    /* Remove unused bits from the LSB end. */
    if (bs->bits_unused) {
        value >>= bs->bits_unused;
    }

    return value;
}

uint64_t get_cell_id(const BIT_STRING_t *cid)
{
    return bitstring_to_uint64(cid);
}

uint32_t get_enb_id(const BIT_STRING_t *nci)
{
    uint64_t value = bitstring_to_uint64(nci);

    return (uint32_t)(value >> 8);
}

uint32_t get_gnb_id(const BIT_STRING_t *nci, unsigned gnb_id_bits)
{
    uint64_t value = bitstring_to_uint64(nci);
    unsigned cell_id_bits = 36 - gnb_id_bits;

    return (uint32_t)(value >> cell_id_bits);
}

uint16_t get_sector_id(const BIT_STRING_t *nci, unsigned gnb_id_bits)
{
    unsigned cell_id_bits = 36 - gnb_id_bits;

    return (uint16_t)(bitstring_to_uint64(nci) &((1ULL << cell_id_bits) - 1));
}
