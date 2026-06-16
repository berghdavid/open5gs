/*
 * mbsr_info.h
 *
 * MBSR Information
 */

#ifndef _mbsr_info_H_
#define _mbsr_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct mbsr_info_t mbsr_info_t;

#include "ecgi.h"
#include "ncgi.h"



typedef struct mbsr_info_t {
    struct ncgi_t *ncgi; //model
    struct ecgi_t *ecgi; //model

    int _library_owned; // Is the library responsible for freeing this object?
} mbsr_info_t;

__attribute__((deprecated)) mbsr_info_t *mbsr_info_create(
    ncgi_t *ncgi,
    ecgi_t *ecgi
);

void mbsr_info_free(mbsr_info_t *mbsr_info);

mbsr_info_t *mbsr_info_parseFromJSON(cJSON *mbsr_infoJSON);

cJSON *mbsr_info_convertToJSON(mbsr_info_t *mbsr_info);

#endif /* _mbsr_info_H_ */

