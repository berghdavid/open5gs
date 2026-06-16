#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "location_qo_s.h"



static location_qo_s_t *location_qo_s_create_internal(
    float *h_accuracy,
    float *v_accuracy,
    int *vertical_requested,
    response_time_t *response_time,
    list_t *minor_loc_qoses,
    lcs_qos_class_t *lcs_qos_class
    ) {
    location_qo_s_t *location_qo_s_local_var = malloc(sizeof(location_qo_s_t));
    if (!location_qo_s_local_var) {
        return NULL;
    }
    memset(location_qo_s_local_var, 0, sizeof(location_qo_s_t));
    location_qo_s_local_var->_library_owned = 1;
    location_qo_s_local_var->h_accuracy = h_accuracy;
    location_qo_s_local_var->v_accuracy = v_accuracy;
    location_qo_s_local_var->vertical_requested = vertical_requested;
    location_qo_s_local_var->response_time = response_time;
    location_qo_s_local_var->minor_loc_qoses = minor_loc_qoses;
    location_qo_s_local_var->lcs_qos_class = lcs_qos_class;
    return location_qo_s_local_var;
}

__attribute__((deprecated)) location_qo_s_t *location_qo_s_create(
    float *h_accuracy,
    float *v_accuracy,
    int *vertical_requested,
    response_time_t *response_time,
    list_t *minor_loc_qoses,
    lcs_qos_class_t *lcs_qos_class
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
    int *vertical_requested_copy = NULL;
    if (vertical_requested) {
        vertical_requested_copy = malloc(sizeof(int));
        if (vertical_requested_copy) *vertical_requested_copy = *vertical_requested;
    }
    location_qo_s_t *result = location_qo_s_create_internal (
        h_accuracy_copy,
        v_accuracy_copy,
        vertical_requested_copy,
        response_time,
        minor_loc_qoses,
        lcs_qos_class
        );
    if (!result) {
        free(h_accuracy_copy);
        free(v_accuracy_copy);
        free(vertical_requested_copy);
    }
    return result;
}

void location_qo_s_free(location_qo_s_t *location_qo_s) {
    if(NULL == location_qo_s){
        return ;
    }
    if(location_qo_s->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "location_qo_s_free");
        return ;
    }
    listEntry_t *listEntry;
    if (location_qo_s->h_accuracy) {
        free(location_qo_s->h_accuracy);
        location_qo_s->h_accuracy = NULL;
    }
    if (location_qo_s->v_accuracy) {
        free(location_qo_s->v_accuracy);
        location_qo_s->v_accuracy = NULL;
    }
    if (location_qo_s->vertical_requested) {
        free(location_qo_s->vertical_requested);
        location_qo_s->vertical_requested = NULL;
    }
    if (location_qo_s->response_time) {
        response_time_free(location_qo_s->response_time);
        location_qo_s->response_time = NULL;
    }
    if (location_qo_s->minor_loc_qoses) {
        list_ForEach(listEntry, location_qo_s->minor_loc_qoses) {
            minor_location_qo_s_free(listEntry->data);
        }
        list_freeList(location_qo_s->minor_loc_qoses);
        location_qo_s->minor_loc_qoses = NULL;
    }
    if (location_qo_s->lcs_qos_class) {
        lcs_qos_class_free(location_qo_s->lcs_qos_class);
        location_qo_s->lcs_qos_class = NULL;
    }
    free(location_qo_s);
}

cJSON *location_qo_s_convertToJSON(location_qo_s_t *location_qo_s) {
    cJSON *item = cJSON_CreateObject();

    // location_qo_s->h_accuracy
    if(location_qo_s->h_accuracy) {
    if(cJSON_AddNumberToObject(item, "hAccuracy", *location_qo_s->h_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // location_qo_s->v_accuracy
    if(location_qo_s->v_accuracy) {
    if(cJSON_AddNumberToObject(item, "vAccuracy", *location_qo_s->v_accuracy) == NULL) {
    goto fail; //Numeric
    }
    }


    // location_qo_s->vertical_requested
    if(location_qo_s->vertical_requested) {
    if(cJSON_AddBoolToObject(item, "verticalRequested", *location_qo_s->vertical_requested) == NULL) {
    goto fail; //Bool
    }
    }


    // location_qo_s->response_time
    if(location_qo_s->response_time) {
    cJSON *response_time_local_JSON = response_time_convertToJSON(location_qo_s->response_time);
    if(response_time_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "responseTime", response_time_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // location_qo_s->minor_loc_qoses
    if(location_qo_s->minor_loc_qoses) {
    cJSON *minor_loc_qoses = cJSON_AddArrayToObject(item, "minorLocQoses");
    if(minor_loc_qoses == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *minor_loc_qosesListEntry;
    if (location_qo_s->minor_loc_qoses) {
    list_ForEach(minor_loc_qosesListEntry, location_qo_s->minor_loc_qoses) {
    cJSON *itemLocal = minor_location_qo_s_convertToJSON(minor_loc_qosesListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(minor_loc_qoses, itemLocal);
    }
    }
    }


    // location_qo_s->lcs_qos_class
    if(location_qo_s->lcs_qos_class) {
    cJSON *lcs_qos_class_local_JSON = lcs_qos_class_convertToJSON(location_qo_s->lcs_qos_class);
    if(lcs_qos_class_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lcsQosClass", lcs_qos_class_local_JSON);
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

location_qo_s_t *location_qo_s_parseFromJSON(cJSON *location_qo_sJSON){

    location_qo_s_t *location_qo_s_local_var = NULL;

    // define the local variable for location_qo_s->h_accuracy
    float *h_accuracy_local_var = NULL;

    // define the local variable for location_qo_s->v_accuracy
    float *v_accuracy_local_var = NULL;

    // define the local variable for location_qo_s->vertical_requested
    int *vertical_requested_local_var = NULL;

    // define the local variable for location_qo_s->response_time
    response_time_t *response_time_local_nonprim = NULL;

    // define the local list for location_qo_s->minor_loc_qoses
    list_t *minor_loc_qosesList = NULL;

    // define the local variable for location_qo_s->lcs_qos_class
    lcs_qos_class_t *lcs_qos_class_local_nonprim = NULL;

    // location_qo_s->h_accuracy
    cJSON *h_accuracy = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON, "hAccuracy");
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

    // location_qo_s->v_accuracy
    cJSON *v_accuracy = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON, "vAccuracy");
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

    // location_qo_s->vertical_requested
    cJSON *vertical_requested = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON, "verticalRequested");
    if (cJSON_IsNull(vertical_requested)) {
        vertical_requested = NULL;
    }
    if (vertical_requested) { 
    if(!cJSON_IsBool(vertical_requested))
    {
    goto end; //Bool
    }
    vertical_requested_local_var = malloc(sizeof(int));
    if(!vertical_requested_local_var)
    {
        goto end;
    }
    *vertical_requested_local_var = vertical_requested->valueint;
    }

    // location_qo_s->response_time
    cJSON *response_time = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON, "responseTime");
    if (cJSON_IsNull(response_time)) {
        response_time = NULL;
    }
    if (response_time) { 
    response_time_local_nonprim = response_time_parseFromJSON(response_time); //nonprimitive
    }

    // location_qo_s->minor_loc_qoses
    cJSON *minor_loc_qoses = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON, "minorLocQoses");
    if (cJSON_IsNull(minor_loc_qoses)) {
        minor_loc_qoses = NULL;
    }
    if (minor_loc_qoses) { 
    cJSON *minor_loc_qoses_local_nonprimitive = NULL;
    if(!cJSON_IsArray(minor_loc_qoses)){
        goto end; //nonprimitive container
    }

    minor_loc_qosesList = list_createList();

    cJSON_ArrayForEach(minor_loc_qoses_local_nonprimitive,minor_loc_qoses )
    {
        if(!cJSON_IsObject(minor_loc_qoses_local_nonprimitive)){
            goto end;
        }
        minor_location_qo_s_t *minor_loc_qosesItem = minor_location_qo_s_parseFromJSON(minor_loc_qoses_local_nonprimitive);

        list_addElement(minor_loc_qosesList, minor_loc_qosesItem);
    }
    }

    // location_qo_s->lcs_qos_class
    cJSON *lcs_qos_class = cJSON_GetObjectItemCaseSensitive(location_qo_sJSON, "lcsQosClass");
    if (cJSON_IsNull(lcs_qos_class)) {
        lcs_qos_class = NULL;
    }
    if (lcs_qos_class) { 
    lcs_qos_class_local_nonprim = lcs_qos_class_parseFromJSON(lcs_qos_class); //nonprimitive
    }



    location_qo_s_local_var = location_qo_s_create_internal (
        h_accuracy_local_var,
        v_accuracy_local_var,
        vertical_requested_local_var,
        response_time ? response_time_local_nonprim : NULL,
        minor_loc_qoses ? minor_loc_qosesList : NULL,
        lcs_qos_class ? lcs_qos_class_local_nonprim : NULL
        );

    if (!location_qo_s_local_var) {
        goto end;
    }

    return location_qo_s_local_var;
end:
    if (h_accuracy_local_var) {
        free(h_accuracy_local_var);
        h_accuracy_local_var = NULL;
    }
    if (v_accuracy_local_var) {
        free(v_accuracy_local_var);
        v_accuracy_local_var = NULL;
    }
    if (vertical_requested_local_var) {
        free(vertical_requested_local_var);
        vertical_requested_local_var = NULL;
    }
    if (response_time_local_nonprim) {
        response_time_free(response_time_local_nonprim);
        response_time_local_nonprim = NULL;
    }
    if (minor_loc_qosesList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, minor_loc_qosesList) {
            minor_location_qo_s_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(minor_loc_qosesList);
        minor_loc_qosesList = NULL;
    }
    if (lcs_qos_class_local_nonprim) {
        lcs_qos_class_free(lcs_qos_class_local_nonprim);
        lcs_qos_class_local_nonprim = NULL;
    }
    return NULL;

}
