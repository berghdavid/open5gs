#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "patch_item.h"



static patch_item_t *patch_item_create_internal(
    patch_operation_t *op,
    char *path,
    char *from,
    any_type_t *value
    ) {
    patch_item_t *patch_item_local_var = malloc(sizeof(patch_item_t));
    if (!patch_item_local_var) {
        return NULL;
    }
    memset(patch_item_local_var, 0, sizeof(patch_item_t));
    patch_item_local_var->_library_owned = 1;
    patch_item_local_var->op = op;
    patch_item_local_var->path = path;
    patch_item_local_var->from = from;
    patch_item_local_var->value = value;
    return patch_item_local_var;
}

__attribute__((deprecated)) patch_item_t *patch_item_create(
    patch_operation_t *op,
    char *path,
    char *from,
    any_type_t *value
    ) {
    patch_item_t *result = patch_item_create_internal (
        op,
        path,
        from,
        value
        );
    if (!result) {
    }
    return result;
}

void patch_item_free(patch_item_t *patch_item) {
    if(NULL == patch_item){
        return ;
    }
    if(patch_item->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "patch_item_free");
        return ;
    }
    listEntry_t *listEntry;
    if (patch_item->op) {
        patch_operation_free(patch_item->op);
        patch_item->op = NULL;
    }
    if (patch_item->path) {
        free(patch_item->path);
        patch_item->path = NULL;
    }
    if (patch_item->from) {
        free(patch_item->from);
        patch_item->from = NULL;
    }
    if (patch_item->value) {
        _free(patch_item->value);
        patch_item->value = NULL;
    }
    free(patch_item);
}

cJSON *patch_item_convertToJSON(patch_item_t *patch_item) {
    cJSON *item = cJSON_CreateObject();

    // patch_item->op
    if (!patch_item->op) {
        goto fail;
    }
    cJSON *op_local_JSON = patch_operation_convertToJSON(patch_item->op);
    if(op_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "op", op_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // patch_item->path
    if (!patch_item->path) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "path", patch_item->path) == NULL) {
    goto fail; //String
    }


    // patch_item->from
    if(patch_item->from) {
    if(cJSON_AddStringToObject(item, "from", patch_item->from) == NULL) {
    goto fail; //String
    }
    }


    // patch_item->value
    if(patch_item->value) {
    cJSON *value_local_JSON = _convertToJSON(patch_item->value);
    if(value_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "value", value_local_JSON);
    if(item->child == NULL) {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

patch_item_t *patch_item_parseFromJSON(cJSON *patch_itemJSON){

    patch_item_t *patch_item_local_var = NULL;

    // define the local variable for patch_item->op
    patch_operation_t *op_local_nonprim = NULL;

    char *path_local_str = NULL;

    char *from_local_str = NULL;

    // define the local variable for patch_item->value
    _t *value_local_nonprim = NULL;

    // patch_item->op
    cJSON *op = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "op");
    if (cJSON_IsNull(op)) {
        op = NULL;
    }
    if (!op) {
        goto end;
    }

    
    op_local_nonprim = patch_operation_parseFromJSON(op); //nonprimitive

    // patch_item->path
    cJSON *path = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "path");
    if (cJSON_IsNull(path)) {
        path = NULL;
    }
    if (!path) {
        goto end;
    }

    
    if(!cJSON_IsString(path))
    {
    goto end; //String
    }

    // patch_item->from
    cJSON *from = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "from");
    if (cJSON_IsNull(from)) {
        from = NULL;
    }
    if (from) { 
    if(!cJSON_IsString(from) && !cJSON_IsNull(from))
    {
    goto end; //String
    }
    }

    // patch_item->value
    cJSON *value = cJSON_GetObjectItemCaseSensitive(patch_itemJSON, "value");
    if (cJSON_IsNull(value)) {
        value = NULL;
    }
    if (value) { 
    value_local_nonprim = _parseFromJSON(value); //custom
    }


    if (path && !cJSON_IsNull(path)) path_local_str = strdup(path->valuestring);
    if (from && !cJSON_IsNull(from)) from_local_str = strdup(from->valuestring);

    patch_item_local_var = patch_item_create_internal (
        op_local_nonprim,
        path_local_str,
        from_local_str,
        value ? value_local_nonprim : NULL
        );

    if (!patch_item_local_var) {
        goto end;
    }

    return patch_item_local_var;
end:
    if (op_local_nonprim) {
        patch_operation_free(op_local_nonprim);
        op_local_nonprim = NULL;
    }
    if (path_local_str) {
        free(path_local_str);
        path_local_str = NULL;
    }
    if (from_local_str) {
        free(from_local_str);
        from_local_str = NULL;
    }
    if (value_local_nonprim) {
        _free(value_local_nonprim);
        value_local_nonprim = NULL;
    }
    return NULL;

}
