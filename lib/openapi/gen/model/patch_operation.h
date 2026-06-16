/*
 * patch_operation.h
 *
 * Operations as defined in IETF RFC 6902.
 */

#ifndef _OpenAPI_patch_operation_H_
#define _OpenAPI_patch_operation_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_patch_operation_s OpenAPI_patch_operation_t;
typedef struct OpenAPI_patch_operation_s {
} OpenAPI_patch_operation_t;

OpenAPI_patch_operation_t *OpenAPI_patch_operation_create(
);
void OpenAPI_patch_operation_free(OpenAPI_patch_operation_t *patch_operation);
OpenAPI_patch_operation_t *OpenAPI_patch_operation_parseFromJSON(cJSON *patch_operationJSON);
cJSON *OpenAPI_patch_operation_convertToJSON(OpenAPI_patch_operation_t *patch_operation);
OpenAPI_patch_operation_t *OpenAPI_patch_operation_copy(OpenAPI_patch_operation_t *dst, OpenAPI_patch_operation_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_patch_operation_H_ */

