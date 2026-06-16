/*
 * additional_ue_info.h
 *
 * MBSR UE or MWAB UE Information
 */

#ifndef _additional_ue_info_H_
#define _additional_ue_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct additional_ue_info_t additional_ue_info_t;

#include "ncgi.h"
#include "tai.h"



typedef struct additional_ue_info_t {
    struct ncgi_t *ncgi; //model
    struct tai_t *tai; //model

    int _library_owned; // Is the library responsible for freeing this object?
} additional_ue_info_t;

__attribute__((deprecated)) additional_ue_info_t *additional_ue_info_create(
    ncgi_t *ncgi,
    tai_t *tai
);

void additional_ue_info_free(additional_ue_info_t *additional_ue_info);

additional_ue_info_t *additional_ue_info_parseFromJSON(cJSON *additional_ue_infoJSON);

cJSON *additional_ue_info_convertToJSON(additional_ue_info_t *additional_ue_info);

#endif /* _additional_ue_info_H_ */

