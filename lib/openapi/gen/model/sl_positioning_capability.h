/*
 * sl_positioning_capability.h
 *
 * The Ranging and sidelink positioning capabilities supported by the UE.
 */

#ifndef _OpenAPI_sl_positioning_capability_H_
#define _OpenAPI_sl_positioning_capability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_sl_positioning_capability_s OpenAPI_sl_positioning_capability_t;
typedef struct OpenAPI_sl_positioning_capability_s {
} OpenAPI_sl_positioning_capability_t;

OpenAPI_sl_positioning_capability_t *OpenAPI_sl_positioning_capability_create(
);
void OpenAPI_sl_positioning_capability_free(OpenAPI_sl_positioning_capability_t *sl_positioning_capability);
OpenAPI_sl_positioning_capability_t *OpenAPI_sl_positioning_capability_parseFromJSON(cJSON *sl_positioning_capabilityJSON);
cJSON *OpenAPI_sl_positioning_capability_convertToJSON(OpenAPI_sl_positioning_capability_t *sl_positioning_capability);
OpenAPI_sl_positioning_capability_t *OpenAPI_sl_positioning_capability_copy(OpenAPI_sl_positioning_capability_t *dst, OpenAPI_sl_positioning_capability_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_sl_positioning_capability_H_ */

