/*
 * indoor_outdoor_ind.h
 *
 * Specifies UE location indoor or outdoor.
 */

#ifndef _OpenAPI_indoor_outdoor_ind_H_
#define _OpenAPI_indoor_outdoor_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_indoor_outdoor_ind_s OpenAPI_indoor_outdoor_ind_t;
typedef struct OpenAPI_indoor_outdoor_ind_s {
} OpenAPI_indoor_outdoor_ind_t;

OpenAPI_indoor_outdoor_ind_t *OpenAPI_indoor_outdoor_ind_create(
);
void OpenAPI_indoor_outdoor_ind_free(OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind);
OpenAPI_indoor_outdoor_ind_t *OpenAPI_indoor_outdoor_ind_parseFromJSON(cJSON *indoor_outdoor_indJSON);
cJSON *OpenAPI_indoor_outdoor_ind_convertToJSON(OpenAPI_indoor_outdoor_ind_t *indoor_outdoor_ind);
OpenAPI_indoor_outdoor_ind_t *OpenAPI_indoor_outdoor_ind_copy(OpenAPI_indoor_outdoor_ind_t *dst, OpenAPI_indoor_outdoor_ind_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_indoor_outdoor_ind_H_ */

