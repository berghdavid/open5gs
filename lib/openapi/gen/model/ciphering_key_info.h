/*
 * ciphering_key_info.h
 *
 * Information within Ciphering Key Data Notification request.
 */

#ifndef _OpenAPI_ciphering_key_info_H_
#define _OpenAPI_ciphering_key_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "ciphering_data_set.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_ciphering_key_info_s OpenAPI_ciphering_key_info_t;
typedef struct OpenAPI_ciphering_key_info_s {
    OpenAPI_list_t *ciphering_data;
    char *supported_features;
} OpenAPI_ciphering_key_info_t;

OpenAPI_ciphering_key_info_t *OpenAPI_ciphering_key_info_create(
    OpenAPI_list_t *ciphering_data,
    char *supported_features
);
void OpenAPI_ciphering_key_info_free(OpenAPI_ciphering_key_info_t *ciphering_key_info);
OpenAPI_ciphering_key_info_t *OpenAPI_ciphering_key_info_parseFromJSON(cJSON *ciphering_key_infoJSON);
cJSON *OpenAPI_ciphering_key_info_convertToJSON(OpenAPI_ciphering_key_info_t *ciphering_key_info);
OpenAPI_ciphering_key_info_t *OpenAPI_ciphering_key_info_copy(OpenAPI_ciphering_key_info_t *dst, OpenAPI_ciphering_key_info_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_ciphering_key_info_H_ */

