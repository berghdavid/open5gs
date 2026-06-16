#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "termination_cause.h"



static termination_cause_t *termination_cause_create_internal(
    ) {
    termination_cause_t *termination_cause_local_var = malloc(sizeof(termination_cause_t));
    if (!termination_cause_local_var) {
        return NULL;
    }
    memset(termination_cause_local_var, 0, sizeof(termination_cause_t));
    termination_cause_local_var->_library_owned = 1;
    return termination_cause_local_var;
}

__attribute__((deprecated)) termination_cause_t *termination_cause_create(
    ) {
    termination_cause_t *result = termination_cause_create_internal (
        );
    if (!result) {
    }
    return result;
}

void termination_cause_free(termination_cause_t *termination_cause) {
    if(NULL == termination_cause){
        return ;
    }
    if(termination_cause->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "termination_cause_free");
        return ;
    }
    listEntry_t *listEntry;
    free(termination_cause);
}

cJSON *termination_cause_convertToJSON(termination_cause_t *termination_cause) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

termination_cause_t *termination_cause_parseFromJSON(cJSON *termination_causeJSON){

    termination_cause_t *termination_cause_local_var = NULL;



    termination_cause_local_var = termination_cause_create_internal (
        );

    if (!termination_cause_local_var) {
        goto end;
    }

    return termination_cause_local_var;
end:
    return NULL;

}
