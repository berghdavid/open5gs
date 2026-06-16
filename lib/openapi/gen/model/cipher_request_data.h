/*
 * cipher_request_data.h
 *
 * Information within Ciphering Key Data request.
 */

#ifndef _OpenAPI_cipher_request_data_H_
#define _OpenAPI_cipher_request_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_cipher_request_data_s OpenAPI_cipher_request_data_t;
typedef struct OpenAPI_cipher_request_data_s {
    char *amf_call_back_uri;
    char *supported_features;
} OpenAPI_cipher_request_data_t;

OpenAPI_cipher_request_data_t *OpenAPI_cipher_request_data_create(
    char *amf_call_back_uri,
    char *supported_features
);
void OpenAPI_cipher_request_data_free(OpenAPI_cipher_request_data_t *cipher_request_data);
OpenAPI_cipher_request_data_t *OpenAPI_cipher_request_data_parseFromJSON(cJSON *cipher_request_dataJSON);
cJSON *OpenAPI_cipher_request_data_convertToJSON(OpenAPI_cipher_request_data_t *cipher_request_data);
OpenAPI_cipher_request_data_t *OpenAPI_cipher_request_data_copy(OpenAPI_cipher_request_data_t *dst, OpenAPI_cipher_request_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_cipher_request_data_H_ */

