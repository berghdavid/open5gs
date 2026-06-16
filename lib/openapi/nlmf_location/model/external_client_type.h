/*
 * external_client_type.h
 *
 * Indicates types of External Clients.
 */

#ifndef _external_client_type_H_
#define _external_client_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct external_client_type_t external_client_type_t;




typedef struct external_client_type_t {

    int _library_owned; // Is the library responsible for freeing this object?
} external_client_type_t;

__attribute__((deprecated)) external_client_type_t *external_client_type_create(
);

void external_client_type_free(external_client_type_t *external_client_type);

external_client_type_t *external_client_type_parseFromJSON(cJSON *external_client_typeJSON);

cJSON *external_client_type_convertToJSON(external_client_type_t *external_client_type);

#endif /* _external_client_type_H_ */

