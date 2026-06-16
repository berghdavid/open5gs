#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_notify_data.h"



static up_notify_data_t *up_notify_data_create_internal(
    char *notif_correlation_id,
    up_connection_status_t *up_connection_status,
    char *target_lmfid
    ) {
    up_notify_data_t *up_notify_data_local_var = malloc(sizeof(up_notify_data_t));
    if (!up_notify_data_local_var) {
        return NULL;
    }
    memset(up_notify_data_local_var, 0, sizeof(up_notify_data_t));
    up_notify_data_local_var->_library_owned = 1;
    up_notify_data_local_var->notif_correlation_id = notif_correlation_id;
    up_notify_data_local_var->up_connection_status = up_connection_status;
    up_notify_data_local_var->target_lmfid = target_lmfid;
    return up_notify_data_local_var;
}

__attribute__((deprecated)) up_notify_data_t *up_notify_data_create(
    char *notif_correlation_id,
    up_connection_status_t *up_connection_status,
    char *target_lmfid
    ) {
    up_notify_data_t *result = up_notify_data_create_internal (
        notif_correlation_id,
        up_connection_status,
        target_lmfid
        );
    if (!result) {
    }
    return result;
}

void up_notify_data_free(up_notify_data_t *up_notify_data) {
    if(NULL == up_notify_data){
        return ;
    }
    if(up_notify_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "up_notify_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (up_notify_data->notif_correlation_id) {
        free(up_notify_data->notif_correlation_id);
        up_notify_data->notif_correlation_id = NULL;
    }
    if (up_notify_data->up_connection_status) {
        up_connection_status_free(up_notify_data->up_connection_status);
        up_notify_data->up_connection_status = NULL;
    }
    if (up_notify_data->target_lmfid) {
        free(up_notify_data->target_lmfid);
        up_notify_data->target_lmfid = NULL;
    }
    free(up_notify_data);
}

cJSON *up_notify_data_convertToJSON(up_notify_data_t *up_notify_data) {
    cJSON *item = cJSON_CreateObject();

    // up_notify_data->notif_correlation_id
    if (!up_notify_data->notif_correlation_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "notifCorrelationId", up_notify_data->notif_correlation_id) == NULL) {
    goto fail; //String
    }


    // up_notify_data->up_connection_status
    if (!up_notify_data->up_connection_status) {
        goto fail;
    }
    cJSON *up_connection_status_local_JSON = up_connection_status_convertToJSON(up_notify_data->up_connection_status);
    if(up_connection_status_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "upConnectionStatus", up_connection_status_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // up_notify_data->target_lmfid
    if(up_notify_data->target_lmfid) {
    if(cJSON_AddStringToObject(item, "targetLMFId", up_notify_data->target_lmfid) == NULL) {
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

up_notify_data_t *up_notify_data_parseFromJSON(cJSON *up_notify_dataJSON){

    up_notify_data_t *up_notify_data_local_var = NULL;

    char *notif_correlation_id_local_str = NULL;

    // define the local variable for up_notify_data->up_connection_status
    up_connection_status_t *up_connection_status_local_nonprim = NULL;

    char *target_lmfid_local_str = NULL;

    // up_notify_data->notif_correlation_id
    cJSON *notif_correlation_id = cJSON_GetObjectItemCaseSensitive(up_notify_dataJSON, "notifCorrelationId");
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

    // up_notify_data->up_connection_status
    cJSON *up_connection_status = cJSON_GetObjectItemCaseSensitive(up_notify_dataJSON, "upConnectionStatus");
    if (cJSON_IsNull(up_connection_status)) {
        up_connection_status = NULL;
    }
    if (!up_connection_status) {
        goto end;
    }

    
    up_connection_status_local_nonprim = up_connection_status_parseFromJSON(up_connection_status); //nonprimitive

    // up_notify_data->target_lmfid
    cJSON *target_lmfid = cJSON_GetObjectItemCaseSensitive(up_notify_dataJSON, "targetLMFId");
    if (cJSON_IsNull(target_lmfid)) {
        target_lmfid = NULL;
    }
    if (target_lmfid) { 
    if(!cJSON_IsString(target_lmfid) && !cJSON_IsNull(target_lmfid))
    {
    goto end; //String
    }
    }


    if (notif_correlation_id && !cJSON_IsNull(notif_correlation_id)) notif_correlation_id_local_str = strdup(notif_correlation_id->valuestring);
    if (target_lmfid && !cJSON_IsNull(target_lmfid)) target_lmfid_local_str = strdup(target_lmfid->valuestring);

    up_notify_data_local_var = up_notify_data_create_internal (
        notif_correlation_id_local_str,
        up_connection_status_local_nonprim,
        target_lmfid_local_str
        );

    if (!up_notify_data_local_var) {
        goto end;
    }

    return up_notify_data_local_var;
end:
    if (notif_correlation_id_local_str) {
        free(notif_correlation_id_local_str);
        notif_correlation_id_local_str = NULL;
    }
    if (up_connection_status_local_nonprim) {
        up_connection_status_free(up_connection_status_local_nonprim);
        up_connection_status_local_nonprim = NULL;
    }
    if (target_lmfid_local_str) {
        free(target_lmfid_local_str);
        target_lmfid_local_str = NULL;
    }
    return NULL;

}
