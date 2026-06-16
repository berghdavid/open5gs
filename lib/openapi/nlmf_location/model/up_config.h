/*
 * up_config.h
 *
 * UP Config
 */

#ifndef _up_config_H_
#define _up_config_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct up_config_t up_config_t;

#include "lcs_up_connection_ind.h"
#include "ue_up_positioning_capabilities.h"



typedef struct up_config_t {
    char *up_notify_call_back_uri; // string
    char *notif_correlation_id; // string
    char *supi; // string
    char *gpsi; // string
    int *amf_reallocation_ind; //boolean
    struct lcs_up_connection_ind_t *lcs_up_connection_ind; //model
    char *target_lmfid; // string
    list_t *ue_up_pos_caps; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} up_config_t;

__attribute__((deprecated)) up_config_t *up_config_create(
    char *up_notify_call_back_uri,
    char *notif_correlation_id,
    char *supi,
    char *gpsi,
    int *amf_reallocation_ind,
    lcs_up_connection_ind_t *lcs_up_connection_ind,
    char *target_lmfid,
    list_t *ue_up_pos_caps
);

void up_config_free(up_config_t *up_config);

up_config_t *up_config_parseFromJSON(cJSON *up_configJSON);

cJSON *up_config_convertToJSON(up_config_t *up_config);

#endif /* _up_config_H_ */

