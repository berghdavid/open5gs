
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_notify_data.h"

OpenAPI_up_notify_data_t *OpenAPI_up_notify_data_create(
    char *notif_correlation_id,
    OpenAPI_up_connection_status_t *up_connection_status,
    char *target_lmfid
)
{
    OpenAPI_up_notify_data_t *up_notify_data_local_var = ogs_malloc(sizeof(OpenAPI_up_notify_data_t));
    ogs_assert(up_notify_data_local_var);

    up_notify_data_local_var->notif_correlation_id = notif_correlation_id;
    up_notify_data_local_var->up_connection_status = up_connection_status;
    up_notify_data_local_var->target_lmfid = target_lmfid;

    return up_notify_data_local_var;
}

void OpenAPI_up_notify_data_free(OpenAPI_up_notify_data_t *up_notify_data)
{
    if (NULL == up_notify_data) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(up_notify_data->notif_correlation_id);
    OpenAPI_up_connection_status_free(up_notify_data->up_connection_status);
    ogs_free(up_notify_data->target_lmfid);
    ogs_free(up_notify_data);
}

cJSON *OpenAPI_up_notify_data_convertToJSON(OpenAPI_up_notify_data_t *up_notify_data)
{
    cJSON *item = NULL;

    if (up_notify_data == NULL) {
        ogs_error("OpenAPI_up_notify_data_convertToJSON() failed [UpNotifyData]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddStringToObject(item, "notifCorrelationId", up_notify_data->notif_correlation_id) == NULL) {
        ogs_error("OpenAPI_up_notify_data_convertToJSON() failed [notif_correlation_id]");
        goto end;
    }

    cJSON *up_connection_status_local_JSON = OpenAPI_up_connection_status_convertToJSON(up_notify_data->up_connection_status);
    if (up_connection_status_local_JSON == NULL) {
        ogs_error("OpenAPI_up_notify_data_convertToJSON() failed [up_connection_status]");
        goto end;
    }
    cJSON_AddItemToObject(item, "upConnectionStatus", up_connection_status_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_up_notify_data_convertToJSON() failed [up_connection_status]");
        goto end;
    }

    if (up_notify_data->target_lmfid) {
    if (cJSON_AddStringToObject(item, "targetLMFId", up_notify_data->target_lmfid) == NULL) {
        ogs_error("OpenAPI_up_notify_data_convertToJSON() failed [target_lmfid]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_up_notify_data_t *OpenAPI_up_notify_data_parseFromJSON(cJSON *up_notify_dataJSON)
{
    OpenAPI_up_notify_data_t *up_notify_data_local_var = NULL;
    cJSON *notif_correlation_id = cJSON_GetObjectItemCaseSensitive(up_notify_dataJSON, "notifCorrelationId");
    if (!notif_correlation_id) {
        ogs_error("OpenAPI_up_notify_data_parseFromJSON() failed [notif_correlation_id]");
        goto end;
    }

    if (!cJSON_IsString(notif_correlation_id)) {
        ogs_error("OpenAPI_up_notify_data_parseFromJSON() failed [notif_correlation_id]");
        goto end;
    }

    cJSON *up_connection_status = cJSON_GetObjectItemCaseSensitive(up_notify_dataJSON, "upConnectionStatus");
    if (!up_connection_status) {
        ogs_error("OpenAPI_up_notify_data_parseFromJSON() failed [up_connection_status]");
        goto end;
    }

    OpenAPI_up_connection_status_t *up_connection_status_local_nonprim = NULL;
    up_connection_status_local_nonprim = OpenAPI_up_connection_status_parseFromJSON(up_connection_status);

    cJSON *target_lmfid = cJSON_GetObjectItemCaseSensitive(up_notify_dataJSON, "targetLMFId");

    if (target_lmfid) {
    if (!cJSON_IsString(target_lmfid)) {
        ogs_error("OpenAPI_up_notify_data_parseFromJSON() failed [target_lmfid]");
        goto end;
    }
    }

    up_notify_data_local_var = OpenAPI_up_notify_data_create (
        ogs_strdup(notif_correlation_id->valuestring),
        up_connection_status_local_nonprim,
        target_lmfid ? ogs_strdup(target_lmfid->valuestring) : NULL
    );

    return up_notify_data_local_var;
end:
    return NULL;
}

OpenAPI_up_notify_data_t *OpenAPI_up_notify_data_copy(OpenAPI_up_notify_data_t *dst, OpenAPI_up_notify_data_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_up_notify_data_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_up_notify_data_convertToJSON() failed");
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

    OpenAPI_up_notify_data_free(dst);
    dst = OpenAPI_up_notify_data_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

