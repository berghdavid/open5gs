/*
 * ue_lcs_capability.h
 *
 * Indicates the LCS capability supported by the UE..
 */

#ifndef _ue_lcs_capability_H_
#define _ue_lcs_capability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ue_lcs_capability_t ue_lcs_capability_t;




typedef struct ue_lcs_capability_t {
    int *lpp_support; //boolean
    int *ciot_optimisation; //boolean

    int _library_owned; // Is the library responsible for freeing this object?
} ue_lcs_capability_t;

__attribute__((deprecated)) ue_lcs_capability_t *ue_lcs_capability_create(
    int *lpp_support,
    int *ciot_optimisation
);

void ue_lcs_capability_free(ue_lcs_capability_t *ue_lcs_capability);

ue_lcs_capability_t *ue_lcs_capability_parseFromJSON(cJSON *ue_lcs_capabilityJSON);

cJSON *ue_lcs_capability_convertToJSON(ue_lcs_capability_t *ue_lcs_capability);

#endif /* _ue_lcs_capability_H_ */

