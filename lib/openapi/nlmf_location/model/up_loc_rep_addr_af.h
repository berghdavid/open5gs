/*
 * up_loc_rep_addr_af.h
 *
 * Represents the user plane addressing information.
 */

#ifndef _up_loc_rep_addr_af_H_
#define _up_loc_rep_addr_af_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct up_loc_rep_addr_af_t up_loc_rep_addr_af_t;

#include "ipv6_addr.h"



typedef struct up_loc_rep_addr_af_t {
    list_t *ipv4_addrs; //primitive container
    list_t *ipv6_addrs; //nonprimitive container
    char *fqdn; // string

    int _library_owned; // Is the library responsible for freeing this object?
} up_loc_rep_addr_af_t;

__attribute__((deprecated)) up_loc_rep_addr_af_t *up_loc_rep_addr_af_create(
    list_t *ipv4_addrs,
    list_t *ipv6_addrs,
    char *fqdn
);

void up_loc_rep_addr_af_free(up_loc_rep_addr_af_t *up_loc_rep_addr_af);

up_loc_rep_addr_af_t *up_loc_rep_addr_af_parseFromJSON(cJSON *up_loc_rep_addr_afJSON);

cJSON *up_loc_rep_addr_af_convertToJSON(up_loc_rep_addr_af_t *up_loc_rep_addr_af);

#endif /* _up_loc_rep_addr_af_H_ */

