/*
 * fix_type.h
 *
 * Specifies the positioning fix type.
 */

#ifndef _OpenAPI_fix_type_H_
#define _OpenAPI_fix_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_fix_type_s OpenAPI_fix_type_t;
typedef struct OpenAPI_fix_type_s {
} OpenAPI_fix_type_t;

OpenAPI_fix_type_t *OpenAPI_fix_type_create(
);
void OpenAPI_fix_type_free(OpenAPI_fix_type_t *fix_type);
OpenAPI_fix_type_t *OpenAPI_fix_type_parseFromJSON(cJSON *fix_typeJSON);
cJSON *OpenAPI_fix_type_convertToJSON(OpenAPI_fix_type_t *fix_type);
OpenAPI_fix_type_t *OpenAPI_fix_type_copy(OpenAPI_fix_type_t *dst, OpenAPI_fix_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_fix_type_H_ */

