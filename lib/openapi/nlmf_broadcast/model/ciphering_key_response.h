/*
 * ciphering_key_response.h
 *
 * Information within Ciphering Key Data Notification Response.
 */

#ifndef _ciphering_key_response_H_
#define _ciphering_key_response_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ciphering_key_response_t ciphering_key_response_t;

#include "ciphering_set_report.h"



typedef struct ciphering_key_response_t {
    list_t *ciphering_data_report; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} ciphering_key_response_t;

__attribute__((deprecated)) ciphering_key_response_t *ciphering_key_response_create(
    list_t *ciphering_data_report
);

void ciphering_key_response_free(ciphering_key_response_t *ciphering_key_response);

ciphering_key_response_t *ciphering_key_response_parseFromJSON(cJSON *ciphering_key_responseJSON);

cJSON *ciphering_key_response_convertToJSON(ciphering_key_response_t *ciphering_key_response);

#endif /* _ciphering_key_response_H_ */

