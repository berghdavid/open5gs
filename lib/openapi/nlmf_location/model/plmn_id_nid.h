/*
 * plmn_id_nid.h
 *
 * Contains the serving core network operator PLMN ID and, for an SNPN, the NID that together with the PLMN ID identifies the SNPN. 
 */

#ifndef _plmn_id_nid_H_
#define _plmn_id_nid_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct plmn_id_nid_t plmn_id_nid_t;




typedef struct plmn_id_nid_t {
    char *mcc; // string
    char *mnc; // string
    char *nid; // string

    int _library_owned; // Is the library responsible for freeing this object?
} plmn_id_nid_t;

__attribute__((deprecated)) plmn_id_nid_t *plmn_id_nid_create(
    char *mcc,
    char *mnc,
    char *nid
);

void plmn_id_nid_free(plmn_id_nid_t *plmn_id_nid);

plmn_id_nid_t *plmn_id_nid_parseFromJSON(cJSON *plmn_id_nidJSON);

cJSON *plmn_id_nid_convertToJSON(plmn_id_nid_t *plmn_id_nid);

#endif /* _plmn_id_nid_H_ */

