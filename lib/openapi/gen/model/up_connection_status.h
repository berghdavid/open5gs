/*
 * up_connection_status.h
 *
 * UP Connection Status.
 */

#ifndef _OpenAPI_up_connection_status_H_
#define _OpenAPI_up_connection_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_up_connection_status_s OpenAPI_up_connection_status_t;
typedef struct OpenAPI_up_connection_status_s {
} OpenAPI_up_connection_status_t;

OpenAPI_up_connection_status_t *OpenAPI_up_connection_status_create(
);
void OpenAPI_up_connection_status_free(OpenAPI_up_connection_status_t *up_connection_status);
OpenAPI_up_connection_status_t *OpenAPI_up_connection_status_parseFromJSON(cJSON *up_connection_statusJSON);
cJSON *OpenAPI_up_connection_status_convertToJSON(OpenAPI_up_connection_status_t *up_connection_status);
OpenAPI_up_connection_status_t *OpenAPI_up_connection_status_copy(OpenAPI_up_connection_status_t *dst, OpenAPI_up_connection_status_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_up_connection_status_H_ */

