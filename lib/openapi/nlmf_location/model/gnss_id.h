/*
 * gnss_id.h
 *
 * Global Navigation Satellite System (GNSS) ID.
 */

#ifndef _gnss_id_H_
#define _gnss_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gnss_id_t gnss_id_t;




typedef struct gnss_id_t {

    int _library_owned; // Is the library responsible for freeing this object?
} gnss_id_t;

__attribute__((deprecated)) gnss_id_t *gnss_id_create(
);

void gnss_id_free(gnss_id_t *gnss_id);

gnss_id_t *gnss_id_parseFromJSON(cJSON *gnss_idJSON);

cJSON *gnss_id_convertToJSON(gnss_id_t *gnss_id);

#endif /* _gnss_id_H_ */

