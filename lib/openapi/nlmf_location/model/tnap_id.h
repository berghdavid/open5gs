/*
 * tnap_id.h
 *
 * Contain the TNAP Identifier see clause5.6.2 of 3GPP TS 23.501.
 */

#ifndef _tnap_id_H_
#define _tnap_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct tnap_id_t tnap_id_t;




typedef struct tnap_id_t {
    char *ss_id; // string
    char *bss_id; // string
    char *civic_address; //ByteArray

    int _library_owned; // Is the library responsible for freeing this object?
} tnap_id_t;

__attribute__((deprecated)) tnap_id_t *tnap_id_create(
    char *ss_id,
    char *bss_id,
    char *civic_address
);

void tnap_id_free(tnap_id_t *tnap_id);

tnap_id_t *tnap_id_parseFromJSON(cJSON *tnap_idJSON);

cJSON *tnap_id_convertToJSON(tnap_id_t *tnap_id);

#endif /* _tnap_id_H_ */

