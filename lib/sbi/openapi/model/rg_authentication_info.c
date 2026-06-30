
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "rg_authentication_info.h"

OpenAPI_rg_authentication_info_t *OpenAPI_rg_authentication_info_create(
    char *suci,
    int authenticated_ind,
    char *supported_features
)
{
    OpenAPI_rg_authentication_info_t *rg_authentication_info_local_var = ogs_malloc(sizeof(OpenAPI_rg_authentication_info_t));
    log_assert(rg_authentication_info_local_var);

    rg_authentication_info_local_var->suci = suci;
    rg_authentication_info_local_var->authenticated_ind = authenticated_ind;
    rg_authentication_info_local_var->supported_features = supported_features;

    return rg_authentication_info_local_var;
}

void OpenAPI_rg_authentication_info_free(OpenAPI_rg_authentication_info_t *rg_authentication_info)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == rg_authentication_info) {
        return;
    }
    if (rg_authentication_info->suci) {
        ogs_free(rg_authentication_info->suci);
        rg_authentication_info->suci = NULL;
    }
    if (rg_authentication_info->supported_features) {
        ogs_free(rg_authentication_info->supported_features);
        rg_authentication_info->supported_features = NULL;
    }
    ogs_free(rg_authentication_info);
}

cJSON *OpenAPI_rg_authentication_info_convertToJSON(OpenAPI_rg_authentication_info_t *rg_authentication_info)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (rg_authentication_info == NULL) {
        log_error("OpenAPI_rg_authentication_info_convertToJSON() failed [RgAuthenticationInfo]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!rg_authentication_info->suci) {
        log_error("OpenAPI_rg_authentication_info_convertToJSON() failed [suci]");
        return NULL;
    }
    if (cJSON_AddStringToObject(item, "suci", rg_authentication_info->suci) == NULL) {
        log_error("OpenAPI_rg_authentication_info_convertToJSON() failed [suci]");
        goto end;
    }

    if (cJSON_AddBoolToObject(item, "authenticatedInd", rg_authentication_info->authenticated_ind) == NULL) {
        log_error("OpenAPI_rg_authentication_info_convertToJSON() failed [authenticated_ind]");
        goto end;
    }

    if (rg_authentication_info->supported_features) {
    if (cJSON_AddStringToObject(item, "supportedFeatures", rg_authentication_info->supported_features) == NULL) {
        log_error("OpenAPI_rg_authentication_info_convertToJSON() failed [supported_features]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_rg_authentication_info_t *OpenAPI_rg_authentication_info_parseFromJSON(cJSON *rg_authentication_infoJSON)
{
    OpenAPI_rg_authentication_info_t *rg_authentication_info_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *suci = NULL;
    cJSON *authenticated_ind = NULL;
    cJSON *supported_features = NULL;
    suci = cJSON_GetObjectItemCaseSensitive(rg_authentication_infoJSON, "suci");
    if (!suci) {
        log_error("OpenAPI_rg_authentication_info_parseFromJSON() failed [suci]");
        goto end;
    }
    if (!cJSON_IsString(suci)) {
        log_error("OpenAPI_rg_authentication_info_parseFromJSON() failed [suci]");
        goto end;
    }

    authenticated_ind = cJSON_GetObjectItemCaseSensitive(rg_authentication_infoJSON, "authenticatedInd");
    if (!authenticated_ind) {
        log_error("OpenAPI_rg_authentication_info_parseFromJSON() failed [authenticated_ind]");
        goto end;
    }
    if (!cJSON_IsBool(authenticated_ind)) {
        log_error("OpenAPI_rg_authentication_info_parseFromJSON() failed [authenticated_ind]");
        goto end;
    }

    supported_features = cJSON_GetObjectItemCaseSensitive(rg_authentication_infoJSON, "supportedFeatures");
    if (supported_features) {
    if (!cJSON_IsString(supported_features) && !cJSON_IsNull(supported_features)) {
        log_error("OpenAPI_rg_authentication_info_parseFromJSON() failed [supported_features]");
        goto end;
    }
    }

    rg_authentication_info_local_var = OpenAPI_rg_authentication_info_create (
        ogs_strdup(suci->valuestring),
        
        authenticated_ind->valueint,
        supported_features && !cJSON_IsNull(supported_features) ? ogs_strdup(supported_features->valuestring) : NULL
    );

    return rg_authentication_info_local_var;
end:
    return NULL;
}

OpenAPI_rg_authentication_info_t *OpenAPI_rg_authentication_info_copy(OpenAPI_rg_authentication_info_t *dst, OpenAPI_rg_authentication_info_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_rg_authentication_info_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_rg_authentication_info_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        log_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        log_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_rg_authentication_info_free(dst);
    dst = OpenAPI_rg_authentication_info_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

