#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mapped_location_qo_s_eps.h"



static mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_create_internal(
    float *h_accuracy,
    float *v_accuracy
    ) {
    mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_local_var = malloc(sizeof(mapped_location_qo_s_eps_t));
    if (!mapped_location_qo_s_eps_local_var) {
        return NULL;
    }
    memset(mapped_location_qo_s_eps_local_var, 0, sizeof(mapped_location_qo_s_eps_t));
    mapped_location_qo_s_eps_local_var->_library_owned = 1;
    mapped_location_qo_s_eps_local_var->h_accuracy = h_accuracy;
    mapped_location_qo_s_eps_local_var->v_accuracy = v_accuracy;
    return mapped_location_qo_s_eps_local_var;
}

__attribute__((deprecated)) mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_create(
    float *h_accuracy,
    float *v_accuracy
    ) {
    float *h_accuracy_copy = NULL;
    if (h_accuracy) {
        h_accuracy_copy = malloc(sizeof(float));
        if (h_accuracy_copy) *h_accuracy_copy = *h_accuracy;
    }
    float *v_accuracy_copy = NULL;
    if (v_accuracy) {
        v_accuracy_copy = malloc(sizeof(float));
        if (v_accuracy_copy) *v_accuracy_copy = *v_accuracy;
    }
    mapped_location_qo_s_eps_t *result = mapped_location_qo_s_eps_create_internal (
        h_accuracy_copy,
        v_accuracy_copy
        );
    if (!result) {
        free(h_accuracy_copy);
        free(v_accuracy_copy);
    }
    return result;
}

void mapped_location_qo_s_eps_free(mapped_location_qo_s_eps_t *mapped_location_qo_s_eps) {
    if(NULL == mapped_location_qo_s_eps){
        return ;
    }
    if(mapped_location_qo_s_eps->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "mapped_location_qo_s_eps_free");
        return ;
    }
    listEntry_t *listEntry;
    if (mapped_location_qo_s_eps->h_accuracy) {
        free(mapped_location_qo_s_eps->h_accuracy);
        mapped_location_qo_s_eps->h_accuracy = NULL;
    }
    if (mapped_location_qo_s_eps->v_accuracy) {
        free(mapped_location_qo_s_eps->v_accuracy);
        mapped_location_qo_s_eps->v_accuracy = NULL;
    }
    free(mapped_location_qo_s_eps);
}

cJSON *mapped_location_qo_s_eps_convertToJSON(mapped_location_qo_s_eps_t *mapped_location_qo_s_eps) {
    cJSON *item = cJSON_CreateObject();

    // mapped_location_qo_s_eps->h_accuracy
    if (!mapped_location_qo_s_eps->h_accuracy) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "hAccuracy", *mapped_location_qo_s_eps->h_accuracy) == NULL) {
    goto fail; //Numeric
    }


    // mapped_location_qo_s_eps->v_accuracy
    if(mapped_location_qo_s_eps->v_accuracy) {
    if(cJSON_AddNumberToObject(item, "vAccuracy", *mapped_location_qo_s_eps->v_accuracy) == NULL) {
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

mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_parseFromJSON(cJSON *mapped_location_qo_s_epsJSON){

    mapped_location_qo_s_eps_t *mapped_location_qo_s_eps_local_var = NULL;

    // define the local variable for mapped_location_qo_s_eps->h_accuracy
    float *h_accuracy_local_var = NULL;

    // define the local variable for mapped_location_qo_s_eps->v_accuracy
    float *v_accuracy_local_var = NULL;

    // mapped_location_qo_s_eps->h_accuracy
    cJSON *h_accuracy = cJSON_GetObjectItemCaseSensitive(mapped_location_qo_s_epsJSON, "hAccuracy");
    if (cJSON_IsNull(h_accuracy)) {
        h_accuracy = NULL;
    }
    if (!h_accuracy) {
        goto end;
    }

    
    if(!cJSON_IsNumber(h_accuracy))
    {
    goto end; //Numeric
    }
    h_accuracy_local_var = malloc(sizeof(float));
    if(!h_accuracy_local_var)
    {
        goto end;
    }
    *h_accuracy_local_var = h_accuracy->valuedouble;

    // mapped_location_qo_s_eps->v_accuracy
    cJSON *v_accuracy = cJSON_GetObjectItemCaseSensitive(mapped_location_qo_s_epsJSON, "vAccuracy");
    if (cJSON_IsNull(v_accuracy)) {
        v_accuracy = NULL;
    }
    if (v_accuracy) { 
    if(!cJSON_IsNumber(v_accuracy))
    {
    goto end; //Numeric
    }
    v_accuracy_local_var = malloc(sizeof(float));
    if(!v_accuracy_local_var)
    {
        goto end;
    }
    *v_accuracy_local_var = v_accuracy->valuedouble;
    }



    mapped_location_qo_s_eps_local_var = mapped_location_qo_s_eps_create_internal (
        h_accuracy_local_var,
        v_accuracy_local_var
        );

    if (!mapped_location_qo_s_eps_local_var) {
        goto end;
    }

    return mapped_location_qo_s_eps_local_var;
end:
    if (h_accuracy_local_var) {
        free(h_accuracy_local_var);
        h_accuracy_local_var = NULL;
    }
    if (v_accuracy_local_var) {
        free(v_accuracy_local_var);
        v_accuracy_local_var = NULL;
    }
    return NULL;

}
