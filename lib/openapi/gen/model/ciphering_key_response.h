/*
 * ciphering_key_response.h
 *
 * Information within Ciphering Key Data Notification Response.
 */

#ifndef _OpenAPI_ciphering_key_response_H_
#define _OpenAPI_ciphering_key_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ciphering_set_report.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_ciphering_key_response_s OpenAPI_ciphering_key_response_t;
typedef struct OpenAPI_ciphering_key_response_s {
    OpenAPI_list_t *ciphering_data_report;
} OpenAPI_ciphering_key_response_t;

OpenAPI_ciphering_key_response_t *OpenAPI_ciphering_key_response_create(
    OpenAPI_list_t *ciphering_data_report
);
void OpenAPI_ciphering_key_response_free(OpenAPI_ciphering_key_response_t *ciphering_key_response);
OpenAPI_ciphering_key_response_t *OpenAPI_ciphering_key_response_parseFromJSON(cJSON *ciphering_key_responseJSON);
cJSON *OpenAPI_ciphering_key_response_convertToJSON(OpenAPI_ciphering_key_response_t *ciphering_key_response);
OpenAPI_ciphering_key_response_t *OpenAPI_ciphering_key_response_copy(OpenAPI_ciphering_key_response_t *dst, OpenAPI_ciphering_key_response_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_ciphering_key_response_H_ */

