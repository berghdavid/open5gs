/*
 * ciphering_key_info.h
 *
 * Information within Ciphering Key Data Notification request.
 */

#ifndef _ciphering_key_info_H_
#define _ciphering_key_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ciphering_key_info_t ciphering_key_info_t;

#include "ciphering_data_set.h"



typedef struct ciphering_key_info_t {
    list_t *ciphering_data; //nonprimitive container
    char *supported_features; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ciphering_key_info_t;

__attribute__((deprecated)) ciphering_key_info_t *ciphering_key_info_create(
    list_t *ciphering_data,
    char *supported_features
);

void ciphering_key_info_free(ciphering_key_info_t *ciphering_key_info);

ciphering_key_info_t *ciphering_key_info_parseFromJSON(cJSON *ciphering_key_infoJSON);

cJSON *ciphering_key_info_convertToJSON(ciphering_key_info_t *ciphering_key_info);

#endif /* _ciphering_key_info_H_ */

