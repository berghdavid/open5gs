/*
 * presence_state.h
 *
 * Possible values are: -IN_AREA: Indicates that the UE is inside or enters the presence reporting area. -OUT_OF_AREA: Indicates that the UE is outside or leaves the presence reporting area -UNKNOW: Indicates it is unknown whether the UE is in the presence reporting area or not -INACTIVE: Indicates that the presence reporting area is inactive in the serving node.  
 */

#ifndef _OpenAPI_presence_state_H_
#define _OpenAPI_presence_state_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_presence_state_s OpenAPI_presence_state_t;
typedef struct OpenAPI_presence_state_s {
} OpenAPI_presence_state_t;

OpenAPI_presence_state_t *OpenAPI_presence_state_create(
);
void OpenAPI_presence_state_free(OpenAPI_presence_state_t *presence_state);
OpenAPI_presence_state_t *OpenAPI_presence_state_parseFromJSON(cJSON *presence_stateJSON);
cJSON *OpenAPI_presence_state_convertToJSON(OpenAPI_presence_state_t *presence_state);
OpenAPI_presence_state_t *OpenAPI_presence_state_copy(OpenAPI_presence_state_t *dst, OpenAPI_presence_state_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_presence_state_H_ */

