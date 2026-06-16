/*
 * no_profile_match_info.h
 *
 * Provides the reason for not finding NF matching the search criteria
 */

#ifndef _no_profile_match_info_H_
#define _no_profile_match_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct no_profile_match_info_t no_profile_match_info_t;

#include "no_profile_match_reason.h"
#include "query_param_combination.h"



typedef struct no_profile_match_info_t {
    struct no_profile_match_reason_t *reason; //model
    list_t *query_param_combination_list; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} no_profile_match_info_t;

__attribute__((deprecated)) no_profile_match_info_t *no_profile_match_info_create(
    no_profile_match_reason_t *reason,
    list_t *query_param_combination_list
);

void no_profile_match_info_free(no_profile_match_info_t *no_profile_match_info);

no_profile_match_info_t *no_profile_match_info_parseFromJSON(cJSON *no_profile_match_infoJSON);

cJSON *no_profile_match_info_convertToJSON(no_profile_match_info_t *no_profile_match_info);

#endif /* _no_profile_match_info_H_ */

