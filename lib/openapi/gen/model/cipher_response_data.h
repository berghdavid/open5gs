/*
 * cipher_response_data.h
 *
 * Information within Ciphering Key Data Response.
 */

#ifndef _OpenAPI_cipher_response_data_H_
#define _OpenAPI_cipher_response_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"
#include "data_availability.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_cipher_response_data_s OpenAPI_cipher_response_data_t;
typedef struct OpenAPI_cipher_response_data_s {
    OpenAPI_data_availability_e data_availability;
} OpenAPI_cipher_response_data_t;

OpenAPI_cipher_response_data_t *OpenAPI_cipher_response_data_create(
    OpenAPI_data_availability_e data_availability
);
void OpenAPI_cipher_response_data_free(OpenAPI_cipher_response_data_t *cipher_response_data);
OpenAPI_cipher_response_data_t *OpenAPI_cipher_response_data_parseFromJSON(cJSON *cipher_response_dataJSON);
cJSON *OpenAPI_cipher_response_data_convertToJSON(OpenAPI_cipher_response_data_t *cipher_response_data);
OpenAPI_cipher_response_data_t *OpenAPI_cipher_response_data_copy(OpenAPI_cipher_response_data_t *dst, OpenAPI_cipher_response_data_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_cipher_response_data_H_ */

