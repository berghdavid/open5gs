#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gnss_id.h"



static gnss_id_t *gnss_id_create_internal(
    ) {
    gnss_id_t *gnss_id_local_var = malloc(sizeof(gnss_id_t));
    if (!gnss_id_local_var) {
        return NULL;
    }
    memset(gnss_id_local_var, 0, sizeof(gnss_id_t));
    gnss_id_local_var->_library_owned = 1;
    return gnss_id_local_var;
}

__attribute__((deprecated)) gnss_id_t *gnss_id_create(
    ) {
    gnss_id_t *result = gnss_id_create_internal (
        );
    if (!result) {
    }
    return result;
}

void gnss_id_free(gnss_id_t *gnss_id) {
    if(NULL == gnss_id){
        return ;
    }
    if(gnss_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gnss_id_free");
        return ;
    }
    listEntry_t *listEntry;
    free(gnss_id);
}

cJSON *gnss_id_convertToJSON(gnss_id_t *gnss_id) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gnss_id_t *gnss_id_parseFromJSON(cJSON *gnss_idJSON){

    gnss_id_t *gnss_id_local_var = NULL;



    gnss_id_local_var = gnss_id_create_internal (
        );

    if (!gnss_id_local_var) {
        goto end;
    }

    return gnss_id_local_var;
end:
    return NULL;

}
