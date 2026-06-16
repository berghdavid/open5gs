/*
 * up_connection_status.h
 *
 * UP Connection Status.
 */

#ifndef _up_connection_status_H_
#define _up_connection_status_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct up_connection_status_t up_connection_status_t;




typedef struct up_connection_status_t {

    int _library_owned; // Is the library responsible for freeing this object?
} up_connection_status_t;

__attribute__((deprecated)) up_connection_status_t *up_connection_status_create(
);

void up_connection_status_free(up_connection_status_t *up_connection_status);

up_connection_status_t *up_connection_status_parseFromJSON(cJSON *up_connection_statusJSON);

cJSON *up_connection_status_convertToJSON(up_connection_status_t *up_connection_status);

#endif /* _up_connection_status_H_ */

