#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reported_event_type.h"



static reported_event_type_t *reported_event_type_create_internal(
    ) {
    reported_event_type_t *reported_event_type_local_var = malloc(sizeof(reported_event_type_t));
    if (!reported_event_type_local_var) {
        return NULL;
    }
    memset(reported_event_type_local_var, 0, sizeof(reported_event_type_t));
    reported_event_type_local_var->_library_owned = 1;
    return reported_event_type_local_var;
}

__attribute__((deprecated)) reported_event_type_t *reported_event_type_create(
    ) {
    reported_event_type_t *result = reported_event_type_create_internal (
        );
    if (!result) {
    }
    return result;
}

void reported_event_type_free(reported_event_type_t *reported_event_type) {
    if(NULL == reported_event_type){
        return ;
    }
    if(reported_event_type->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reported_event_type_free");
        return ;
    }
    listEntry_t *listEntry;
    free(reported_event_type);
}

cJSON *reported_event_type_convertToJSON(reported_event_type_t *reported_event_type) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

reported_event_type_t *reported_event_type_parseFromJSON(cJSON *reported_event_typeJSON){

    reported_event_type_t *reported_event_type_local_var = NULL;



    reported_event_type_local_var = reported_event_type_create_internal (
        );

    if (!reported_event_type_local_var) {
        goto end;
    }

    return reported_event_type_local_var;
end:
    return NULL;

}
