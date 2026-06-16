#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "positioning_method_and_usage.h"



static positioning_method_and_usage_t *positioning_method_and_usage_create_internal(
    positioning_method_t *method,
    positioning_mode_t *mode,
    usage_t *usage,
    int *method_code
    ) {
    positioning_method_and_usage_t *positioning_method_and_usage_local_var = malloc(sizeof(positioning_method_and_usage_t));
    if (!positioning_method_and_usage_local_var) {
        return NULL;
    }
    memset(positioning_method_and_usage_local_var, 0, sizeof(positioning_method_and_usage_t));
    positioning_method_and_usage_local_var->_library_owned = 1;
    positioning_method_and_usage_local_var->method = method;
    positioning_method_and_usage_local_var->mode = mode;
    positioning_method_and_usage_local_var->usage = usage;
    positioning_method_and_usage_local_var->method_code = method_code;
    return positioning_method_and_usage_local_var;
}

__attribute__((deprecated)) positioning_method_and_usage_t *positioning_method_and_usage_create(
    positioning_method_t *method,
    positioning_mode_t *mode,
    usage_t *usage,
    int *method_code
    ) {
    int *method_code_copy = NULL;
    if (method_code) {
        method_code_copy = malloc(sizeof(int));
        if (method_code_copy) *method_code_copy = *method_code;
    }
    positioning_method_and_usage_t *result = positioning_method_and_usage_create_internal (
        method,
        mode,
        usage,
        method_code_copy
        );
    if (!result) {
        free(method_code_copy);
    }
    return result;
}

void positioning_method_and_usage_free(positioning_method_and_usage_t *positioning_method_and_usage) {
    if(NULL == positioning_method_and_usage){
        return ;
    }
    if(positioning_method_and_usage->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "positioning_method_and_usage_free");
        return ;
    }
    listEntry_t *listEntry;
    if (positioning_method_and_usage->method) {
        positioning_method_free(positioning_method_and_usage->method);
        positioning_method_and_usage->method = NULL;
    }
    if (positioning_method_and_usage->mode) {
        positioning_mode_free(positioning_method_and_usage->mode);
        positioning_method_and_usage->mode = NULL;
    }
    if (positioning_method_and_usage->usage) {
        usage_free(positioning_method_and_usage->usage);
        positioning_method_and_usage->usage = NULL;
    }
    if (positioning_method_and_usage->method_code) {
        free(positioning_method_and_usage->method_code);
        positioning_method_and_usage->method_code = NULL;
    }
    free(positioning_method_and_usage);
}

cJSON *positioning_method_and_usage_convertToJSON(positioning_method_and_usage_t *positioning_method_and_usage) {
    cJSON *item = cJSON_CreateObject();

    // positioning_method_and_usage->method
    if (!positioning_method_and_usage->method) {
        goto fail;
    }
    cJSON *method_local_JSON = positioning_method_convertToJSON(positioning_method_and_usage->method);
    if(method_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "method", method_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // positioning_method_and_usage->mode
    if (!positioning_method_and_usage->mode) {
        goto fail;
    }
    cJSON *mode_local_JSON = positioning_mode_convertToJSON(positioning_method_and_usage->mode);
    if(mode_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "mode", mode_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // positioning_method_and_usage->usage
    if (!positioning_method_and_usage->usage) {
        goto fail;
    }
    cJSON *usage_local_JSON = usage_convertToJSON(positioning_method_and_usage->usage);
    if(usage_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "usage", usage_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // positioning_method_and_usage->method_code
    if(positioning_method_and_usage->method_code) {
    if(cJSON_AddNumberToObject(item, "methodCode", *positioning_method_and_usage->method_code) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

positioning_method_and_usage_t *positioning_method_and_usage_parseFromJSON(cJSON *positioning_method_and_usageJSON){

    positioning_method_and_usage_t *positioning_method_and_usage_local_var = NULL;

    // define the local variable for positioning_method_and_usage->method
    positioning_method_t *method_local_nonprim = NULL;

    // define the local variable for positioning_method_and_usage->mode
    positioning_mode_t *mode_local_nonprim = NULL;

    // define the local variable for positioning_method_and_usage->usage
    usage_t *usage_local_nonprim = NULL;

    // define the local variable for positioning_method_and_usage->method_code
    int *method_code_local_var = NULL;

    // positioning_method_and_usage->method
    cJSON *method = cJSON_GetObjectItemCaseSensitive(positioning_method_and_usageJSON, "method");
    if (cJSON_IsNull(method)) {
        method = NULL;
    }
    if (!method) {
        goto end;
    }

    
    method_local_nonprim = positioning_method_parseFromJSON(method); //nonprimitive

    // positioning_method_and_usage->mode
    cJSON *mode = cJSON_GetObjectItemCaseSensitive(positioning_method_and_usageJSON, "mode");
    if (cJSON_IsNull(mode)) {
        mode = NULL;
    }
    if (!mode) {
        goto end;
    }

    
    mode_local_nonprim = positioning_mode_parseFromJSON(mode); //nonprimitive

    // positioning_method_and_usage->usage
    cJSON *usage = cJSON_GetObjectItemCaseSensitive(positioning_method_and_usageJSON, "usage");
    if (cJSON_IsNull(usage)) {
        usage = NULL;
    }
    if (!usage) {
        goto end;
    }

    
    usage_local_nonprim = usage_parseFromJSON(usage); //nonprimitive

    // positioning_method_and_usage->method_code
    cJSON *method_code = cJSON_GetObjectItemCaseSensitive(positioning_method_and_usageJSON, "methodCode");
    if (cJSON_IsNull(method_code)) {
        method_code = NULL;
    }
    if (method_code) { 
    if(!cJSON_IsNumber(method_code))
    {
    goto end; //Numeric
    }
    method_code_local_var = malloc(sizeof(int));
    if(!method_code_local_var)
    {
        goto end;
    }
    *method_code_local_var = method_code->valuedouble;
    }



    positioning_method_and_usage_local_var = positioning_method_and_usage_create_internal (
        method_local_nonprim,
        mode_local_nonprim,
        usage_local_nonprim,
        method_code_local_var
        );

    if (!positioning_method_and_usage_local_var) {
        goto end;
    }

    return positioning_method_and_usage_local_var;
end:
    if (method_local_nonprim) {
        positioning_method_free(method_local_nonprim);
        method_local_nonprim = NULL;
    }
    if (mode_local_nonprim) {
        positioning_mode_free(mode_local_nonprim);
        mode_local_nonprim = NULL;
    }
    if (usage_local_nonprim) {
        usage_free(usage_local_nonprim);
        usage_local_nonprim = NULL;
    }
    if (method_code_local_var) {
        free(method_code_local_var);
        method_code_local_var = NULL;
    }
    return NULL;

}
