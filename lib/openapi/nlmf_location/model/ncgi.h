/*
 * ncgi.h
 *
 * Contains the NCGI (NR Cell Global Identity), as described in 3GPP 23.003
 */

#ifndef _ncgi_H_
#define _ncgi_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ncgi_t ncgi_t;

#include "plmn_id.h"



typedef struct ncgi_t {
    struct plmn_id_t *plmn_id; //model
    char *nr_cell_id; // string
    char *nid; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ncgi_t;

__attribute__((deprecated)) ncgi_t *ncgi_create(
    plmn_id_t *plmn_id,
    char *nr_cell_id,
    char *nid
);

void ncgi_free(ncgi_t *ncgi);

ncgi_t *ncgi_parseFromJSON(cJSON *ncgiJSON);

cJSON *ncgi_convertToJSON(ncgi_t *ncgi);

#endif /* _ncgi_H_ */

