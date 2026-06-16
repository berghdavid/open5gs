/*
 * ecgi.h
 *
 * Contains the ECGI (E-UTRAN Cell Global Identity), as described in 3GPP 23.003
 */

#ifndef _ecgi_H_
#define _ecgi_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ecgi_t ecgi_t;

#include "plmn_id.h"



typedef struct ecgi_t {
    struct plmn_id_t *plmn_id; //model
    char *eutra_cell_id; // string
    char *nid; // string

    int _library_owned; // Is the library responsible for freeing this object?
} ecgi_t;

__attribute__((deprecated)) ecgi_t *ecgi_create(
    plmn_id_t *plmn_id,
    char *eutra_cell_id,
    char *nid
);

void ecgi_free(ecgi_t *ecgi);

ecgi_t *ecgi_parseFromJSON(cJSON *ecgiJSON);

cJSON *ecgi_convertToJSON(ecgi_t *ecgi);

#endif /* _ecgi_H_ */

