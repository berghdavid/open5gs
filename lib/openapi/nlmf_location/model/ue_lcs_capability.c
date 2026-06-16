#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_lcs_capability.h"



static ue_lcs_capability_t *ue_lcs_capability_create_internal(
    int *lpp_support,
    int *ciot_optimisation
    ) {
    ue_lcs_capability_t *ue_lcs_capability_local_var = malloc(sizeof(ue_lcs_capability_t));
    if (!ue_lcs_capability_local_var) {
        return NULL;
    }
    memset(ue_lcs_capability_local_var, 0, sizeof(ue_lcs_capability_t));
    ue_lcs_capability_local_var->_library_owned = 1;
    ue_lcs_capability_local_var->lpp_support = lpp_support;
    ue_lcs_capability_local_var->ciot_optimisation = ciot_optimisation;
    return ue_lcs_capability_local_var;
}

__attribute__((deprecated)) ue_lcs_capability_t *ue_lcs_capability_create(
    int *lpp_support,
    int *ciot_optimisation
    ) {
    int *lpp_support_copy = NULL;
    if (lpp_support) {
        lpp_support_copy = malloc(sizeof(int));
        if (lpp_support_copy) *lpp_support_copy = *lpp_support;
    }
    int *ciot_optimisation_copy = NULL;
    if (ciot_optimisation) {
        ciot_optimisation_copy = malloc(sizeof(int));
        if (ciot_optimisation_copy) *ciot_optimisation_copy = *ciot_optimisation;
    }
    ue_lcs_capability_t *result = ue_lcs_capability_create_internal (
        lpp_support_copy,
        ciot_optimisation_copy
        );
    if (!result) {
        free(lpp_support_copy);
        free(ciot_optimisation_copy);
    }
    return result;
}

void ue_lcs_capability_free(ue_lcs_capability_t *ue_lcs_capability) {
    if(NULL == ue_lcs_capability){
        return ;
    }
    if(ue_lcs_capability->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ue_lcs_capability_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ue_lcs_capability->lpp_support) {
        free(ue_lcs_capability->lpp_support);
        ue_lcs_capability->lpp_support = NULL;
    }
    if (ue_lcs_capability->ciot_optimisation) {
        free(ue_lcs_capability->ciot_optimisation);
        ue_lcs_capability->ciot_optimisation = NULL;
    }
    free(ue_lcs_capability);
}

cJSON *ue_lcs_capability_convertToJSON(ue_lcs_capability_t *ue_lcs_capability) {
    cJSON *item = cJSON_CreateObject();

    // ue_lcs_capability->lpp_support
    if(ue_lcs_capability->lpp_support) {
    if(cJSON_AddBoolToObject(item, "lppSupport", *ue_lcs_capability->lpp_support) == NULL) {
    goto fail; //Bool
    }
    }


    // ue_lcs_capability->ciot_optimisation
    if(ue_lcs_capability->ciot_optimisation) {
    if(cJSON_AddBoolToObject(item, "ciotOptimisation", *ue_lcs_capability->ciot_optimisation) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ue_lcs_capability_t *ue_lcs_capability_parseFromJSON(cJSON *ue_lcs_capabilityJSON){

    ue_lcs_capability_t *ue_lcs_capability_local_var = NULL;

    // define the local variable for ue_lcs_capability->lpp_support
    int *lpp_support_local_var = NULL;

    // define the local variable for ue_lcs_capability->ciot_optimisation
    int *ciot_optimisation_local_var = NULL;

    // ue_lcs_capability->lpp_support
    cJSON *lpp_support = cJSON_GetObjectItemCaseSensitive(ue_lcs_capabilityJSON, "lppSupport");
    if (cJSON_IsNull(lpp_support)) {
        lpp_support = NULL;
    }
    if (lpp_support) { 
    if(!cJSON_IsBool(lpp_support))
    {
    goto end; //Bool
    }
    lpp_support_local_var = malloc(sizeof(int));
    if(!lpp_support_local_var)
    {
        goto end;
    }
    *lpp_support_local_var = lpp_support->valueint;
    }

    // ue_lcs_capability->ciot_optimisation
    cJSON *ciot_optimisation = cJSON_GetObjectItemCaseSensitive(ue_lcs_capabilityJSON, "ciotOptimisation");
    if (cJSON_IsNull(ciot_optimisation)) {
        ciot_optimisation = NULL;
    }
    if (ciot_optimisation) { 
    if(!cJSON_IsBool(ciot_optimisation))
    {
    goto end; //Bool
    }
    ciot_optimisation_local_var = malloc(sizeof(int));
    if(!ciot_optimisation_local_var)
    {
        goto end;
    }
    *ciot_optimisation_local_var = ciot_optimisation->valueint;
    }



    ue_lcs_capability_local_var = ue_lcs_capability_create_internal (
        lpp_support_local_var,
        ciot_optimisation_local_var
        );

    if (!ue_lcs_capability_local_var) {
        goto end;
    }

    return ue_lcs_capability_local_var;
end:
    if (lpp_support_local_var) {
        free(lpp_support_local_var);
        lpp_support_local_var = NULL;
    }
    if (ciot_optimisation_local_var) {
        free(ciot_optimisation_local_var);
        ciot_optimisation_local_var = NULL;
    }
    return NULL;

}
