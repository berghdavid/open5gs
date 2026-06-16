#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_up_connection_ind.h"



static lcs_up_connection_ind_t *lcs_up_connection_ind_create_internal(
    ) {
    lcs_up_connection_ind_t *lcs_up_connection_ind_local_var = malloc(sizeof(lcs_up_connection_ind_t));
    if (!lcs_up_connection_ind_local_var) {
        return NULL;
    }
    memset(lcs_up_connection_ind_local_var, 0, sizeof(lcs_up_connection_ind_t));
    lcs_up_connection_ind_local_var->_library_owned = 1;
    return lcs_up_connection_ind_local_var;
}

__attribute__((deprecated)) lcs_up_connection_ind_t *lcs_up_connection_ind_create(
    ) {
    lcs_up_connection_ind_t *result = lcs_up_connection_ind_create_internal (
        );
    if (!result) {
    }
    return result;
}

void lcs_up_connection_ind_free(lcs_up_connection_ind_t *lcs_up_connection_ind) {
    if(NULL == lcs_up_connection_ind){
        return ;
    }
    if(lcs_up_connection_ind->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lcs_up_connection_ind_free");
        return ;
    }
    listEntry_t *listEntry;
    free(lcs_up_connection_ind);
}

cJSON *lcs_up_connection_ind_convertToJSON(lcs_up_connection_ind_t *lcs_up_connection_ind) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lcs_up_connection_ind_t *lcs_up_connection_ind_parseFromJSON(cJSON *lcs_up_connection_indJSON){

    lcs_up_connection_ind_t *lcs_up_connection_ind_local_var = NULL;



    lcs_up_connection_ind_local_var = lcs_up_connection_ind_create_internal (
        );

    if (!lcs_up_connection_ind_local_var) {
        goto end;
    }

    return lcs_up_connection_ind_local_var;
end:
    return NULL;

}
