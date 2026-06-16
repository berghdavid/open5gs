/*
 * ue_up_positioning_capabilities.h
 *
 * User plane positioning capabilities supported by the UE.
 */

#ifndef _OpenAPI_ue_up_positioning_capabilities_H_
#define _OpenAPI_ue_up_positioning_capabilities_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_ue_up_positioning_capabilities_s OpenAPI_ue_up_positioning_capabilities_t;
typedef struct OpenAPI_ue_up_positioning_capabilities_s {
} OpenAPI_ue_up_positioning_capabilities_t;

OpenAPI_ue_up_positioning_capabilities_t *OpenAPI_ue_up_positioning_capabilities_create(
);
void OpenAPI_ue_up_positioning_capabilities_free(OpenAPI_ue_up_positioning_capabilities_t *ue_up_positioning_capabilities);
OpenAPI_ue_up_positioning_capabilities_t *OpenAPI_ue_up_positioning_capabilities_parseFromJSON(cJSON *ue_up_positioning_capabilitiesJSON);
cJSON *OpenAPI_ue_up_positioning_capabilities_convertToJSON(OpenAPI_ue_up_positioning_capabilities_t *ue_up_positioning_capabilities);
OpenAPI_ue_up_positioning_capabilities_t *OpenAPI_ue_up_positioning_capabilities_copy(OpenAPI_ue_up_positioning_capabilities_t *dst, OpenAPI_ue_up_positioning_capabilities_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_ue_up_positioning_capabilities_H_ */

