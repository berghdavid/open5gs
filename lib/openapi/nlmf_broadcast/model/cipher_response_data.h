/*
 * cipher_response_data.h
 *
 * Information within Ciphering Key Data Response.
 */

#ifndef _cipher_response_data_H_
#define _cipher_response_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cipher_response_data_t cipher_response_data_t;

#include "data_availability.h"



typedef struct cipher_response_data_t {
    lmf_broadcast_data_availability__e data_availability; //referenced enum

    int _library_owned; // Is the library responsible for freeing this object?
} cipher_response_data_t;

__attribute__((deprecated)) cipher_response_data_t *cipher_response_data_create(
    lmf_broadcast_data_availability__e data_availability
);

void cipher_response_data_free(cipher_response_data_t *cipher_response_data);

cipher_response_data_t *cipher_response_data_parseFromJSON(cJSON *cipher_response_dataJSON);

cJSON *cipher_response_data_convertToJSON(cipher_response_data_t *cipher_response_data);

#endif /* _cipher_response_data_H_ */

