#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "trp_parameter.h"



static trp_parameter_t *trp_parameter_create_internal(
    list_t *trp_ids,
    global_ran_node_id_t *global_gnb_id
    ) {
    trp_parameter_t *trp_parameter_local_var = malloc(sizeof(trp_parameter_t));
    if (!trp_parameter_local_var) {
        return NULL;
    }
    memset(trp_parameter_local_var, 0, sizeof(trp_parameter_t));
    trp_parameter_local_var->_library_owned = 1;
    trp_parameter_local_var->trp_ids = trp_ids;
    trp_parameter_local_var->global_gnb_id = global_gnb_id;
    return trp_parameter_local_var;
}

__attribute__((deprecated)) trp_parameter_t *trp_parameter_create(
    list_t *trp_ids,
    global_ran_node_id_t *global_gnb_id
    ) {
    trp_parameter_t *result = trp_parameter_create_internal (
        trp_ids,
        global_gnb_id
        );
    if (!result) {
    }
    return result;
}

void trp_parameter_free(trp_parameter_t *trp_parameter) {
    if(NULL == trp_parameter){
        return ;
    }
    if(trp_parameter->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "trp_parameter_free");
        return ;
    }
    listEntry_t *listEntry;
    if (trp_parameter->trp_ids) {
        list_ForEach(listEntry, trp_parameter->trp_ids) {
            free(listEntry->data);
        }
        list_freeList(trp_parameter->trp_ids);
        trp_parameter->trp_ids = NULL;
    }
    if (trp_parameter->global_gnb_id) {
        global_ran_node_id_free(trp_parameter->global_gnb_id);
        trp_parameter->global_gnb_id = NULL;
    }
    free(trp_parameter);
}

cJSON *trp_parameter_convertToJSON(trp_parameter_t *trp_parameter) {
    cJSON *item = cJSON_CreateObject();

    // trp_parameter->trp_ids
    if(trp_parameter->trp_ids) {
    cJSON *trp_ids = cJSON_AddArrayToObject(item, "trpIds");
    if(trp_ids == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *trp_idsListEntry;
    list_ForEach(trp_idsListEntry, trp_parameter->trp_ids) {
    if(cJSON_AddNumberToObject(trp_ids, "", *(double *)trp_idsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // trp_parameter->global_gnb_id
    if(trp_parameter->global_gnb_id) {
    cJSON *global_gnb_id_local_JSON = global_ran_node_id_convertToJSON(trp_parameter->global_gnb_id);
    if(global_gnb_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "globalGnbId", global_gnb_id_local_JSON);
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

trp_parameter_t *trp_parameter_parseFromJSON(cJSON *trp_parameterJSON){

    trp_parameter_t *trp_parameter_local_var = NULL;

    // define the local list for trp_parameter->trp_ids
    list_t *trp_idsList = NULL;

    // define the local variable for trp_parameter->global_gnb_id
    global_ran_node_id_t *global_gnb_id_local_nonprim = NULL;

    // trp_parameter->trp_ids
    cJSON *trp_ids = cJSON_GetObjectItemCaseSensitive(trp_parameterJSON, "trpIds");
    if (cJSON_IsNull(trp_ids)) {
        trp_ids = NULL;
    }
    if (trp_ids) { 
    cJSON *trp_ids_local = NULL;
    if(!cJSON_IsArray(trp_ids)) {
        goto end;//primitive container
    }
    trp_idsList = list_createList();

    cJSON_ArrayForEach(trp_ids_local, trp_ids)
    {
        if(!cJSON_IsNumber(trp_ids_local))
        {
            goto end;
        }
        double *trp_ids_local_value = calloc(1, sizeof(double));
        if(!trp_ids_local_value)
        {
            goto end;
        }
        *trp_ids_local_value = trp_ids_local->valuedouble;
        list_addElement(trp_idsList , trp_ids_local_value);
    }
    }

    // trp_parameter->global_gnb_id
    cJSON *global_gnb_id = cJSON_GetObjectItemCaseSensitive(trp_parameterJSON, "globalGnbId");
    if (cJSON_IsNull(global_gnb_id)) {
        global_gnb_id = NULL;
    }
    if (global_gnb_id) { 
    global_gnb_id_local_nonprim = global_ran_node_id_parseFromJSON(global_gnb_id); //nonprimitive
    }



    trp_parameter_local_var = trp_parameter_create_internal (
        trp_ids ? trp_idsList : NULL,
        global_gnb_id ? global_gnb_id_local_nonprim : NULL
        );

    if (!trp_parameter_local_var) {
        goto end;
    }

    return trp_parameter_local_var;
end:
    if (trp_idsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, trp_idsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(trp_idsList);
        trp_idsList = NULL;
    }
    if (global_gnb_id_local_nonprim) {
        global_ran_node_id_free(global_gnb_id_local_nonprim);
        global_gnb_id_local_nonprim = NULL;
    }
    return NULL;

}
