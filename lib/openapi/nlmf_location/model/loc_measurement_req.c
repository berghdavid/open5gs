#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_measurement_req.h"



static loc_measurement_req_t *loc_measurement_req_create_internal(
    ncgi_t *ncgi,
    ecgi_t *ecgi,
    geographic_area_t *pre_calcu_loc_estimate,
    char *timestamp_of_pre_calcu_loc_estimate,
    list_t *time_windows,
    time_windows_nrppa_t *time_windows_nrppa,
    positioning_method_t *method,
    list_t *trp_parameters
    ) {
    loc_measurement_req_t *loc_measurement_req_local_var = malloc(sizeof(loc_measurement_req_t));
    if (!loc_measurement_req_local_var) {
        return NULL;
    }
    memset(loc_measurement_req_local_var, 0, sizeof(loc_measurement_req_t));
    loc_measurement_req_local_var->_library_owned = 1;
    loc_measurement_req_local_var->ncgi = ncgi;
    loc_measurement_req_local_var->ecgi = ecgi;
    loc_measurement_req_local_var->pre_calcu_loc_estimate = pre_calcu_loc_estimate;
    loc_measurement_req_local_var->timestamp_of_pre_calcu_loc_estimate = timestamp_of_pre_calcu_loc_estimate;
    loc_measurement_req_local_var->time_windows = time_windows;
    loc_measurement_req_local_var->time_windows_nrppa = time_windows_nrppa;
    loc_measurement_req_local_var->method = method;
    loc_measurement_req_local_var->trp_parameters = trp_parameters;
    return loc_measurement_req_local_var;
}

__attribute__((deprecated)) loc_measurement_req_t *loc_measurement_req_create(
    ncgi_t *ncgi,
    ecgi_t *ecgi,
    geographic_area_t *pre_calcu_loc_estimate,
    char *timestamp_of_pre_calcu_loc_estimate,
    list_t *time_windows,
    time_windows_nrppa_t *time_windows_nrppa,
    positioning_method_t *method,
    list_t *trp_parameters
    ) {
    loc_measurement_req_t *result = loc_measurement_req_create_internal (
        ncgi,
        ecgi,
        pre_calcu_loc_estimate,
        timestamp_of_pre_calcu_loc_estimate,
        time_windows,
        time_windows_nrppa,
        method,
        trp_parameters
        );
    if (!result) {
    }
    return result;
}

void loc_measurement_req_free(loc_measurement_req_t *loc_measurement_req) {
    if(NULL == loc_measurement_req){
        return ;
    }
    if(loc_measurement_req->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "loc_measurement_req_free");
        return ;
    }
    listEntry_t *listEntry;
    if (loc_measurement_req->ncgi) {
        ncgi_free(loc_measurement_req->ncgi);
        loc_measurement_req->ncgi = NULL;
    }
    if (loc_measurement_req->ecgi) {
        ecgi_free(loc_measurement_req->ecgi);
        loc_measurement_req->ecgi = NULL;
    }
    if (loc_measurement_req->pre_calcu_loc_estimate) {
        geographic_area_free(loc_measurement_req->pre_calcu_loc_estimate);
        loc_measurement_req->pre_calcu_loc_estimate = NULL;
    }
    if (loc_measurement_req->timestamp_of_pre_calcu_loc_estimate) {
        free(loc_measurement_req->timestamp_of_pre_calcu_loc_estimate);
        loc_measurement_req->timestamp_of_pre_calcu_loc_estimate = NULL;
    }
    if (loc_measurement_req->time_windows) {
        list_ForEach(listEntry, loc_measurement_req->time_windows) {
            free(listEntry->data);
        }
        list_freeList(loc_measurement_req->time_windows);
        loc_measurement_req->time_windows = NULL;
    }
    if (loc_measurement_req->time_windows_nrppa) {
        time_windows_nrppa_free(loc_measurement_req->time_windows_nrppa);
        loc_measurement_req->time_windows_nrppa = NULL;
    }
    if (loc_measurement_req->method) {
        positioning_method_free(loc_measurement_req->method);
        loc_measurement_req->method = NULL;
    }
    if (loc_measurement_req->trp_parameters) {
        list_ForEach(listEntry, loc_measurement_req->trp_parameters) {
            trp_parameter_free(listEntry->data);
        }
        list_freeList(loc_measurement_req->trp_parameters);
        loc_measurement_req->trp_parameters = NULL;
    }
    free(loc_measurement_req);
}

cJSON *loc_measurement_req_convertToJSON(loc_measurement_req_t *loc_measurement_req) {
    cJSON *item = cJSON_CreateObject();

    // loc_measurement_req->ncgi
    if(loc_measurement_req->ncgi) {
    cJSON *ncgi_local_JSON = ncgi_convertToJSON(loc_measurement_req->ncgi);
    if(ncgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_measurement_req->ecgi
    if(loc_measurement_req->ecgi) {
    cJSON *ecgi_local_JSON = ecgi_convertToJSON(loc_measurement_req->ecgi);
    if(ecgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_measurement_req->pre_calcu_loc_estimate
    if(loc_measurement_req->pre_calcu_loc_estimate) {
    cJSON *pre_calcu_loc_estimate_local_JSON = geographic_area_convertToJSON(loc_measurement_req->pre_calcu_loc_estimate);
    if(pre_calcu_loc_estimate_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "preCalcuLocEstimate", pre_calcu_loc_estimate_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_measurement_req->timestamp_of_pre_calcu_loc_estimate
    if(loc_measurement_req->timestamp_of_pre_calcu_loc_estimate) {
    if(cJSON_AddStringToObject(item, "timestampOfPreCalcuLocEstimate", loc_measurement_req->timestamp_of_pre_calcu_loc_estimate) == NULL) {
    goto fail; //Date-Time
    }
    }


    // loc_measurement_req->time_windows
    if(loc_measurement_req->time_windows) {
    cJSON *time_windows = cJSON_AddArrayToObject(item, "timeWindows");
    if(time_windows == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *time_windowsListEntry;
    list_ForEach(time_windowsListEntry, loc_measurement_req->time_windows) {
    }
    }


    // loc_measurement_req->time_windows_nrppa
    if(loc_measurement_req->time_windows_nrppa) {
    cJSON *time_windows_nrppa_local_JSON = time_windows_nrppa_convertToJSON(loc_measurement_req->time_windows_nrppa);
    if(time_windows_nrppa_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "timeWindowsNrppa", time_windows_nrppa_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_measurement_req->method
    if(loc_measurement_req->method) {
    cJSON *method_local_JSON = positioning_method_convertToJSON(loc_measurement_req->method);
    if(method_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "method", method_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // loc_measurement_req->trp_parameters
    if(loc_measurement_req->trp_parameters) {
    cJSON *trp_parameters = cJSON_AddArrayToObject(item, "trpParameters");
    if(trp_parameters == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *trp_parametersListEntry;
    if (loc_measurement_req->trp_parameters) {
    list_ForEach(trp_parametersListEntry, loc_measurement_req->trp_parameters) {
    cJSON *itemLocal = trp_parameter_convertToJSON(trp_parametersListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(trp_parameters, itemLocal);
    }
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

loc_measurement_req_t *loc_measurement_req_parseFromJSON(cJSON *loc_measurement_reqJSON){

    loc_measurement_req_t *loc_measurement_req_local_var = NULL;

    // define the local variable for loc_measurement_req->ncgi
    ncgi_t *ncgi_local_nonprim = NULL;

    // define the local variable for loc_measurement_req->ecgi
    ecgi_t *ecgi_local_nonprim = NULL;

    // define the local variable for loc_measurement_req->pre_calcu_loc_estimate
    geographic_area_t *pre_calcu_loc_estimate_local_nonprim = NULL;

    char *timestamp_of_pre_calcu_loc_estimate_local_str = NULL;

    // define the local list for loc_measurement_req->time_windows
    list_t *time_windowsList = NULL;

    // define the local variable for loc_measurement_req->time_windows_nrppa
    time_windows_nrppa_t *time_windows_nrppa_local_nonprim = NULL;

    // define the local variable for loc_measurement_req->method
    positioning_method_t *method_local_nonprim = NULL;

    // define the local list for loc_measurement_req->trp_parameters
    list_t *trp_parametersList = NULL;

    // loc_measurement_req->ncgi
    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "ncgi");
    if (cJSON_IsNull(ncgi)) {
        ncgi = NULL;
    }
    if (ncgi) { 
    ncgi_local_nonprim = ncgi_parseFromJSON(ncgi); //nonprimitive
    }

    // loc_measurement_req->ecgi
    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "ecgi");
    if (cJSON_IsNull(ecgi)) {
        ecgi = NULL;
    }
    if (ecgi) { 
    ecgi_local_nonprim = ecgi_parseFromJSON(ecgi); //nonprimitive
    }

    // loc_measurement_req->pre_calcu_loc_estimate
    cJSON *pre_calcu_loc_estimate = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "preCalcuLocEstimate");
    if (cJSON_IsNull(pre_calcu_loc_estimate)) {
        pre_calcu_loc_estimate = NULL;
    }
    if (pre_calcu_loc_estimate) { 
    pre_calcu_loc_estimate_local_nonprim = geographic_area_parseFromJSON(pre_calcu_loc_estimate); //nonprimitive
    }

    // loc_measurement_req->timestamp_of_pre_calcu_loc_estimate
    cJSON *timestamp_of_pre_calcu_loc_estimate = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "timestampOfPreCalcuLocEstimate");
    if (cJSON_IsNull(timestamp_of_pre_calcu_loc_estimate)) {
        timestamp_of_pre_calcu_loc_estimate = NULL;
    }
    if (timestamp_of_pre_calcu_loc_estimate) { 
    if(!cJSON_IsString(timestamp_of_pre_calcu_loc_estimate) && !cJSON_IsNull(timestamp_of_pre_calcu_loc_estimate))
    {
    goto end; //DateTime
    }
    }

    // loc_measurement_req->time_windows
    cJSON *time_windows = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "timeWindows");
    if (cJSON_IsNull(time_windows)) {
        time_windows = NULL;
    }
    if (time_windows) { 
    cJSON *time_windows_local = NULL;
    if(!cJSON_IsArray(time_windows)) {
        goto end;//primitive container
    }
    time_windowsList = list_createList();

    cJSON_ArrayForEach(time_windows_local, time_windows)
    {
    }
    }

    // loc_measurement_req->time_windows_nrppa
    cJSON *time_windows_nrppa = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "timeWindowsNrppa");
    if (cJSON_IsNull(time_windows_nrppa)) {
        time_windows_nrppa = NULL;
    }
    if (time_windows_nrppa) { 
    time_windows_nrppa_local_nonprim = time_windows_nrppa_parseFromJSON(time_windows_nrppa); //nonprimitive
    }

    // loc_measurement_req->method
    cJSON *method = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "method");
    if (cJSON_IsNull(method)) {
        method = NULL;
    }
    if (method) { 
    method_local_nonprim = positioning_method_parseFromJSON(method); //nonprimitive
    }

    // loc_measurement_req->trp_parameters
    cJSON *trp_parameters = cJSON_GetObjectItemCaseSensitive(loc_measurement_reqJSON, "trpParameters");
    if (cJSON_IsNull(trp_parameters)) {
        trp_parameters = NULL;
    }
    if (trp_parameters) { 
    cJSON *trp_parameters_local_nonprimitive = NULL;
    if(!cJSON_IsArray(trp_parameters)){
        goto end; //nonprimitive container
    }

    trp_parametersList = list_createList();

    cJSON_ArrayForEach(trp_parameters_local_nonprimitive,trp_parameters )
    {
        if(!cJSON_IsObject(trp_parameters_local_nonprimitive)){
            goto end;
        }
        trp_parameter_t *trp_parametersItem = trp_parameter_parseFromJSON(trp_parameters_local_nonprimitive);

        list_addElement(trp_parametersList, trp_parametersItem);
    }
    }


    if (timestamp_of_pre_calcu_loc_estimate && !cJSON_IsNull(timestamp_of_pre_calcu_loc_estimate)) timestamp_of_pre_calcu_loc_estimate_local_str = strdup(timestamp_of_pre_calcu_loc_estimate->valuestring);

    loc_measurement_req_local_var = loc_measurement_req_create_internal (
        ncgi ? ncgi_local_nonprim : NULL,
        ecgi ? ecgi_local_nonprim : NULL,
        pre_calcu_loc_estimate ? pre_calcu_loc_estimate_local_nonprim : NULL,
        timestamp_of_pre_calcu_loc_estimate_local_str,
        time_windows ? time_windowsList : NULL,
        time_windows_nrppa ? time_windows_nrppa_local_nonprim : NULL,
        method ? method_local_nonprim : NULL,
        trp_parameters ? trp_parametersList : NULL
        );

    if (!loc_measurement_req_local_var) {
        goto end;
    }

    return loc_measurement_req_local_var;
end:
    if (ncgi_local_nonprim) {
        ncgi_free(ncgi_local_nonprim);
        ncgi_local_nonprim = NULL;
    }
    if (ecgi_local_nonprim) {
        ecgi_free(ecgi_local_nonprim);
        ecgi_local_nonprim = NULL;
    }
    if (pre_calcu_loc_estimate_local_nonprim) {
        geographic_area_free(pre_calcu_loc_estimate_local_nonprim);
        pre_calcu_loc_estimate_local_nonprim = NULL;
    }
    if (timestamp_of_pre_calcu_loc_estimate_local_str) {
        free(timestamp_of_pre_calcu_loc_estimate_local_str);
        timestamp_of_pre_calcu_loc_estimate_local_str = NULL;
    }
    if (time_windowsList) {
        list_freeList(time_windowsList);
        time_windowsList = NULL;
    }
    if (time_windows_nrppa_local_nonprim) {
        time_windows_nrppa_free(time_windows_nrppa_local_nonprim);
        time_windows_nrppa_local_nonprim = NULL;
    }
    if (method_local_nonprim) {
        positioning_method_free(method_local_nonprim);
        method_local_nonprim = NULL;
    }
    if (trp_parametersList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, trp_parametersList) {
            trp_parameter_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(trp_parametersList);
        trp_parametersList = NULL;
    }
    return NULL;

}
