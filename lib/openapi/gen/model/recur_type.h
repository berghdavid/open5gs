/*
 * recur_type.h
 *
 * Indicates the recurrence applicable to a time window.
 */

#ifndef _OpenAPI_recur_type_H_
#define _OpenAPI_recur_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_recur_type_s OpenAPI_recur_type_t;
typedef struct OpenAPI_recur_type_s {
} OpenAPI_recur_type_t;

OpenAPI_recur_type_t *OpenAPI_recur_type_create(
);
void OpenAPI_recur_type_free(OpenAPI_recur_type_t *recur_type);
OpenAPI_recur_type_t *OpenAPI_recur_type_parseFromJSON(cJSON *recur_typeJSON);
cJSON *OpenAPI_recur_type_convertToJSON(OpenAPI_recur_type_t *recur_type);
OpenAPI_recur_type_t *OpenAPI_recur_type_copy(OpenAPI_recur_type_t *dst, OpenAPI_recur_type_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_recur_type_H_ */

