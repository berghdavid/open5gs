#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "occurrence_info.h"



static occurrence_info_t *occurrence_info_create_internal(
    ) {
    occurrence_info_t *occurrence_info_local_var = malloc(sizeof(occurrence_info_t));
    if (!occurrence_info_local_var) {
        return NULL;
    }
    memset(occurrence_info_local_var, 0, sizeof(occurrence_info_t));
    occurrence_info_local_var->_library_owned = 1;
    return occurrence_info_local_var;
}

__attribute__((deprecated)) occurrence_info_t *occurrence_info_create(
    ) {
    occurrence_info_t *result = occurrence_info_create_internal (
        );
    if (!result) {
    }
    return result;
}

void occurrence_info_free(occurrence_info_t *occurrence_info) {
    if(NULL == occurrence_info){
        return ;
    }
    if(occurrence_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "occurrence_info_free");
        return ;
    }
    listEntry_t *listEntry;
    free(occurrence_info);
}

cJSON *occurrence_info_convertToJSON(occurrence_info_t *occurrence_info) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

occurrence_info_t *occurrence_info_parseFromJSON(cJSON *occurrence_infoJSON){

    occurrence_info_t *occurrence_info_local_var = NULL;



    occurrence_info_local_var = occurrence_info_create_internal (
        );

    if (!occurrence_info_local_var) {
        goto end;
    }

    return occurrence_info_local_var;
end:
    return NULL;

}
