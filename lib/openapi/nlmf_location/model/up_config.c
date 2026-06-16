#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_config.h"



static up_config_t *up_config_create_internal(
    char *up_notify_call_back_uri,
    char *notif_correlation_id,
    char *supi,
    char *gpsi,
    int *amf_reallocation_ind,
    lcs_up_connection_ind_t *lcs_up_connection_ind,
    char *target_lmfid,
    list_t *ue_up_pos_caps
    ) {
    up_config_t *up_config_local_var = malloc(sizeof(up_config_t));
    if (!up_config_local_var) {
        return NULL;
    }
    memset(up_config_local_var, 0, sizeof(up_config_t));
    up_config_local_var->_library_owned = 1;
    up_config_local_var->up_notify_call_back_uri = up_notify_call_back_uri;
    up_config_local_var->notif_correlation_id = notif_correlation_id;
    up_config_local_var->supi = supi;
    up_config_local_var->gpsi = gpsi;
    up_config_local_var->amf_reallocation_ind = amf_reallocation_ind;
    up_config_local_var->lcs_up_connection_ind = lcs_up_connection_ind;
    up_config_local_var->target_lmfid = target_lmfid;
    up_config_local_var->ue_up_pos_caps = ue_up_pos_caps;
    return up_config_local_var;
}

__attribute__((deprecated)) up_config_t *up_config_create(
    char *up_notify_call_back_uri,
    char *notif_correlation_id,
    char *supi,
    char *gpsi,
    int *amf_reallocation_ind,
    lcs_up_connection_ind_t *lcs_up_connection_ind,
    char *target_lmfid,
    list_t *ue_up_pos_caps
    ) {
    int *amf_reallocation_ind_copy = NULL;
    if (amf_reallocation_ind) {
        amf_reallocation_ind_copy = malloc(sizeof(int));
        if (amf_reallocation_ind_copy) *amf_reallocation_ind_copy = *amf_reallocation_ind;
    }
    up_config_t *result = up_config_create_internal (
        up_notify_call_back_uri,
        notif_correlation_id,
        supi,
        gpsi,
        amf_reallocation_ind_copy,
        lcs_up_connection_ind,
        target_lmfid,
        ue_up_pos_caps
        );
    if (!result) {
        free(amf_reallocation_ind_copy);
    }
    return result;
}

void up_config_free(up_config_t *up_config) {
    if(NULL == up_config){
        return ;
    }
    if(up_config->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "up_config_free");
        return ;
    }
    listEntry_t *listEntry;
    if (up_config->up_notify_call_back_uri) {
        free(up_config->up_notify_call_back_uri);
        up_config->up_notify_call_back_uri = NULL;
    }
    if (up_config->notif_correlation_id) {
        free(up_config->notif_correlation_id);
        up_config->notif_correlation_id = NULL;
    }
    if (up_config->supi) {
        free(up_config->supi);
        up_config->supi = NULL;
    }
    if (up_config->gpsi) {
        free(up_config->gpsi);
        up_config->gpsi = NULL;
    }
    if (up_config->amf_reallocation_ind) {
        free(up_config->amf_reallocation_ind);
        up_config->amf_reallocation_ind = NULL;
    }
    if (up_config->lcs_up_connection_ind) {
        lcs_up_connection_ind_free(up_config->lcs_up_connection_ind);
        up_config->lcs_up_connection_ind = NULL;
    }
    if (up_config->target_lmfid) {
        free(up_config->target_lmfid);
        up_config->target_lmfid = NULL;
    }
    if (up_config->ue_up_pos_caps) {
        list_ForEach(listEntry, up_config->ue_up_pos_caps) {
            ue_up_positioning_capabilities_free(listEntry->data);
        }
        list_freeList(up_config->ue_up_pos_caps);
        up_config->ue_up_pos_caps = NULL;
    }
    free(up_config);
}

cJSON *up_config_convertToJSON(up_config_t *up_config) {
    cJSON *item = cJSON_CreateObject();

    // up_config->up_notify_call_back_uri
    if (!up_config->up_notify_call_back_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "upNotifyCallBackUri", up_config->up_notify_call_back_uri) == NULL) {
    goto fail; //String
    }


    // up_config->notif_correlation_id
    if (!up_config->notif_correlation_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "notifCorrelationId", up_config->notif_correlation_id) == NULL) {
    goto fail; //String
    }


    // up_config->supi
    if(up_config->supi) {
    if(cJSON_AddStringToObject(item, "supi", up_config->supi) == NULL) {
    goto fail; //String
    }
    }


    // up_config->gpsi
    if(up_config->gpsi) {
    if(cJSON_AddStringToObject(item, "gpsi", up_config->gpsi) == NULL) {
    goto fail; //String
    }
    }


    // up_config->amf_reallocation_ind
    if(up_config->amf_reallocation_ind) {
    if(cJSON_AddBoolToObject(item, "amfReallocationInd", *up_config->amf_reallocation_ind) == NULL) {
    goto fail; //Bool
    }
    }


    // up_config->lcs_up_connection_ind
    if(up_config->lcs_up_connection_ind) {
    cJSON *lcs_up_connection_ind_local_JSON = lcs_up_connection_ind_convertToJSON(up_config->lcs_up_connection_ind);
    if(lcs_up_connection_ind_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "lcsUpConnectionInd", lcs_up_connection_ind_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // up_config->target_lmfid
    if(up_config->target_lmfid) {
    if(cJSON_AddStringToObject(item, "targetLMFId", up_config->target_lmfid) == NULL) {
    goto fail; //String
    }
    }


    // up_config->ue_up_pos_caps
    if(up_config->ue_up_pos_caps) {
    cJSON *ue_up_pos_caps = cJSON_AddArrayToObject(item, "ueUpPosCaps");
    if(ue_up_pos_caps == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ue_up_pos_capsListEntry;
    if (up_config->ue_up_pos_caps) {
    list_ForEach(ue_up_pos_capsListEntry, up_config->ue_up_pos_caps) {
    cJSON *itemLocal = ue_up_positioning_capabilities_convertToJSON(ue_up_pos_capsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ue_up_pos_caps, itemLocal);
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

up_config_t *up_config_parseFromJSON(cJSON *up_configJSON){

    up_config_t *up_config_local_var = NULL;

    char *up_notify_call_back_uri_local_str = NULL;

    char *notif_correlation_id_local_str = NULL;

    char *supi_local_str = NULL;

    char *gpsi_local_str = NULL;

    // define the local variable for up_config->amf_reallocation_ind
    int *amf_reallocation_ind_local_var = NULL;

    // define the local variable for up_config->lcs_up_connection_ind
    lcs_up_connection_ind_t *lcs_up_connection_ind_local_nonprim = NULL;

    char *target_lmfid_local_str = NULL;

    // define the local list for up_config->ue_up_pos_caps
    list_t *ue_up_pos_capsList = NULL;

    // up_config->up_notify_call_back_uri
    cJSON *up_notify_call_back_uri = cJSON_GetObjectItemCaseSensitive(up_configJSON, "upNotifyCallBackUri");
    if (cJSON_IsNull(up_notify_call_back_uri)) {
        up_notify_call_back_uri = NULL;
    }
    if (!up_notify_call_back_uri) {
        goto end;
    }

    
    if(!cJSON_IsString(up_notify_call_back_uri))
    {
    goto end; //String
    }

    // up_config->notif_correlation_id
    cJSON *notif_correlation_id = cJSON_GetObjectItemCaseSensitive(up_configJSON, "notifCorrelationId");
    if (cJSON_IsNull(notif_correlation_id)) {
        notif_correlation_id = NULL;
    }
    if (!notif_correlation_id) {
        goto end;
    }

    
    if(!cJSON_IsString(notif_correlation_id))
    {
    goto end; //String
    }

    // up_config->supi
    cJSON *supi = cJSON_GetObjectItemCaseSensitive(up_configJSON, "supi");
    if (cJSON_IsNull(supi)) {
        supi = NULL;
    }
    if (supi) { 
    if(!cJSON_IsString(supi) && !cJSON_IsNull(supi))
    {
    goto end; //String
    }
    }

    // up_config->gpsi
    cJSON *gpsi = cJSON_GetObjectItemCaseSensitive(up_configJSON, "gpsi");
    if (cJSON_IsNull(gpsi)) {
        gpsi = NULL;
    }
    if (gpsi) { 
    if(!cJSON_IsString(gpsi) && !cJSON_IsNull(gpsi))
    {
    goto end; //String
    }
    }

    // up_config->amf_reallocation_ind
    cJSON *amf_reallocation_ind = cJSON_GetObjectItemCaseSensitive(up_configJSON, "amfReallocationInd");
    if (cJSON_IsNull(amf_reallocation_ind)) {
        amf_reallocation_ind = NULL;
    }
    if (amf_reallocation_ind) { 
    if(!cJSON_IsBool(amf_reallocation_ind))
    {
    goto end; //Bool
    }
    amf_reallocation_ind_local_var = malloc(sizeof(int));
    if(!amf_reallocation_ind_local_var)
    {
        goto end;
    }
    *amf_reallocation_ind_local_var = amf_reallocation_ind->valueint;
    }

    // up_config->lcs_up_connection_ind
    cJSON *lcs_up_connection_ind = cJSON_GetObjectItemCaseSensitive(up_configJSON, "lcsUpConnectionInd");
    if (cJSON_IsNull(lcs_up_connection_ind)) {
        lcs_up_connection_ind = NULL;
    }
    if (lcs_up_connection_ind) { 
    lcs_up_connection_ind_local_nonprim = lcs_up_connection_ind_parseFromJSON(lcs_up_connection_ind); //nonprimitive
    }

    // up_config->target_lmfid
    cJSON *target_lmfid = cJSON_GetObjectItemCaseSensitive(up_configJSON, "targetLMFId");
    if (cJSON_IsNull(target_lmfid)) {
        target_lmfid = NULL;
    }
    if (target_lmfid) { 
    if(!cJSON_IsString(target_lmfid) && !cJSON_IsNull(target_lmfid))
    {
    goto end; //String
    }
    }

    // up_config->ue_up_pos_caps
    cJSON *ue_up_pos_caps = cJSON_GetObjectItemCaseSensitive(up_configJSON, "ueUpPosCaps");
    if (cJSON_IsNull(ue_up_pos_caps)) {
        ue_up_pos_caps = NULL;
    }
    if (ue_up_pos_caps) { 
    cJSON *ue_up_pos_caps_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ue_up_pos_caps)){
        goto end; //nonprimitive container
    }

    ue_up_pos_capsList = list_createList();

    cJSON_ArrayForEach(ue_up_pos_caps_local_nonprimitive,ue_up_pos_caps )
    {
        if(!cJSON_IsObject(ue_up_pos_caps_local_nonprimitive)){
            goto end;
        }
        ue_up_positioning_capabilities_t *ue_up_pos_capsItem = ue_up_positioning_capabilities_parseFromJSON(ue_up_pos_caps_local_nonprimitive);

        list_addElement(ue_up_pos_capsList, ue_up_pos_capsItem);
    }
    }


    if (up_notify_call_back_uri && !cJSON_IsNull(up_notify_call_back_uri)) up_notify_call_back_uri_local_str = strdup(up_notify_call_back_uri->valuestring);
    if (notif_correlation_id && !cJSON_IsNull(notif_correlation_id)) notif_correlation_id_local_str = strdup(notif_correlation_id->valuestring);
    if (supi && !cJSON_IsNull(supi)) supi_local_str = strdup(supi->valuestring);
    if (gpsi && !cJSON_IsNull(gpsi)) gpsi_local_str = strdup(gpsi->valuestring);
    if (target_lmfid && !cJSON_IsNull(target_lmfid)) target_lmfid_local_str = strdup(target_lmfid->valuestring);

    up_config_local_var = up_config_create_internal (
        up_notify_call_back_uri_local_str,
        notif_correlation_id_local_str,
        supi_local_str,
        gpsi_local_str,
        amf_reallocation_ind_local_var,
        lcs_up_connection_ind ? lcs_up_connection_ind_local_nonprim : NULL,
        target_lmfid_local_str,
        ue_up_pos_caps ? ue_up_pos_capsList : NULL
        );

    if (!up_config_local_var) {
        goto end;
    }

    return up_config_local_var;
end:
    if (up_notify_call_back_uri_local_str) {
        free(up_notify_call_back_uri_local_str);
        up_notify_call_back_uri_local_str = NULL;
    }
    if (notif_correlation_id_local_str) {
        free(notif_correlation_id_local_str);
        notif_correlation_id_local_str = NULL;
    }
    if (supi_local_str) {
        free(supi_local_str);
        supi_local_str = NULL;
    }
    if (gpsi_local_str) {
        free(gpsi_local_str);
        gpsi_local_str = NULL;
    }
    if (amf_reallocation_ind_local_var) {
        free(amf_reallocation_ind_local_var);
        amf_reallocation_ind_local_var = NULL;
    }
    if (lcs_up_connection_ind_local_nonprim) {
        lcs_up_connection_ind_free(lcs_up_connection_ind_local_nonprim);
        lcs_up_connection_ind_local_nonprim = NULL;
    }
    if (target_lmfid_local_str) {
        free(target_lmfid_local_str);
        target_lmfid_local_str = NULL;
    }
    if (ue_up_pos_capsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ue_up_pos_capsList) {
            ue_up_positioning_capabilities_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ue_up_pos_capsList);
        ue_up_pos_capsList = NULL;
    }
    return NULL;

}
