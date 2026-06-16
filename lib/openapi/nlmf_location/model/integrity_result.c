#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "integrity_result.h"



static integrity_result_t *integrity_result_create_internal(
    integrity_computing_entity_t *computing_entity,
    integrity_protection_level_t *protection_level,
    int *integrity_req_met_ind,
    int *achieved_tir
    ) {
    integrity_result_t *integrity_result_local_var = malloc(sizeof(integrity_result_t));
    if (!integrity_result_local_var) {
        return NULL;
    }
    memset(integrity_result_local_var, 0, sizeof(integrity_result_t));
    integrity_result_local_var->_library_owned = 1;
    integrity_result_local_var->computing_entity = computing_entity;
    integrity_result_local_var->protection_level = protection_level;
    integrity_result_local_var->integrity_req_met_ind = integrity_req_met_ind;
    integrity_result_local_var->achieved_tir = achieved_tir;
    return integrity_result_local_var;
}

__attribute__((deprecated)) integrity_result_t *integrity_result_create(
    integrity_computing_entity_t *computing_entity,
    integrity_protection_level_t *protection_level,
    int *integrity_req_met_ind,
    int *achieved_tir
    ) {
    int *integrity_req_met_ind_copy = NULL;
    if (integrity_req_met_ind) {
        integrity_req_met_ind_copy = malloc(sizeof(int));
        if (integrity_req_met_ind_copy) *integrity_req_met_ind_copy = *integrity_req_met_ind;
    }
    int *achieved_tir_copy = NULL;
    if (achieved_tir) {
        achieved_tir_copy = malloc(sizeof(int));
        if (achieved_tir_copy) *achieved_tir_copy = *achieved_tir;
    }
    integrity_result_t *result = integrity_result_create_internal (
        computing_entity,
        protection_level,
        integrity_req_met_ind_copy,
        achieved_tir_copy
        );
    if (!result) {
        free(integrity_req_met_ind_copy);
        free(achieved_tir_copy);
    }
    return result;
}

void integrity_result_free(integrity_result_t *integrity_result) {
    if(NULL == integrity_result){
        return ;
    }
    if(integrity_result->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "integrity_result_free");
        return ;
    }
    listEntry_t *listEntry;
    if (integrity_result->computing_entity) {
        integrity_computing_entity_free(integrity_result->computing_entity);
        integrity_result->computing_entity = NULL;
    }
    if (integrity_result->protection_level) {
        integrity_protection_level_free(integrity_result->protection_level);
        integrity_result->protection_level = NULL;
    }
    if (integrity_result->integrity_req_met_ind) {
        free(integrity_result->integrity_req_met_ind);
        integrity_result->integrity_req_met_ind = NULL;
    }
    if (integrity_result->achieved_tir) {
        free(integrity_result->achieved_tir);
        integrity_result->achieved_tir = NULL;
    }
    free(integrity_result);
}

cJSON *integrity_result_convertToJSON(integrity_result_t *integrity_result) {
    cJSON *item = cJSON_CreateObject();

    // integrity_result->computing_entity
    if(integrity_result->computing_entity) {
    cJSON *computing_entity_local_JSON = integrity_computing_entity_convertToJSON(integrity_result->computing_entity);
    if(computing_entity_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "computingEntity", computing_entity_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // integrity_result->protection_level
    if(integrity_result->protection_level) {
    cJSON *protection_level_local_JSON = integrity_protection_level_convertToJSON(integrity_result->protection_level);
    if(protection_level_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "protectionLevel", protection_level_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // integrity_result->integrity_req_met_ind
    if(integrity_result->integrity_req_met_ind) {
    if(cJSON_AddBoolToObject(item, "integrityReqMetInd", *integrity_result->integrity_req_met_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // integrity_result->achieved_tir
    if(integrity_result->achieved_tir) {
    if(cJSON_AddNumberToObject(item, "achievedTir", *integrity_result->achieved_tir) == NULL) {
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

integrity_result_t *integrity_result_parseFromJSON(cJSON *integrity_resultJSON){

    integrity_result_t *integrity_result_local_var = NULL;

    // define the local variable for integrity_result->computing_entity
    integrity_computing_entity_t *computing_entity_local_nonprim = NULL;

    // define the local variable for integrity_result->protection_level
    integrity_protection_level_t *protection_level_local_nonprim = NULL;

    // define the local variable for integrity_result->integrity_req_met_ind
    int *integrity_req_met_ind_local_var = NULL;

    // define the local variable for integrity_result->achieved_tir
    int *achieved_tir_local_var = NULL;

    // integrity_result->computing_entity
    cJSON *computing_entity = cJSON_GetObjectItemCaseSensitive(integrity_resultJSON, "computingEntity");
    if (cJSON_IsNull(computing_entity)) {
        computing_entity = NULL;
    }
    if (computing_entity) { 
    computing_entity_local_nonprim = integrity_computing_entity_parseFromJSON(computing_entity); //nonprimitive
    }

    // integrity_result->protection_level
    cJSON *protection_level = cJSON_GetObjectItemCaseSensitive(integrity_resultJSON, "protectionLevel");
    if (cJSON_IsNull(protection_level)) {
        protection_level = NULL;
    }
    if (protection_level) { 
    protection_level_local_nonprim = integrity_protection_level_parseFromJSON(protection_level); //nonprimitive
    }

    // integrity_result->integrity_req_met_ind
    cJSON *integrity_req_met_ind = cJSON_GetObjectItemCaseSensitive(integrity_resultJSON, "integrityReqMetInd");
    if (cJSON_IsNull(integrity_req_met_ind)) {
        integrity_req_met_ind = NULL;
    }
    if (integrity_req_met_ind) { 
    if(!cJSON_IsBool(integrity_req_met_ind))
    {
    goto end; //Bool
    }
    integrity_req_met_ind_local_var = malloc(sizeof(int));
    if(!integrity_req_met_ind_local_var)
    {
        goto end;
    }
    *integrity_req_met_ind_local_var = integrity_req_met_ind->valueint;
    }

    // integrity_result->achieved_tir
    cJSON *achieved_tir = cJSON_GetObjectItemCaseSensitive(integrity_resultJSON, "achievedTir");
    if (cJSON_IsNull(achieved_tir)) {
        achieved_tir = NULL;
    }
    if (achieved_tir) { 
    if(!cJSON_IsNumber(achieved_tir))
    {
    goto end; //Numeric
    }
    achieved_tir_local_var = malloc(sizeof(int));
    if(!achieved_tir_local_var)
    {
        goto end;
    }
    *achieved_tir_local_var = achieved_tir->valuedouble;
    }



    integrity_result_local_var = integrity_result_create_internal (
        computing_entity ? computing_entity_local_nonprim : NULL,
        protection_level ? protection_level_local_nonprim : NULL,
        integrity_req_met_ind_local_var,
        achieved_tir_local_var
        );

    if (!integrity_result_local_var) {
        goto end;
    }

    return integrity_result_local_var;
end:
    if (computing_entity_local_nonprim) {
        integrity_computing_entity_free(computing_entity_local_nonprim);
        computing_entity_local_nonprim = NULL;
    }
    if (protection_level_local_nonprim) {
        integrity_protection_level_free(protection_level_local_nonprim);
        protection_level_local_nonprim = NULL;
    }
    if (integrity_req_met_ind_local_var) {
        free(integrity_req_met_ind_local_var);
        integrity_req_met_ind_local_var = NULL;
    }
    if (achieved_tir_local_var) {
        free(achieved_tir_local_var);
        achieved_tir_local_var = NULL;
    }
    return NULL;

}
