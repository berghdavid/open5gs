#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "indoor_outdoor_ind.h"



static indoor_outdoor_ind_t *indoor_outdoor_ind_create_internal(
    ) {
    indoor_outdoor_ind_t *indoor_outdoor_ind_local_var = malloc(sizeof(indoor_outdoor_ind_t));
    if (!indoor_outdoor_ind_local_var) {
        return NULL;
    }
    memset(indoor_outdoor_ind_local_var, 0, sizeof(indoor_outdoor_ind_t));
    indoor_outdoor_ind_local_var->_library_owned = 1;
    return indoor_outdoor_ind_local_var;
}

__attribute__((deprecated)) indoor_outdoor_ind_t *indoor_outdoor_ind_create(
    ) {
    indoor_outdoor_ind_t *result = indoor_outdoor_ind_create_internal (
        );
    if (!result) {
    }
    return result;
}

void indoor_outdoor_ind_free(indoor_outdoor_ind_t *indoor_outdoor_ind) {
    if(NULL == indoor_outdoor_ind){
        return ;
    }
    if(indoor_outdoor_ind->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "indoor_outdoor_ind_free");
        return ;
    }
    listEntry_t *listEntry;
    free(indoor_outdoor_ind);
}

cJSON *indoor_outdoor_ind_convertToJSON(indoor_outdoor_ind_t *indoor_outdoor_ind) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

indoor_outdoor_ind_t *indoor_outdoor_ind_parseFromJSON(cJSON *indoor_outdoor_indJSON){

    indoor_outdoor_ind_t *indoor_outdoor_ind_local_var = NULL;



    indoor_outdoor_ind_local_var = indoor_outdoor_ind_create_internal (
        );

    if (!indoor_outdoor_ind_local_var) {
        goto end;
    }

    return indoor_outdoor_ind_local_var;
end:
    return NULL;

}
