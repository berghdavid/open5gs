#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_class.h"



static event_class_t *event_class_create_internal(
    ) {
    event_class_t *event_class_local_var = malloc(sizeof(event_class_t));
    if (!event_class_local_var) {
        return NULL;
    }
    memset(event_class_local_var, 0, sizeof(event_class_t));
    event_class_local_var->_library_owned = 1;
    return event_class_local_var;
}

__attribute__((deprecated)) event_class_t *event_class_create(
    ) {
    event_class_t *result = event_class_create_internal (
        );
    if (!result) {
    }
    return result;
}

void event_class_free(event_class_t *event_class) {
    if(NULL == event_class){
        return ;
    }
    if(event_class->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "event_class_free");
        return ;
    }
    listEntry_t *listEntry;
    free(event_class);
}

cJSON *event_class_convertToJSON(event_class_t *event_class) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

event_class_t *event_class_parseFromJSON(cJSON *event_classJSON){

    event_class_t *event_class_local_var = NULL;



    event_class_local_var = event_class_create_internal (
        );

    if (!event_class_local_var) {
        goto end;
    }

    return event_class_local_var;
end:
    return NULL;

}
