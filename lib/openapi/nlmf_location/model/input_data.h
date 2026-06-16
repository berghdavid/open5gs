/*
 * input_data.h
 *
 * Information within Determine Location Request.
 */

#ifndef _input_data_H_
#define _input_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct input_data_t input_data_t;

#include "additional_ue_info.h"
#include "area_event_info.h"
#include "ecgi.h"
#include "external_client_type.h"
#include "integrity_requirements.h"
#include "lcs_broadcast_assistance_types_data.h"
#include "lcs_priority.h"
#include "ldr_type.h"
#include "location_qo_s.h"
#include "lp_hap_type.h"
#include "mapped_location_qo_s_eps.h"
#include "mbsr_info.h"
#include "motion_event_info.h"
#include "ncgi.h"
#include "periodic_event_info.h"
#include "ranging_sl_result.h"
#include "ref_to_binary_data.h"
#include "related_ue.h"
#include "reporting_access_type.h"
#include "reporting_area.h"
#include "reporting_ind.h"
#include "sl_positioning_capability.h"
#include "supported_gad_shapes.h"
#include "tnap_id.h"
#include "twap_id.h"
#include "ue_connectivity_state.h"
#include "ue_lcs_capability.h"
#include "ue_location_service_ind.h"
#include "ue_up_positioning_capabilities.h"
#include "up_cum_evt_rpt_criteria.h"
#include "up_loc_rep_addr_af.h"
#include "velocity_requested.h"



typedef struct input_data_t {
    struct external_client_type_t *external_client_type; //model
    char *correlation_id; // string
    char *amf_id; // string
    struct location_qo_s_t *location_qo_s; //model
    list_t *supported_gad_shapes; //nonprimitive container
    char *supi; // string
    char *pei; // string
    char *gpsi; // string
    list_t *requested_ranging_sl_result; //nonprimitive container
    list_t *related_ues; //nonprimitive container
    struct ecgi_t *ecgi; //model
    struct ecgi_t *ecgi_on_second_node; //model
    struct ncgi_t *ncgi; //model
    struct ncgi_t *ncgi_on_second_node; //model
    struct lcs_priority_t *priority; //model
    struct velocity_requested_t *velocity_requested; //model
    struct ue_lcs_capability_t *ue_lcs_cap; //model
    int *lcs_service_type; //numeric
    struct ldr_type_t *ldr_type; //model
    char *hgmlc_call_back_uri; // string
    char *lir_gmlc_call_back_uri; // string
    char *vgmlc_address; // string
    char *ldr_reference; // string
    char *lir_reference; // string
    struct periodic_event_info_t *periodic_event_info; //model
    struct area_event_info_t *area_event_info; //model
    struct motion_event_info_t *motion_event_info; //model
    list_t *reporting_access_types; //nonprimitive container
    struct ue_connectivity_state_t *ue_connectivity_states; //model
    struct ue_location_service_ind_t *ue_location_service_ind; //model
    struct lcs_broadcast_assistance_types_data_t *mo_assistance_data_types; //model
    struct ref_to_binary_data_t *lpp_message; //model
    list_t *lpp_message_ext; //nonprimitive container
    char *supported_features; // string
    char *ue_positioning_cap; //ByteArray
    struct tnap_id_t *tnap_id; //model
    struct twap_id_t *twap_id; //model
    int *ue_country_det_ind; //boolean
    char *scheduled_loc_time; //date time
    int *reliable_loc_req; //boolean
    list_t *evt_rpt_allowed_areas; //nonprimitive container
    int *ue_unaware_ind; //boolean
    int *intermediate_location_ind; //boolean
    int *max_resp_time; //numeric
    struct lp_hap_type_t *lp_hap_type; //model
    list_t *ue_up_pos_caps; //nonprimitive container
    struct reporting_ind_t *reporting_ind; //model
    struct mbsr_info_t *mbsr_info; //model
    int *mwab_support_ind; //boolean
    struct integrity_requirements_t *integrity_requirements; //model
    struct up_loc_rep_addr_af_t *up_loc_rep_addr_af; //model
    struct up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria; //model
    struct mapped_location_qo_s_eps_t *mapped_qo_s_eps; //model
    struct additional_ue_info_t *additional_ue_info; //model
    int *coordinate_id; //numeric
    char *ranging_sl_capability; //ByteArray
    list_t *sl_positioning_capabilities; //nonprimitive container
    int *extended_facility_ind; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} input_data_t;

__attribute__((deprecated)) input_data_t *input_data_create(
    external_client_type_t *external_client_type,
    char *correlation_id,
    char *amf_id,
    location_qo_s_t *location_qo_s,
    list_t *supported_gad_shapes,
    char *supi,
    char *pei,
    char *gpsi,
    list_t *requested_ranging_sl_result,
    list_t *related_ues,
    ecgi_t *ecgi,
    ecgi_t *ecgi_on_second_node,
    ncgi_t *ncgi,
    ncgi_t *ncgi_on_second_node,
    lcs_priority_t *priority,
    velocity_requested_t *velocity_requested,
    ue_lcs_capability_t *ue_lcs_cap,
    int *lcs_service_type,
    ldr_type_t *ldr_type,
    char *hgmlc_call_back_uri,
    char *lir_gmlc_call_back_uri,
    char *vgmlc_address,
    char *ldr_reference,
    char *lir_reference,
    periodic_event_info_t *periodic_event_info,
    area_event_info_t *area_event_info,
    motion_event_info_t *motion_event_info,
    list_t *reporting_access_types,
    ue_connectivity_state_t *ue_connectivity_states,
    ue_location_service_ind_t *ue_location_service_ind,
    lcs_broadcast_assistance_types_data_t *mo_assistance_data_types,
    ref_to_binary_data_t *lpp_message,
    list_t *lpp_message_ext,
    char *supported_features,
    char *ue_positioning_cap,
    tnap_id_t *tnap_id,
    twap_id_t *twap_id,
    int *ue_country_det_ind,
    char *scheduled_loc_time,
    int *reliable_loc_req,
    list_t *evt_rpt_allowed_areas,
    int *ue_unaware_ind,
    int *intermediate_location_ind,
    int *max_resp_time,
    lp_hap_type_t *lp_hap_type,
    list_t *ue_up_pos_caps,
    reporting_ind_t *reporting_ind,
    mbsr_info_t *mbsr_info,
    int *mwab_support_ind,
    integrity_requirements_t *integrity_requirements,
    up_loc_rep_addr_af_t *up_loc_rep_addr_af,
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria,
    mapped_location_qo_s_eps_t *mapped_qo_s_eps,
    additional_ue_info_t *additional_ue_info,
    int *coordinate_id,
    char *ranging_sl_capability,
    list_t *sl_positioning_capabilities,
    int *extended_facility_ind
);

void input_data_free(input_data_t *input_data);

input_data_t *input_data_parseFromJSON(cJSON *input_dataJSON);

cJSON *input_data_convertToJSON(input_data_t *input_data);

#endif /* _input_data_H_ */

