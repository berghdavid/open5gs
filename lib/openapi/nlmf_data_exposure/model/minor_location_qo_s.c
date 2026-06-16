#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "minor_location_qo_s.h"



static minor_location_qo_s_t *minor_location_qo_s_create_internal(
    float *h_accuracy,
    float *v_accuracy
    ) {
    minor_location_qo_s_t *minor_location_qo_s_local_var = malloc(sizeof(minor_location_qo_s_t));
    if (!minor_location_qo_s_local_var) {
        return NULL;
    }
    memset(minor_location_qo_s_local_var, 0, sizeof(minor_location_qo_s_t));
    minor_location_qo_s_local_var->_library_owned = 1;
    minor_location_qo_s_local_var->h_accuracy = h_accuracy;
    minor_location_qo_s_local_var->v_accuracy = v_accuracy;
    return minor_location_qo_s_local_var;
}

__attribute__((deprecated)) minor_location_qo_s_t *minor_location_qo_s_create(
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
    minor_location_qo_s_t *result = minor_location_qo_s_create_internal (
        h_accuracy_copy,
        v_accuracy_copy
        );
    if (!result) {
        free(h_accuracy_copy);
        free(v_accuracy_copy);
    }
    return result;
}

void minor_location_qo_s_free(minor_location_qo_s_t *minor_location_qo_s) {
    if(NULL == minor_location_qo_s){
        return ;
    }
    if(minor_location_qo_s->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "minor_location_qo_s_free");
        return ;
    }
    listEntry_t *listEntry;
    if (minor_location_qo_s->h_accuracy) {
        free(minor_location_qo_s->h_accuracy);
        minor_location_qo_s->h_accuracy = NULL;
    }
    if (minor_location_qo_s->v_accuracy) {
        free(minor_location_qo_s->v_accuracy);
        minor_location_qo_s->v_accuracy = NULL;
    }
    free(minor_location_qo_s);
}

cJSON *minor_location_qo_s_convertToJSON(minor_location_qo_s_t *minor_location_qo_s) {
    cJSON *item = cJSON_CreateObject();

    // minor_location_qo_s->h_accuracy
    if(minor_location_qo_s->h_accuracy) {
    if(cJSON_AddNumberToObject(item, "hAccuracy", *minor_location_qo_s->h_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // minor_location_qo_s->v_accuracy
    if(minor_location_qo_s->v_accuracy) {
    if(cJSON_AddNumberToObject(item, "vAccuracy", *minor_location_qo_s->v_accuracy) == NULL) {
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

minor_location_qo_s_t *minor_location_qo_s_parseFromJSON(cJSON *minor_location_qo_sJSON){

    minor_location_qo_s_t *minor_location_qo_s_local_var = NULL;

    // define the local variable for minor_location_qo_s->h_accuracy
    float *h_accuracy_local_var = NULL;

    // define the local variable for minor_location_qo_s->v_accuracy
    float *v_accuracy_local_var = NULL;

    // minor_location_qo_s->h_accuracy
    cJSON *h_accuracy = cJSON_GetObjectItemCaseSensitive(minor_location_qo_sJSON, "hAccuracy");
    if (cJSON_IsNull(h_accuracy)) {
        h_accuracy = NULL;
    }
    if (h_accuracy) { 
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
    }

    // minor_location_qo_s->v_accuracy
    cJSON *v_accuracy = cJSON_GetObjectItemCaseSensitive(minor_location_qo_sJSON, "vAccuracy");
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



    minor_location_qo_s_local_var = minor_location_qo_s_create_internal (
        h_accuracy_local_var,
        v_accuracy_local_var
        );

    if (!minor_location_qo_s_local_var) {
        goto end;
    }

    return minor_location_qo_s_local_var;
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
