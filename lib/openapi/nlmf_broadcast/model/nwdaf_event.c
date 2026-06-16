#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "nwdaf_event.h"



static nwdaf_event_t *nwdaf_event_create_internal(
    ) {
    nwdaf_event_t *nwdaf_event_local_var = malloc(sizeof(nwdaf_event_t));
    if (!nwdaf_event_local_var) {
        return NULL;
    }
    memset(nwdaf_event_local_var, 0, sizeof(nwdaf_event_t));
    nwdaf_event_local_var->_library_owned = 1;
    return nwdaf_event_local_var;
}

__attribute__((deprecated)) nwdaf_event_t *nwdaf_event_create(
    ) {
    nwdaf_event_t *result = nwdaf_event_create_internal (
        );
    if (!result) {
    }
    return result;
}

void nwdaf_event_free(nwdaf_event_t *nwdaf_event) {
    if(NULL == nwdaf_event){
        return ;
    }
    if(nwdaf_event->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "nwdaf_event_free");
        return ;
    }
    listEntry_t *listEntry;
    free(nwdaf_event);
}

cJSON *nwdaf_event_convertToJSON(nwdaf_event_t *nwdaf_event) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

nwdaf_event_t *nwdaf_event_parseFromJSON(cJSON *nwdaf_eventJSON){

    nwdaf_event_t *nwdaf_event_local_var = NULL;



    nwdaf_event_local_var = nwdaf_event_create_internal (
        );

    if (!nwdaf_event_local_var) {
        goto end;
    }

    return nwdaf_event_local_var;
end:
    return NULL;

}
