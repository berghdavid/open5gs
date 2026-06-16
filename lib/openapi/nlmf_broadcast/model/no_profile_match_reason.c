#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "no_profile_match_reason.h"



static no_profile_match_reason_t *no_profile_match_reason_create_internal(
    ) {
    no_profile_match_reason_t *no_profile_match_reason_local_var = malloc(sizeof(no_profile_match_reason_t));
    if (!no_profile_match_reason_local_var) {
        return NULL;
    }
    memset(no_profile_match_reason_local_var, 0, sizeof(no_profile_match_reason_t));
    no_profile_match_reason_local_var->_library_owned = 1;
    return no_profile_match_reason_local_var;
}

__attribute__((deprecated)) no_profile_match_reason_t *no_profile_match_reason_create(
    ) {
    no_profile_match_reason_t *result = no_profile_match_reason_create_internal (
        );
    if (!result) {
    }
    return result;
}

void no_profile_match_reason_free(no_profile_match_reason_t *no_profile_match_reason) {
    if(NULL == no_profile_match_reason){
        return ;
    }
    if(no_profile_match_reason->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "no_profile_match_reason_free");
        return ;
    }
    listEntry_t *listEntry;
    free(no_profile_match_reason);
}

cJSON *no_profile_match_reason_convertToJSON(no_profile_match_reason_t *no_profile_match_reason) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

no_profile_match_reason_t *no_profile_match_reason_parseFromJSON(cJSON *no_profile_match_reasonJSON){

    no_profile_match_reason_t *no_profile_match_reason_local_var = NULL;



    no_profile_match_reason_local_var = no_profile_match_reason_create_internal (
        );

    if (!no_profile_match_reason_local_var) {
        goto end;
    }

    return no_profile_match_reason_local_var;
end:
    return NULL;

}
