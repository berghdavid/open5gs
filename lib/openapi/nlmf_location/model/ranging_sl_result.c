#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ranging_sl_result.h"



static ranging_sl_result_t *ranging_sl_result_create_internal(
    ) {
    ranging_sl_result_t *ranging_sl_result_local_var = malloc(sizeof(ranging_sl_result_t));
    if (!ranging_sl_result_local_var) {
        return NULL;
    }
    memset(ranging_sl_result_local_var, 0, sizeof(ranging_sl_result_t));
    ranging_sl_result_local_var->_library_owned = 1;
    return ranging_sl_result_local_var;
}

__attribute__((deprecated)) ranging_sl_result_t *ranging_sl_result_create(
    ) {
    ranging_sl_result_t *result = ranging_sl_result_create_internal (
        );
    if (!result) {
    }
    return result;
}

void ranging_sl_result_free(ranging_sl_result_t *ranging_sl_result) {
    if(NULL == ranging_sl_result){
        return ;
    }
    if(ranging_sl_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ranging_sl_result_free");
        return ;
    }
    listEntry_t *listEntry;
    free(ranging_sl_result);
}

cJSON *ranging_sl_result_convertToJSON(ranging_sl_result_t *ranging_sl_result) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ranging_sl_result_t *ranging_sl_result_parseFromJSON(cJSON *ranging_sl_resultJSON){

    ranging_sl_result_t *ranging_sl_result_local_var = NULL;



    ranging_sl_result_local_var = ranging_sl_result_create_internal (
        );

    if (!ranging_sl_result_local_var) {
        goto end;
    }

    return ranging_sl_result_local_var;
end:
    return NULL;

}
