/*
 * related_ue_type.h
 *
 * Specifies the different roles of UE for ranging and sidelink positioning service.
 */

#ifndef _OpenAPI_related_ue_type_H_
#define _OpenAPI_related_ue_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_related_ue_type_s OpenAPI_related_ue_type_t;
typedef struct OpenAPI_related_ue_type_s {
} OpenAPI_related_ue_type_t;

OpenAPI_related_ue_type_t *OpenAPI_related_ue_type_create(
);
void OpenAPI_related_ue_type_free(OpenAPI_related_ue_type_t *related_ue_type);
OpenAPI_related_ue_type_t *OpenAPI_related_ue_type_parseFromJSON(cJSON *related_ue_typeJSON);
cJSON *OpenAPI_related_ue_type_convertToJSON(OpenAPI_related_ue_type_t *related_ue_type);
OpenAPI_related_ue_type_t *OpenAPI_related_ue_type_copy(OpenAPI_related_ue_type_t *dst, OpenAPI_related_ue_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_related_ue_type_H_ */

