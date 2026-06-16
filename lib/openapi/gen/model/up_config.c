
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_config.h"

OpenAPI_up_config_t *OpenAPI_up_config_create(
    char *up_notify_call_back_uri,
    char *notif_correlation_id,
    char *supi,
    char *gpsi,
    bool is_amf_reallocation_ind,
    int amf_reallocation_ind,
    OpenAPI_lcs_up_connection_ind_t *lcs_up_connection_ind,
    char *target_lmfid,
    OpenAPI_list_t *ue_up_pos_caps
)
{
    OpenAPI_up_config_t *up_config_local_var = ogs_malloc(sizeof(OpenAPI_up_config_t));
    ogs_assert(up_config_local_var);

    up_config_local_var->up_notify_call_back_uri = up_notify_call_back_uri;
    up_config_local_var->notif_correlation_id = notif_correlation_id;
    up_config_local_var->supi = supi;
    up_config_local_var->gpsi = gpsi;
    up_config_local_var->is_amf_reallocation_ind = is_amf_reallocation_ind;
    up_config_local_var->amf_reallocation_ind = amf_reallocation_ind;
    up_config_local_var->lcs_up_connection_ind = lcs_up_connection_ind;
    up_config_local_var->target_lmfid = target_lmfid;
    up_config_local_var->ue_up_pos_caps = ue_up_pos_caps;

    return up_config_local_var;
}

void OpenAPI_up_config_free(OpenAPI_up_config_t *up_config)
{
    if (NULL == up_config) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(up_config->up_notify_call_back_uri);
    ogs_free(up_config->notif_correlation_id);
    ogs_free(up_config->supi);
    ogs_free(up_config->gpsi);
    OpenAPI_lcs_up_connection_ind_free(up_config->lcs_up_connection_ind);
    ogs_free(up_config->target_lmfid);
    OpenAPI_list_for_each(up_config->ue_up_pos_caps, node) {
        OpenAPI_ue_up_positioning_capabilities_free(node->data);
    }
    OpenAPI_list_free(up_config->ue_up_pos_caps);
    ogs_free(up_config);
}

cJSON *OpenAPI_up_config_convertToJSON(OpenAPI_up_config_t *up_config)
{
    cJSON *item = NULL;

    if (up_config == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [UpConfig]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddStringToObject(item, "upNotifyCallBackUri", up_config->up_notify_call_back_uri) == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [up_notify_call_back_uri]");
        goto end;
    }

    if (cJSON_AddStringToObject(item, "notifCorrelationId", up_config->notif_correlation_id) == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [notif_correlation_id]");
        goto end;
    }

    if (up_config->supi) {
    if (cJSON_AddStringToObject(item, "supi", up_config->supi) == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [supi]");
        goto end;
    }
    }

    if (up_config->gpsi) {
    if (cJSON_AddStringToObject(item, "gpsi", up_config->gpsi) == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [gpsi]");
        goto end;
    }
    }

    if (up_config->is_amf_reallocation_ind) {
    if (cJSON_AddBoolToObject(item, "amfReallocationInd", up_config->amf_reallocation_ind) == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [amf_reallocation_ind]");
        goto end;
    }
    }

    if (up_config->lcs_up_connection_ind) {
    cJSON *lcs_up_connection_ind_local_JSON = OpenAPI_lcs_up_connection_ind_convertToJSON(up_config->lcs_up_connection_ind);
    if (lcs_up_connection_ind_local_JSON == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [lcs_up_connection_ind]");
        goto end;
    }
    cJSON_AddItemToObject(item, "lcsUpConnectionInd", lcs_up_connection_ind_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [lcs_up_connection_ind]");
        goto end;
    }
    }

    if (up_config->target_lmfid) {
    if (cJSON_AddStringToObject(item, "targetLMFId", up_config->target_lmfid) == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [target_lmfid]");
        goto end;
    }
    }

    if (up_config->ue_up_pos_caps) {
    cJSON *ue_up_pos_capsList = cJSON_AddArrayToObject(item, "ueUpPosCaps");
    if (ue_up_pos_capsList == NULL) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed [ue_up_pos_caps]");
        goto end;
    }

    OpenAPI_lnode_t *ue_up_pos_caps_node;
    if (up_config->ue_up_pos_caps) {
        OpenAPI_list_for_each(up_config->ue_up_pos_caps, ue_up_pos_caps_node) {
            cJSON *itemLocal = OpenAPI_ue_up_positioning_capabilities_convertToJSON(ue_up_pos_caps_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_up_config_convertToJSON() failed [ue_up_pos_caps]");
                goto end;
            }
            cJSON_AddItemToArray(ue_up_pos_capsList, itemLocal);
        }
    }
    }

end:
    return item;
}

OpenAPI_up_config_t *OpenAPI_up_config_parseFromJSON(cJSON *up_configJSON)
{
    OpenAPI_up_config_t *up_config_local_var = NULL;
    cJSON *up_notify_call_back_uri = cJSON_GetObjectItemCaseSensitive(up_configJSON, "upNotifyCallBackUri");
    if (!up_notify_call_back_uri) {
        ogs_error("OpenAPI_up_config_parseFromJSON() failed [up_notify_call_back_uri]");
        goto end;
    }

    if (!cJSON_IsString(up_notify_call_back_uri)) {
        ogs_error("OpenAPI_up_config_parseFromJSON() failed [up_notify_call_back_uri]");
        goto end;
    }

    cJSON *notif_correlation_id = cJSON_GetObjectItemCaseSensitive(up_configJSON, "notifCorrelationId");
    if (!notif_correlation_id) {
        ogs_error("OpenAPI_up_config_parseFromJSON() failed [notif_correlation_id]");
        goto end;
    }

    if (!cJSON_IsString(notif_correlation_id)) {
        ogs_error("OpenAPI_up_config_parseFromJSON() failed [notif_correlation_id]");
        goto end;
    }

    cJSON *supi = cJSON_GetObjectItemCaseSensitive(up_configJSON, "supi");

    if (supi) {
    if (!cJSON_IsString(supi)) {
        ogs_error("OpenAPI_up_config_parseFromJSON() failed [supi]");
        goto end;
    }
    }

    cJSON *gpsi = cJSON_GetObjectItemCaseSensitive(up_configJSON, "gpsi");

    if (gpsi) {
    if (!cJSON_IsString(gpsi)) {
        ogs_error("OpenAPI_up_config_parseFromJSON() failed [gpsi]");
        goto end;
    }
    }

    cJSON *amf_reallocation_ind = cJSON_GetObjectItemCaseSensitive(up_configJSON, "amfReallocationInd");

    if (amf_reallocation_ind) {
    if (!cJSON_IsBool(amf_reallocation_ind)) {
        ogs_error("OpenAPI_up_config_parseFromJSON() failed [amf_reallocation_ind]");
        goto end;
    }
    }

    cJSON *lcs_up_connection_ind = cJSON_GetObjectItemCaseSensitive(up_configJSON, "lcsUpConnectionInd");

    OpenAPI_lcs_up_connection_ind_t *lcs_up_connection_ind_local_nonprim = NULL;
    if (lcs_up_connection_ind) {
    lcs_up_connection_ind_local_nonprim = OpenAPI_lcs_up_connection_ind_parseFromJSON(lcs_up_connection_ind);
    }

    cJSON *target_lmfid = cJSON_GetObjectItemCaseSensitive(up_configJSON, "targetLMFId");

    if (target_lmfid) {
    if (!cJSON_IsString(target_lmfid)) {
        ogs_error("OpenAPI_up_config_parseFromJSON() failed [target_lmfid]");
        goto end;
    }
    }

    cJSON *ue_up_pos_caps = cJSON_GetObjectItemCaseSensitive(up_configJSON, "ueUpPosCaps");

    OpenAPI_list_t *ue_up_pos_capsList;
    if (ue_up_pos_caps) {
    cJSON *ue_up_pos_caps_local_nonprimitive;
    if (!cJSON_IsArray(ue_up_pos_caps)){
        ogs_error("OpenAPI_up_config_parseFromJSON() failed [ue_up_pos_caps]");
        goto end;
    }

    ue_up_pos_capsList = OpenAPI_list_create();

    cJSON_ArrayForEach(ue_up_pos_caps_local_nonprimitive, ue_up_pos_caps ) {
        if (!cJSON_IsObject(ue_up_pos_caps_local_nonprimitive)) {
            ogs_error("OpenAPI_up_config_parseFromJSON() failed [ue_up_pos_caps]");
            goto end;
        }
        OpenAPI_ue_up_positioning_capabilities_t *ue_up_pos_capsItem = OpenAPI_ue_up_positioning_capabilities_parseFromJSON(ue_up_pos_caps_local_nonprimitive);

        if (!ue_up_pos_capsItem) {
            ogs_error("No ue_up_pos_capsItem");
            OpenAPI_list_free(ue_up_pos_capsList);
            goto end;
        }

        OpenAPI_list_add(ue_up_pos_capsList, ue_up_pos_capsItem);
    }
    }

    up_config_local_var = OpenAPI_up_config_create (
        ogs_strdup(up_notify_call_back_uri->valuestring),
        ogs_strdup(notif_correlation_id->valuestring),
        supi ? ogs_strdup(supi->valuestring) : NULL,
        gpsi ? ogs_strdup(gpsi->valuestring) : NULL,
        amf_reallocation_ind ? true : false,
        amf_reallocation_ind ? amf_reallocation_ind->valueint : 0,
        lcs_up_connection_ind ? lcs_up_connection_ind_local_nonprim : NULL,
        target_lmfid ? ogs_strdup(target_lmfid->valuestring) : NULL,
        ue_up_pos_caps ? ue_up_pos_capsList : NULL
    );

    return up_config_local_var;
end:
    return NULL;
}

OpenAPI_up_config_t *OpenAPI_up_config_copy(OpenAPI_up_config_t *dst, OpenAPI_up_config_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_up_config_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_up_config_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_up_config_free(dst);
    dst = OpenAPI_up_config_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

