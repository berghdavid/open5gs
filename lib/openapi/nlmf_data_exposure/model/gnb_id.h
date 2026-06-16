/*
 * gnb_id.h
 *
 * Provides the G-NB identifier.
 */

#ifndef _gnb_id_H_
#define _gnb_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct gnb_id_t gnb_id_t;




typedef struct gnb_id_t {
    int *bit_length; //numeric
    char *g_nb_value; // string

    int _library_owned; // Is the library responsible for freeing this object?
} gnb_id_t;

__attribute__((deprecated)) gnb_id_t *gnb_id_create(
    int *bit_length,
    char *g_nb_value
);

void gnb_id_free(gnb_id_t *gnb_id);

gnb_id_t *gnb_id_parseFromJSON(cJSON *gnb_idJSON);

cJSON *gnb_id_convertToJSON(gnb_id_t *gnb_id);

#endif /* _gnb_id_H_ */

