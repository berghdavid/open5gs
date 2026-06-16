#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "query_parameter.h"



static query_parameter_t *query_parameter_create_internal(
    char *name,
    char *value
    ) {
    query_parameter_t *query_parameter_local_var = malloc(sizeof(query_parameter_t));
    if (!query_parameter_local_var) {
        return NULL;
    }
    memset(query_parameter_local_var, 0, sizeof(query_parameter_t));
    query_parameter_local_var->_library_owned = 1;
    query_parameter_local_var->name = name;
    query_parameter_local_var->value = value;
    return query_parameter_local_var;
}

__attribute__((deprecated)) query_parameter_t *query_parameter_create(
    char *name,
    char *value
    ) {
    query_parameter_t *result = query_parameter_create_internal (
        name,
        value
        );
    if (!result) {
    }
    return result;
}

void query_parameter_free(query_parameter_t *query_parameter) {
    if(NULL == query_parameter){
        return ;
    }
    if(query_parameter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "query_parameter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (query_parameter->name) {
        free(query_parameter->name);
        query_parameter->name = NULL;
    }
    if (query_parameter->value) {
        free(query_parameter->value);
        query_parameter->value = NULL;
    }
    free(query_parameter);
}

cJSON *query_parameter_convertToJSON(query_parameter_t *query_parameter) {
    cJSON *item = cJSON_CreateObject();

    // query_parameter->name
    if (!query_parameter->name) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "name", query_parameter->name) == NULL) {
    goto fail; //String
    }


    // query_parameter->value
    if (!query_parameter->value) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "value", query_parameter->value) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

query_parameter_t *query_parameter_parseFromJSON(cJSON *query_parameterJSON){

    query_parameter_t *query_parameter_local_var = NULL;

    char *name_local_str = NULL;

    char *value_local_str = NULL;

    // query_parameter->name
    cJSON *name = cJSON_GetObjectItemCaseSensitive(query_parameterJSON, "name");
    if (cJSON_IsNull(name)) {
        name = NULL;
    }
    if (!name) {
        goto end;
    }

    
    if(!cJSON_IsString(name))
    {
    goto end; //String
    }

    // query_parameter->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(query_parameterJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (!value) {
        goto end;
    }

    
    if(!cJSON_IsString(value))
    {
    goto end; //String
    }


    if (name && !cJSON_IsNull(name)) name_local_str = strdup(name->valuestring);
    if (value && !cJSON_IsNull(value)) value_local_str = strdup(value->valuestring);

    query_parameter_local_var = query_parameter_create_internal (
        name_local_str,
        value_local_str
        );

    if (!query_parameter_local_var) {
        goto end;
    }

    return query_parameter_local_var;
end:
    if (name_local_str) {
        free(name_local_str);
        name_local_str = NULL;
    }
    if (value_local_str) {
        free(value_local_str);
        value_local_str = NULL;
    }
    return NULL;

}
