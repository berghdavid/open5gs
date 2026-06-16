/*
 * ue_connectivity_state.h
 *
 * Indicates the connectivity state of a UE.
 */

#ifndef _ue_connectivity_state_H_
#define _ue_connectivity_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ue_connectivity_state_t ue_connectivity_state_t;

#include "access_type.h"
#include "cm_state.h"



typedef struct ue_connectivity_state_t {
    lmf_location_access_type__e access_type; //referenced enum
    struct cm_state_t *connectivitystate; //model

    int _library_owned; // Is the library responsible for freeing this object?
} ue_connectivity_state_t;

__attribute__((deprecated)) ue_connectivity_state_t *ue_connectivity_state_create(
    lmf_location_access_type__e access_type,
    cm_state_t *connectivitystate
);

void ue_connectivity_state_free(ue_connectivity_state_t *ue_connectivity_state);

ue_connectivity_state_t *ue_connectivity_state_parseFromJSON(cJSON *ue_connectivity_stateJSON);

cJSON *ue_connectivity_state_convertToJSON(ue_connectivity_state_t *ue_connectivity_state);

#endif /* _ue_connectivity_state_H_ */

