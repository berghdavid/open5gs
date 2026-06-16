/*
 * ue_up_positioning_capabilities.h
 *
 * User plane positioning capabilities supported by the UE.
 */

#ifndef _ue_up_positioning_capabilities_H_
#define _ue_up_positioning_capabilities_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ue_up_positioning_capabilities_t ue_up_positioning_capabilities_t;




typedef struct ue_up_positioning_capabilities_t {

    int _library_owned; // Is the library responsible for freeing this object?
} ue_up_positioning_capabilities_t;

__attribute__((deprecated)) ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_create(
);

void ue_up_positioning_capabilities_free(ue_up_positioning_capabilities_t *ue_up_positioning_capabilities);

ue_up_positioning_capabilities_t *ue_up_positioning_capabilities_parseFromJSON(cJSON *ue_up_positioning_capabilitiesJSON);

cJSON *ue_up_positioning_capabilities_convertToJSON(ue_up_positioning_capabilities_t *ue_up_positioning_capabilities);

#endif /* _ue_up_positioning_capabilities_H_ */

