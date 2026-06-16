#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "problem_details.h"



static problem_details_t *problem_details_create_internal(
    char *type,
    char *title,
    int *status,
    char *detail,
    char *instance,
    char *cause,
    list_t *invalid_params,
    char *supported_features,
    access_token_err_t *access_token_error,
    access_token_req_t *access_token_request,
    char *nrf_id,
    list_t *supported_api_versions,
    no_profile_match_info_t *no_profile_match_info
    ) {
    problem_details_t *problem_details_local_var = malloc(sizeof(problem_details_t));
    if (!problem_details_local_var) {
        return NULL;
    }
    memset(problem_details_local_var, 0, sizeof(problem_details_t));
    problem_details_local_var->_library_owned = 1;
    problem_details_local_var->type = type;
    problem_details_local_var->title = title;
    problem_details_local_var->status = status;
    problem_details_local_var->detail = detail;
    problem_details_local_var->instance = instance;
    problem_details_local_var->cause = cause;
    problem_details_local_var->invalid_params = invalid_params;
    problem_details_local_var->supported_features = supported_features;
    problem_details_local_var->access_token_error = access_token_error;
    problem_details_local_var->access_token_request = access_token_request;
    problem_details_local_var->nrf_id = nrf_id;
    problem_details_local_var->supported_api_versions = supported_api_versions;
    problem_details_local_var->no_profile_match_info = no_profile_match_info;
    return problem_details_local_var;
}

__attribute__((deprecated)) problem_details_t *problem_details_create(
    char *type,
    char *title,
    int *status,
    char *detail,
    char *instance,
    char *cause,
    list_t *invalid_params,
    char *supported_features,
    access_token_err_t *access_token_error,
    access_token_req_t *access_token_request,
    char *nrf_id,
    list_t *supported_api_versions,
    no_profile_match_info_t *no_profile_match_info
    ) {
    int *status_copy = NULL;
    if (status) {
        status_copy = malloc(sizeof(int));
        if (status_copy) *status_copy = *status;
    }
    problem_details_t *result = problem_details_create_internal (
        type,
        title,
        status_copy,
        detail,
        instance,
        cause,
        invalid_params,
        supported_features,
        access_token_error,
        access_token_request,
        nrf_id,
        supported_api_versions,
        no_profile_match_info
        );
    if (!result) {
        free(status_copy);
    }
    return result;
}

void problem_details_free(problem_details_t *problem_details) {
    if(NULL == problem_details){
        return ;
    }
    if(problem_details->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "problem_details_free");
        return ;
    }
    listEntry_t *listEntry;
    if (problem_details->type) {
        free(problem_details->type);
        problem_details->type = NULL;
    }
    if (problem_details->title) {
        free(problem_details->title);
        problem_details->title = NULL;
    }
    if (problem_details->status) {
        free(problem_details->status);
        problem_details->status = NULL;
    }
    if (problem_details->detail) {
        free(problem_details->detail);
        problem_details->detail = NULL;
    }
    if (problem_details->instance) {
        free(problem_details->instance);
        problem_details->instance = NULL;
    }
    if (problem_details->cause) {
        free(problem_details->cause);
        problem_details->cause = NULL;
    }
    if (problem_details->invalid_params) {
        list_ForEach(listEntry, problem_details->invalid_params) {
            invalid_param_free(listEntry->data);
        }
        list_freeList(problem_details->invalid_params);
        problem_details->invalid_params = NULL;
    }
    if (problem_details->supported_features) {
        free(problem_details->supported_features);
        problem_details->supported_features = NULL;
    }
    if (problem_details->access_token_error) {
        access_token_err_free(problem_details->access_token_error);
        problem_details->access_token_error = NULL;
    }
    if (problem_details->access_token_request) {
        access_token_req_free(problem_details->access_token_request);
        problem_details->access_token_request = NULL;
    }
    if (problem_details->nrf_id) {
        free(problem_details->nrf_id);
        problem_details->nrf_id = NULL;
    }
    if (problem_details->supported_api_versions) {
        list_ForEach(listEntry, problem_details->supported_api_versions) {
            free(listEntry->data);
        }
        list_freeList(problem_details->supported_api_versions);
        problem_details->supported_api_versions = NULL;
    }
    if (problem_details->no_profile_match_info) {
        no_profile_match_info_free(problem_details->no_profile_match_info);
        problem_details->no_profile_match_info = NULL;
    }
    free(problem_details);
}

cJSON *problem_details_convertToJSON(problem_details_t *problem_details) {
    cJSON *item = cJSON_CreateObject();

    // problem_details->type
    if(problem_details->type) {
    if(cJSON_AddStringToObject(item, "type", problem_details->type) == NULL) {
    goto fail; //String
    }
    }


    // problem_details->title
    if(problem_details->title) {
    if(cJSON_AddStringToObject(item, "title", problem_details->title) == NULL) {
    goto fail; //String
    }
    }


    // problem_details->status
    if(problem_details->status) {
    if(cJSON_AddNumberToObject(item, "status", *problem_details->status) == NULL) {
    goto fail; //Numeric
    }
    }


    // problem_details->detail
    if(problem_details->detail) {
    if(cJSON_AddStringToObject(item, "detail", problem_details->detail) == NULL) {
    goto fail; //String
    }
    }


    // problem_details->instance
    if(problem_details->instance) {
    if(cJSON_AddStringToObject(item, "instance", problem_details->instance) == NULL) {
    goto fail; //String
    }
    }


    // problem_details->cause
    if(problem_details->cause) {
    if(cJSON_AddStringToObject(item, "cause", problem_details->cause) == NULL) {
    goto fail; //String
    }
    }


    // problem_details->invalid_params
    if(problem_details->invalid_params) {
    cJSON *invalid_params = cJSON_AddArrayToObject(item, "invalidParams");
    if(invalid_params == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *invalid_paramsListEntry;
    if (problem_details->invalid_params) {
    list_ForEach(invalid_paramsListEntry, problem_details->invalid_params) {
    cJSON *itemLocal = invalid_param_convertToJSON(invalid_paramsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(invalid_params, itemLocal);
    }
    }
    }


    // problem_details->supported_features
    if(problem_details->supported_features) {
    if(cJSON_AddStringToObject(item, "supportedFeatures", problem_details->supported_features) == NULL) {
    goto fail; //String
    }
    }


    // problem_details->access_token_error
    if(problem_details->access_token_error) {
    cJSON *access_token_error_local_JSON = access_token_err_convertToJSON(problem_details->access_token_error);
    if(access_token_error_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "accessTokenError", access_token_error_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // problem_details->access_token_request
    if(problem_details->access_token_request) {
    cJSON *access_token_request_local_JSON = access_token_req_convertToJSON(problem_details->access_token_request);
    if(access_token_request_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "accessTokenRequest", access_token_request_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // problem_details->nrf_id
    if(problem_details->nrf_id) {
    if(cJSON_AddStringToObject(item, "nrfId", problem_details->nrf_id) == NULL) {
    goto fail; //String
    }
    }


    // problem_details->supported_api_versions
    if(problem_details->supported_api_versions) {
    cJSON *supported_api_versions = cJSON_AddArrayToObject(item, "supportedApiVersions");
    if(supported_api_versions == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *supported_api_versionsListEntry;
    list_ForEach(supported_api_versionsListEntry, problem_details->supported_api_versions) {
    if(cJSON_AddStringToObject(supported_api_versions, "", supported_api_versionsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // problem_details->no_profile_match_info
    if(problem_details->no_profile_match_info) {
    cJSON *no_profile_match_info_local_JSON = no_profile_match_info_convertToJSON(problem_details->no_profile_match_info);
    if(no_profile_match_info_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "noProfileMatchInfo", no_profile_match_info_local_JSON);
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

problem_details_t *problem_details_parseFromJSON(cJSON *problem_detailsJSON){

    problem_details_t *problem_details_local_var = NULL;

    char *type_local_str = NULL;

    char *title_local_str = NULL;

    // define the local variable for problem_details->status
    int *status_local_var = NULL;

    char *detail_local_str = NULL;

    char *instance_local_str = NULL;

    char *cause_local_str = NULL;

    // define the local list for problem_details->invalid_params
    list_t *invalid_paramsList = NULL;

    char *supported_features_local_str = NULL;

    // define the local variable for problem_details->access_token_error
    access_token_err_t *access_token_error_local_nonprim = NULL;

    // define the local variable for problem_details->access_token_request
    access_token_req_t *access_token_request_local_nonprim = NULL;

    char *nrf_id_local_str = NULL;

    // define the local list for problem_details->supported_api_versions
    list_t *supported_api_versionsList = NULL;

    // define the local variable for problem_details->no_profile_match_info
    no_profile_match_info_t *no_profile_match_info_local_nonprim = NULL;

    // problem_details->type
    cJSON *type = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "type");
    if (cJSON_IsNull(type)) {
        type = NULL;
    }
    if (type) { 
    if(!cJSON_IsString(type) && !cJSON_IsNull(type))
    {
    goto end; //String
    }
    }

    // problem_details->title
    cJSON *title = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "title");
    if (cJSON_IsNull(title)) {
        title = NULL;
    }
    if (title) { 
    if(!cJSON_IsString(title) && !cJSON_IsNull(title))
    {
    goto end; //String
    }
    }

    // problem_details->status
    cJSON *status = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "status");
    if (cJSON_IsNull(status)) {
        status = NULL;
    }
    if (status) { 
    if(!cJSON_IsNumber(status))
    {
    goto end; //Numeric
    }
    status_local_var = malloc(sizeof(int));
    if(!status_local_var)
    {
        goto end;
    }
    *status_local_var = status->valuedouble;
    }

    // problem_details->detail
    cJSON *detail = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "detail");
    if (cJSON_IsNull(detail)) {
        detail = NULL;
    }
    if (detail) { 
    if(!cJSON_IsString(detail) && !cJSON_IsNull(detail))
    {
    goto end; //String
    }
    }

    // problem_details->instance
    cJSON *instance = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "instance");
    if (cJSON_IsNull(instance)) {
        instance = NULL;
    }
    if (instance) { 
    if(!cJSON_IsString(instance) && !cJSON_IsNull(instance))
    {
    goto end; //String
    }
    }

    // problem_details->cause
    cJSON *cause = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "cause");
    if (cJSON_IsNull(cause)) {
        cause = NULL;
    }
    if (cause) { 
    if(!cJSON_IsString(cause) && !cJSON_IsNull(cause))
    {
    goto end; //String
    }
    }

    // problem_details->invalid_params
    cJSON *invalid_params = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "invalidParams");
    if (cJSON_IsNull(invalid_params)) {
        invalid_params = NULL;
    }
    if (invalid_params) { 
    cJSON *invalid_params_local_nonprimitive = NULL;
    if(!cJSON_IsArray(invalid_params)){
        goto end; //nonprimitive container
    }

    invalid_paramsList = list_createList();

    cJSON_ArrayForEach(invalid_params_local_nonprimitive,invalid_params )
    {
        if(!cJSON_IsObject(invalid_params_local_nonprimitive)){
            goto end;
        }
        invalid_param_t *invalid_paramsItem = invalid_param_parseFromJSON(invalid_params_local_nonprimitive);

        list_addElement(invalid_paramsList, invalid_paramsItem);
    }
    }

    // problem_details->supported_features
    cJSON *supported_features = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "supportedFeatures");
    if (cJSON_IsNull(supported_features)) {
        supported_features = NULL;
    }
    if (supported_features) { 
    if(!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features))
    {
    goto end; //String
    }
    }

    // problem_details->access_token_error
    cJSON *access_token_error = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "accessTokenError");
    if (cJSON_IsNull(access_token_error)) {
        access_token_error = NULL;
    }
    if (access_token_error) { 
    access_token_error_local_nonprim = access_token_err_parseFromJSON(access_token_error); //nonprimitive
    }

    // problem_details->access_token_request
    cJSON *access_token_request = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "accessTokenRequest");
    if (cJSON_IsNull(access_token_request)) {
        access_token_request = NULL;
    }
    if (access_token_request) { 
    access_token_request_local_nonprim = access_token_req_parseFromJSON(access_token_request); //nonprimitive
    }

    // problem_details->nrf_id
    cJSON *nrf_id = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "nrfId");
    if (cJSON_IsNull(nrf_id)) {
        nrf_id = NULL;
    }
    if (nrf_id) { 
    if(!cJSON_IsString(nrf_id) && !cJSON_IsNull(nrf_id))
    {
    goto end; //String
    }
    }

    // problem_details->supported_api_versions
    cJSON *supported_api_versions = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "supportedApiVersions");
    if (cJSON_IsNull(supported_api_versions)) {
        supported_api_versions = NULL;
    }
    if (supported_api_versions) { 
    cJSON *supported_api_versions_local = NULL;
    if(!cJSON_IsArray(supported_api_versions)) {
        goto end;//primitive container
    }
    supported_api_versionsList = list_createList();

    cJSON_ArrayForEach(supported_api_versions_local, supported_api_versions)
    {
        if(!cJSON_IsString(supported_api_versions_local))
        {
            goto end;
        }
        list_addElement(supported_api_versionsList , strdup(supported_api_versions_local->valuestring));
    }
    }

    // problem_details->no_profile_match_info
    cJSON *no_profile_match_info = cJSON_GetObjectItemCaseSensitive(problem_detailsJSON, "noProfileMatchInfo");
    if (cJSON_IsNull(no_profile_match_info)) {
        no_profile_match_info = NULL;
    }
    if (no_profile_match_info) { 
    no_profile_match_info_local_nonprim = no_profile_match_info_parseFromJSON(no_profile_match_info); //nonprimitive
    }


    if (type && !cJSON_IsNull(type)) type_local_str = strdup(type->valuestring);
    if (title && !cJSON_IsNull(title)) title_local_str = strdup(title->valuestring);
    if (detail && !cJSON_IsNull(detail)) detail_local_str = strdup(detail->valuestring);
    if (instance && !cJSON_IsNull(instance)) instance_local_str = strdup(instance->valuestring);
    if (cause && !cJSON_IsNull(cause)) cause_local_str = strdup(cause->valuestring);
    if (supported_features && !cJSON_IsNull(supported_features)) supported_features_local_str = strdup(supported_features->valuestring);
    if (nrf_id && !cJSON_IsNull(nrf_id)) nrf_id_local_str = strdup(nrf_id->valuestring);

    problem_details_local_var = problem_details_create_internal (
        type_local_str,
        title_local_str,
        status_local_var,
        detail_local_str,
        instance_local_str,
        cause_local_str,
        invalid_params ? invalid_paramsList : NULL,
        supported_features_local_str,
        access_token_error ? access_token_error_local_nonprim : NULL,
        access_token_request ? access_token_request_local_nonprim : NULL,
        nrf_id_local_str,
        supported_api_versions ? supported_api_versionsList : NULL,
        no_profile_match_info ? no_profile_match_info_local_nonprim : NULL
        );

    if (!problem_details_local_var) {
        goto end;
    }

    return problem_details_local_var;
end:
    if (type_local_str) {
        free(type_local_str);
        type_local_str = NULL;
    }
    if (title_local_str) {
        free(title_local_str);
        title_local_str = NULL;
    }
    if (status_local_var) {
        free(status_local_var);
        status_local_var = NULL;
    }
    if (detail_local_str) {
        free(detail_local_str);
        detail_local_str = NULL;
    }
    if (instance_local_str) {
        free(instance_local_str);
        instance_local_str = NULL;
    }
    if (cause_local_str) {
        free(cause_local_str);
        cause_local_str = NULL;
    }
    if (invalid_paramsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, invalid_paramsList) {
            invalid_param_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(invalid_paramsList);
        invalid_paramsList = NULL;
    }
    if (supported_features_local_str) {
        free(supported_features_local_str);
        supported_features_local_str = NULL;
    }
    if (access_token_error_local_nonprim) {
        access_token_err_free(access_token_error_local_nonprim);
        access_token_error_local_nonprim = NULL;
    }
    if (access_token_request_local_nonprim) {
        access_token_req_free(access_token_request_local_nonprim);
        access_token_request_local_nonprim = NULL;
    }
    if (nrf_id_local_str) {
        free(nrf_id_local_str);
        nrf_id_local_str = NULL;
    }
    if (supported_api_versionsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, supported_api_versionsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(supported_api_versionsList);
        supported_api_versionsList = NULL;
    }
    if (no_profile_match_info_local_nonprim) {
        no_profile_match_info_free(no_profile_match_info_local_nonprim);
        no_profile_match_info_local_nonprim = NULL;
    }
    return NULL;

}
