#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "redirect_response.h"



static redirect_response_t *redirect_response_create_internal(
    char *cause,
    char *target_scp,
    char *target_sepp
    ) {
    redirect_response_t *redirect_response_local_var = malloc(sizeof(redirect_response_t));
    if (!redirect_response_local_var) {
        return NULL;
    }
    memset(redirect_response_local_var, 0, sizeof(redirect_response_t));
    redirect_response_local_var->_library_owned = 1;
    redirect_response_local_var->cause = cause;
    redirect_response_local_var->target_scp = target_scp;
    redirect_response_local_var->target_sepp = target_sepp;
    return redirect_response_local_var;
}

__attribute__((deprecated)) redirect_response_t *redirect_response_create(
    char *cause,
    char *target_scp,
    char *target_sepp
    ) {
    redirect_response_t *result = redirect_response_create_internal (
        cause,
        target_scp,
        target_sepp
        );
    if (!result) {
    }
    return result;
}

void redirect_response_free(redirect_response_t *redirect_response) {
    if(NULL == redirect_response){
        return ;
    }
    if(redirect_response->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "redirect_response_free");
        return ;
    }
    listEntry_t *listEntry;
    if (redirect_response->cause) {
        free(redirect_response->cause);
        redirect_response->cause = NULL;
    }
    if (redirect_response->target_scp) {
        free(redirect_response->target_scp);
        redirect_response->target_scp = NULL;
    }
    if (redirect_response->target_sepp) {
        free(redirect_response->target_sepp);
        redirect_response->target_sepp = NULL;
    }
    free(redirect_response);
}

cJSON *redirect_response_convertToJSON(redirect_response_t *redirect_response) {
    cJSON *item = cJSON_CreateObject();

    // redirect_response->cause
    if(redirect_response->cause) {
    if(cJSON_AddStringToObject(item, "cause", redirect_response->cause) == NULL) {
    goto fail; //String
    }
    }


    // redirect_response->target_scp
    if(redirect_response->target_scp) {
    if(cJSON_AddStringToObject(item, "targetScp", redirect_response->target_scp) == NULL) {
    goto fail; //String
    }
    }


    // redirect_response->target_sepp
    if(redirect_response->target_sepp) {
    if(cJSON_AddStringToObject(item, "targetSepp", redirect_response->target_sepp) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

redirect_response_t *redirect_response_parseFromJSON(cJSON *redirect_responseJSON){

    redirect_response_t *redirect_response_local_var = NULL;

    char *cause_local_str = NULL;

    char *target_scp_local_str = NULL;

    char *target_sepp_local_str = NULL;

    // redirect_response->cause
    cJSON *cause = cJSON_GetObjectItemCaseSensitive(redirect_responseJSON, "cause");
    if (cJSON_IsNull(cause)) {
        cause = NULL;
    }
    if (cause) { 
    if(!cJSON_IsString(cause) && !cJSON_IsNull(cause))
    {
    goto end; //String
    }
    }

    // redirect_response->target_scp
    cJSON *target_scp = cJSON_GetObjectItemCaseSensitive(redirect_responseJSON, "targetScp");
    if (cJSON_IsNull(target_scp)) {
        target_scp = NULL;
    }
    if (target_scp) { 
    if(!cJSON_IsString(target_scp) && !cJSON_IsNull(target_scp))
    {
    goto end; //String
    }
    }

    // redirect_response->target_sepp
    cJSON *target_sepp = cJSON_GetObjectItemCaseSensitive(redirect_responseJSON, "targetSepp");
    if (cJSON_IsNull(target_sepp)) {
        target_sepp = NULL;
    }
    if (target_sepp) { 
    if(!cJSON_IsString(target_sepp) && !cJSON_IsNull(target_sepp))
    {
    goto end; //String
    }
    }


    if (cause && !cJSON_IsNull(cause)) cause_local_str = strdup(cause->valuestring);
    if (target_scp && !cJSON_IsNull(target_scp)) target_scp_local_str = strdup(target_scp->valuestring);
    if (target_sepp && !cJSON_IsNull(target_sepp)) target_sepp_local_str = strdup(target_sepp->valuestring);

    redirect_response_local_var = redirect_response_create_internal (
        cause_local_str,
        target_scp_local_str,
        target_sepp_local_str
        );

    if (!redirect_response_local_var) {
        goto end;
    }

    return redirect_response_local_var;
end:
    if (cause_local_str) {
        free(cause_local_str);
        cause_local_str = NULL;
    }
    if (target_scp_local_str) {
        free(target_scp_local_str);
        target_scp_local_str = NULL;
    }
    if (target_sepp_local_str) {
        free(target_sepp_local_str);
        target_sepp_local_str = NULL;
    }
    return NULL;

}
