#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_location_service_ind.h"



static ue_location_service_ind_t *ue_location_service_ind_create_internal(
    ) {
    ue_location_service_ind_t *ue_location_service_ind_local_var = malloc(sizeof(ue_location_service_ind_t));
    if (!ue_location_service_ind_local_var) {
        return NULL;
    }
    memset(ue_location_service_ind_local_var, 0, sizeof(ue_location_service_ind_t));
    ue_location_service_ind_local_var->_library_owned = 1;
    return ue_location_service_ind_local_var;
}

__attribute__((deprecated)) ue_location_service_ind_t *ue_location_service_ind_create(
    ) {
    ue_location_service_ind_t *result = ue_location_service_ind_create_internal (
        );
    if (!result) {
    }
    return result;
}

void ue_location_service_ind_free(ue_location_service_ind_t *ue_location_service_ind) {
    if(NULL == ue_location_service_ind){
        return ;
    }
    if(ue_location_service_ind->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ue_location_service_ind_free");
        return ;
    }
    listEntry_t *listEntry;
    free(ue_location_service_ind);
}

cJSON *ue_location_service_ind_convertToJSON(ue_location_service_ind_t *ue_location_service_ind) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ue_location_service_ind_t *ue_location_service_ind_parseFromJSON(cJSON *ue_location_service_indJSON){

    ue_location_service_ind_t *ue_location_service_ind_local_var = NULL;



    ue_location_service_ind_local_var = ue_location_service_ind_create_internal (
        );

    if (!ue_location_service_ind_local_var) {
        goto end;
    }

    return ue_location_service_ind_local_var;
end:
    return NULL;

}
