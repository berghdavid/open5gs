#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_connection_status.h"



static up_connection_status_t *up_connection_status_create_internal(
    ) {
    up_connection_status_t *up_connection_status_local_var = malloc(sizeof(up_connection_status_t));
    if (!up_connection_status_local_var) {
        return NULL;
    }
    memset(up_connection_status_local_var, 0, sizeof(up_connection_status_t));
    up_connection_status_local_var->_library_owned = 1;
    return up_connection_status_local_var;
}

__attribute__((deprecated)) up_connection_status_t *up_connection_status_create(
    ) {
    up_connection_status_t *result = up_connection_status_create_internal (
        );
    if (!result) {
    }
    return result;
}

void up_connection_status_free(up_connection_status_t *up_connection_status) {
    if(NULL == up_connection_status){
        return ;
    }
    if(up_connection_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "up_connection_status_free");
        return ;
    }
    listEntry_t *listEntry;
    free(up_connection_status);
}

cJSON *up_connection_status_convertToJSON(up_connection_status_t *up_connection_status) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

up_connection_status_t *up_connection_status_parseFromJSON(cJSON *up_connection_statusJSON){

    up_connection_status_t *up_connection_status_local_var = NULL;



    up_connection_status_local_var = up_connection_status_create_internal (
        );

    if (!up_connection_status_local_var) {
        goto end;
    }

    return up_connection_status_local_var;
end:
    return NULL;

}
