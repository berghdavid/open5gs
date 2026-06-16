#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_ind.h"



static reporting_ind_t *reporting_ind_create_internal(
    ) {
    reporting_ind_t *reporting_ind_local_var = malloc(sizeof(reporting_ind_t));
    if (!reporting_ind_local_var) {
        return NULL;
    }
    memset(reporting_ind_local_var, 0, sizeof(reporting_ind_t));
    reporting_ind_local_var->_library_owned = 1;
    return reporting_ind_local_var;
}

__attribute__((deprecated)) reporting_ind_t *reporting_ind_create(
    ) {
    reporting_ind_t *result = reporting_ind_create_internal (
        );
    if (!result) {
    }
    return result;
}

void reporting_ind_free(reporting_ind_t *reporting_ind) {
    if(NULL == reporting_ind){
        return ;
    }
    if(reporting_ind->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reporting_ind_free");
        return ;
    }
    listEntry_t *listEntry;
    free(reporting_ind);
}

cJSON *reporting_ind_convertToJSON(reporting_ind_t *reporting_ind) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reporting_ind_t *reporting_ind_parseFromJSON(cJSON *reporting_indJSON){

    reporting_ind_t *reporting_ind_local_var = NULL;



    reporting_ind_local_var = reporting_ind_create_internal (
        );

    if (!reporting_ind_local_var) {
        goto end;
    }

    return reporting_ind_local_var;
end:
    return NULL;

}
