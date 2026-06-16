#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "invalid_param.h"



static invalid_param_t *invalid_param_create_internal(
    char *param,
    char *reason
    ) {
    invalid_param_t *invalid_param_local_var = malloc(sizeof(invalid_param_t));
    if (!invalid_param_local_var) {
        return NULL;
    }
    memset(invalid_param_local_var, 0, sizeof(invalid_param_t));
    invalid_param_local_var->_library_owned = 1;
    invalid_param_local_var->param = param;
    invalid_param_local_var->reason = reason;
    return invalid_param_local_var;
}

__attribute__((deprecated)) invalid_param_t *invalid_param_create(
    char *param,
    char *reason
    ) {
    invalid_param_t *result = invalid_param_create_internal (
        param,
        reason
        );
    if (!result) {
    }
    return result;
}

void invalid_param_free(invalid_param_t *invalid_param) {
    if(NULL == invalid_param){
        return ;
    }
    if(invalid_param->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "invalid_param_free");
        return ;
    }
    listEntry_t *listEntry;
    if (invalid_param->param) {
        free(invalid_param->param);
        invalid_param->param = NULL;
    }
    if (invalid_param->reason) {
        free(invalid_param->reason);
        invalid_param->reason = NULL;
    }
    free(invalid_param);
}

cJSON *invalid_param_convertToJSON(invalid_param_t *invalid_param) {
    cJSON *item = cJSON_CreateObject();

    // invalid_param->param
    if (!invalid_param->param) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "param", invalid_param->param) == NULL) {
    goto fail; //String
    }


    // invalid_param->reason
    if(invalid_param->reason) {
    if(cJSON_AddStringToObject(item, "reason", invalid_param->reason) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

invalid_param_t *invalid_param_parseFromJSON(cJSON *invalid_paramJSON){

    invalid_param_t *invalid_param_local_var = NULL;

    char *param_local_str = NULL;

    char *reason_local_str = NULL;

    // invalid_param->param
    cJSON *param = cJSON_GetObjectItemCaseSensitive(invalid_paramJSON, "param");
    if (cJSON_IsNull(param)) {
        param = NULL;
    }
    if (!param) {
        goto end;
    }

    
    if(!cJSON_IsString(param))
    {
    goto end; //String
    }

    // invalid_param->reason
    cJSON *reason = cJSON_GetObjectItemCaseSensitive(invalid_paramJSON, "reason");
    if (cJSON_IsNull(reason)) {
        reason = NULL;
    }
    if (reason) { 
    if(!cJSON_IsString(reason) && !cJSON_IsNull(reason))
    {
    goto end; //String
    }
    }


    if (param && !cJSON_IsNull(param)) param_local_str = strdup(param->valuestring);
    if (reason && !cJSON_IsNull(reason)) reason_local_str = strdup(reason->valuestring);

    invalid_param_local_var = invalid_param_create_internal (
        param_local_str,
        reason_local_str
        );

    if (!invalid_param_local_var) {
        goto end;
    }

    return invalid_param_local_var;
end:
    if (param_local_str) {
        free(param_local_str);
        param_local_str = NULL;
    }
    if (reason_local_str) {
        free(reason_local_str);
        reason_local_str = NULL;
    }
    return NULL;

}
