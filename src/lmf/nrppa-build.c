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

#include "nrppa-build.h"

#include "NRPPA-PDU.h"
#include "InitiatingMessage.h"
#include "E-CIDMeasurementInitiationRequest.h"
#include "ProtocolIE-Container.h"
#include "ProtocolIE-Field.h"
#include "asn_SEQUENCE_OF.h"
#include "constr_TYPE.h"
#include "ogs-core.h"

static ogs_pkbuf_t *encode_nrppa_pdu(NRPPA_PDU_t *sptr)
{
    asn_enc_rval_t enc_ret = {0};
    ogs_pkbuf_t *pkbuf = NULL;

    log_assert(sptr);

    pkbuf = ogs_pkbuf_alloc(NULL, OGS_MAX_SDU_LEN);
    if (!pkbuf) {
        log_error("ogs_pkbuf_alloc() failed");
        return NULL;
    }
    ogs_pkbuf_put(pkbuf, OGS_MAX_SDU_LEN);

    enc_ret = aper_encode_to_buffer(&asn_DEF_NRPPA_PDU, NULL, sptr, pkbuf->data, OGS_MAX_SDU_LEN);
    if (enc_ret.encoded < 0) {
        if (enc_ret.failed_type) {
            log_error("Failed to encode ASN-PDU [type: %s]", enc_ret.failed_type->name);
        } else {
            log_error("Failed to encode ASN-PDU");
        }
        ogs_pkbuf_free(pkbuf);
        return NULL;
    }

    ogs_pkbuf_trim(pkbuf, ((enc_ret.encoded + 7) >> 3));

    return pkbuf;
}

ogs_pkbuf_t *lmf_nrppa_build_ecid_measurement_request(
    uint32_t measurement_id,
    uint64_t ue_ngap_id,
    uint8_t requested_measurements
)
{
    NRPPA_PDU_t pdu;
    static uint32_t transaction_id_counter = 1;
    uint32_t transaction_id;
    E_CIDMeasurementInitiationRequest_IEs_t *ecid_ie = NULL;
    int rv;
    ogs_pkbuf_t *pkbuf = NULL;

    log_info("Building NRPPa ECID request (v19.1.0 ProtocolIE format): "
             "measurement_id=%u, requested=0x%02x",
             measurement_id, requested_measurements);
    
    /* Log requested measurement types */
    if (requested_measurements & NRPPA_ECID_MEASUREMENT_TYPE_RSRP) {
        log_debug("  Requesting: SS-RSRP");
    }
    if (requested_measurements & NRPPA_ECID_MEASUREMENT_TYPE_TA) {
        log_debug("  Requesting: NR Timing Advance");
    }
    if (requested_measurements & NRPPA_ECID_MEASUREMENT_TYPE_AOA) {
        log_info("  Requesting: Angle of Arrival (requires UE SRS and gNB antenna array)");
        log_info("    Note: AoA may not be returned if UE doesn't support SRS");
        log_info("    Note: AoA requires specific gNB antenna configuration (array)");
        log_info("    Note: Per TS 38.455 §9.2.38, Azimuth+Zenith always reported when AoA present");
    }

    transaction_id = (int64_t)transaction_id_counter++;
    if (transaction_id_counter == 0)
        transaction_id_counter = 1;

    memset(&pdu, 0, sizeof(pdu));

    pdu.present = NRPPA_PDU_PR_initiatingMessage;
    pdu.choice.initiatingMessage = CALLOC(1, sizeof(InitiatingMessage_t));
    assert(NULL != pdu.choice.initiatingMessage);

    pdu.choice.initiatingMessage->criticality = Criticality_reject;
    pdu.choice.initiatingMessage->nrppatransactionID = (NRPPATransactionID_t)transaction_id;
    pdu.choice.initiatingMessage->procedureCode = ProcedureCode_id_e_CIDMeasurementInitiation;
    pdu.choice.initiatingMessage->value.present = InitiatingMessage__value_PR_E_CIDMeasurementInitiationRequest;
    pdu.choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest = CALLOC(1, sizeof(E_CIDMeasurementInitiationRequest_t));
    assert(NULL != pdu.choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest);

    pdu.choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest->protocolIEs = CALLOC(1, sizeof(ProtocolIE_Container_97P9_t));
    assert(NULL != pdu.choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest->protocolIEs);
    ProtocolIE_Container_97P9_t *ecid_ie_list = (ProtocolIE_Container_97P9_t*)pdu.choice.initiatingMessage->value.choice.E_CIDMeasurementInitiationRequest->protocolIEs;

    /* E-CID IE 1: id-LMF-UE-Measurement-ID (Mandatory) */
    ecid_ie = CALLOC(1, sizeof(E_CIDMeasurementInitiationRequest_IEs_t));
    assert(ecid_ie != NULL);
    ecid_ie->id = ProtocolIE_ID_id_LMF_UE_Measurement_ID;
    ecid_ie->criticality = Criticality_reject;
    ecid_ie->value.present = E_CIDMeasurementInitiationRequest_IEs__value_PR_UE_Measurement_ID;
    ecid_ie->value.choice.UE_Measurement_ID = CALLOC(1, sizeof(UE_Measurement_ID_t));
    assert(NULL != ecid_ie->value.choice.UE_Measurement_ID);
    *ecid_ie->value.choice.UE_Measurement_ID = (UE_Measurement_ID_t)measurement_id;
    rv = ASN_SEQUENCE_ADD(ecid_ie_list, ecid_ie);
    if (rv != 0) {
        log_error("ASN_SEQUENCE_ADD() failed [error_code: %d]", rv);
        goto end;
    }

    /* E-CID IE 2: id-ReportCharacteristics (Mandatory) */
    ecid_ie = CALLOC(1, sizeof(E_CIDMeasurementInitiationRequest_IEs_t));
    assert(ecid_ie != NULL);
    ecid_ie->id = ProtocolIE_ID_id_ReportCharacteristics;
    ecid_ie->criticality = Criticality_reject;
    ecid_ie->value.present = E_CIDMeasurementInitiationRequest_IEs__value_PR_ReportCharacteristics;
    ecid_ie->value.choice.ReportCharacteristics = CALLOC(1, sizeof(ReportCharacteristics_t));
    assert(NULL != ecid_ie->value.choice.ReportCharacteristics);
    *ecid_ie->value.choice.ReportCharacteristics = (ReportCharacteristics_t)ReportCharacteristics_onDemand;
    rv = ASN_SEQUENCE_ADD(ecid_ie_list, ecid_ie);
    if (rv != 0) {
        log_error("ASN_SEQUENCE_ADD() failed [error_code: %d]", rv);
        goto end;
    }

    /* E-CID IE 3: id-MeasurementQuantities (Mandatory) */
    ecid_ie = CALLOC(1, sizeof(*ecid_ie));
    assert(ecid_ie != NULL);
    ecid_ie->id = ProtocolIE_ID_id_MeasurementQuantities;
    ecid_ie->criticality = Criticality_reject;
    ecid_ie->value.present = E_CIDMeasurementInitiationRequest_IEs__value_PR_MeasurementQuantities;
    ecid_ie->value.choice.MeasurementQuantities = CALLOC(1, sizeof(MeasurementQuantities_t));
    assert(NULL != ecid_ie->value.choice.MeasurementQuantities);

    /* Iterate over and add the requested measurement IEs to ecid_ie->value.choice.MeasurementQuantities */
    e_MeasurementQuantitiesValue supported_measurement_ies[] = {
        MeasurementQuantitiesValue_cell_ID,
        MeasurementQuantitiesValue_angleOfArrival,
        MeasurementQuantitiesValue_timingAdvanceType1,
        MeasurementQuantitiesValue_timingAdvanceType2,
        MeasurementQuantitiesValue_rSRP,
        MeasurementQuantitiesValue_rSRQ,
        MeasurementQuantitiesValue_sS_RSRP,
        MeasurementQuantitiesValue_sS_RSRQ,
        MeasurementQuantitiesValue_cSI_RSRP,
        MeasurementQuantitiesValue_cSI_RSRQ,
        MeasurementQuantitiesValue_angleOfArrivalNR,
        MeasurementQuantitiesValue_timingAdvanceNR,
        MeasurementQuantitiesValue_uE_Rx_Tx_Time_Diff,
        MeasurementQuantitiesValue_angleOfArrivalNR_per_TRP
    };
    size_t i;
    MeasurementQuantities_ItemIEs_t *quantity_ie = NULL;
    size_t num_supported_measurement_ies = sizeof(supported_measurement_ies) / sizeof(supported_measurement_ies[0]);
    for (i = 0; i < num_supported_measurement_ies; i++) {
        if (requested_measurements & (0b0000000000000001 << i)) {
            /* Create MeasurementQuantities_Item */
            quantity_ie = CALLOC(1, sizeof(MeasurementQuantities_ItemIEs_t));
            assert(quantity_ie != NULL);
            quantity_ie->id = ProtocolIE_ID_id_MeasurementQuantities_Item;
            quantity_ie->criticality = Criticality_reject;
            quantity_ie->value.present = MeasurementQuantities_ItemIEs__value_PR_MeasurementQuantities_Item;
            quantity_ie->value.choice.MeasurementQuantities_Item = CALLOC(1, sizeof(MeasurementQuantities_Item_t));
            assert(NULL != quantity_ie->value.choice.MeasurementQuantities_Item);
            quantity_ie->value.choice.MeasurementQuantities_Item->measurementQuantitiesValue = (MeasurementQuantitiesValue_t)supported_measurement_ies[i];

            /* Add to list of requested MeasurementQuantities */
            rv = ASN_SEQUENCE_ADD(&ecid_ie->value.choice.MeasurementQuantities->list, quantity_ie);
            if (rv != 0) {
                log_error("ASN_SEQUENCE_ADD() failed [error_code: %d]", rv);
                goto end;
            }
        }
    }

    rv = ASN_SEQUENCE_ADD(ecid_ie_list, ecid_ie);
    if (rv != 0) {
        log_error("ASN_SEQUENCE_ADD() failed [error_code: %d]", rv);
        goto end;
    }

    pkbuf = encode_nrppa_pdu(&pdu);

end:
    ASN_STRUCT_FREE_CONTENTS_ONLY(asn_DEF_NRPPA_PDU, &pdu);
    return pkbuf;
}
