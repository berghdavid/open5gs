#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "response_time.h"



static response_time_t *response_time_create_internal(
    ) {
    response_time_t *response_time_local_var = malloc(sizeof(response_time_t));
    if (!response_time_local_var) {
        return NULL;
    }
    memset(response_time_local_var, 0, sizeof(response_time_t));
    response_time_local_var->_library_owned = 1;
    return response_time_local_var;
}

__attribute__((deprecated)) response_time_t *response_time_create(
    ) {
    response_time_t *result = response_time_create_internal (
        );
    if (!result) {
    }
    return result;
}

void response_time_free(response_time_t *response_time) {
    if(NULL == response_time){
        return ;
    }
    if(response_time->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "response_time_free");
        return ;
    }
    listEntry_t *listEntry;
    free(response_time);
}

cJSON *response_time_convertToJSON(response_time_t *response_time) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

response_time_t *response_time_parseFromJSON(cJSON *response_timeJSON){

    response_time_t *response_time_local_var = NULL;



    response_time_local_var = response_time_create_internal (
        );

    if (!response_time_local_var) {
        goto end;
    }

    return response_time_local_var;
end:
    return NULL;

}
