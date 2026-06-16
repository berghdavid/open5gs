#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "los_nlos_measure_ind.h"



static los_nlos_measure_ind_t *los_nlos_measure_ind_create_internal(
    ) {
    los_nlos_measure_ind_t *los_nlos_measure_ind_local_var = malloc(sizeof(los_nlos_measure_ind_t));
    if (!los_nlos_measure_ind_local_var) {
        return NULL;
    }
    memset(los_nlos_measure_ind_local_var, 0, sizeof(los_nlos_measure_ind_t));
    los_nlos_measure_ind_local_var->_library_owned = 1;
    return los_nlos_measure_ind_local_var;
}

__attribute__((deprecated)) los_nlos_measure_ind_t *los_nlos_measure_ind_create(
    ) {
    los_nlos_measure_ind_t *result = los_nlos_measure_ind_create_internal (
        );
    if (!result) {
    }
    return result;
}

void los_nlos_measure_ind_free(los_nlos_measure_ind_t *los_nlos_measure_ind) {
    if(NULL == los_nlos_measure_ind){
        return ;
    }
    if(los_nlos_measure_ind->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "los_nlos_measure_ind_free");
        return ;
    }
    listEntry_t *listEntry;
    free(los_nlos_measure_ind);
}

cJSON *los_nlos_measure_ind_convertToJSON(los_nlos_measure_ind_t *los_nlos_measure_ind) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

los_nlos_measure_ind_t *los_nlos_measure_ind_parseFromJSON(cJSON *los_nlos_measure_indJSON){

    los_nlos_measure_ind_t *los_nlos_measure_ind_local_var = NULL;



    los_nlos_measure_ind_local_var = los_nlos_measure_ind_create_internal (
        );

    if (!los_nlos_measure_ind_local_var) {
        goto end;
    }

    return los_nlos_measure_ind_local_var;
end:
    return NULL;

}
