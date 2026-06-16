
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_notification.h"

OpenAPI_lmf_data_exposure_notification_t *OpenAPI_lmf_data_exposure_notification_create(
    char *notify_correlation_id,
    OpenAPI_list_t *reports
)
{
    OpenAPI_lmf_data_exposure_notification_t *lmf_data_exposure_notification_local_var = ogs_malloc(sizeof(OpenAPI_lmf_data_exposure_notification_t));
    ogs_assert(lmf_data_exposure_notification_local_var);

    lmf_data_exposure_notification_local_var->notify_correlation_id = notify_correlation_id;
    lmf_data_exposure_notification_local_var->reports = reports;

    return lmf_data_exposure_notification_local_var;
}

void OpenAPI_lmf_data_exposure_notification_free(OpenAPI_lmf_data_exposure_notification_t *lmf_data_exposure_notification)
{
    if (NULL == lmf_data_exposure_notification) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(lmf_data_exposure_notification->notify_correlation_id);
    OpenAPI_list_for_each(lmf_data_exposure_notification->reports, node) {
        OpenAPI_lmf_data_exposure_report_free(node->data);
    }
    OpenAPI_list_free(lmf_data_exposure_notification->reports);
    ogs_free(lmf_data_exposure_notification);
}

cJSON *OpenAPI_lmf_data_exposure_notification_convertToJSON(OpenAPI_lmf_data_exposure_notification_t *lmf_data_exposure_notification)
{
    cJSON *item = NULL;

    if (lmf_data_exposure_notification == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_notification_convertToJSON() failed [LmfDataExposureNotification]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddStringToObject(item, "notifyCorrelationId", lmf_data_exposure_notification->notify_correlation_id) == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_notification_convertToJSON() failed [notify_correlation_id]");
        goto end;
    }

    cJSON *reportsList = cJSON_AddArrayToObject(item, "reports");
    if (reportsList == NULL) {
        ogs_error("OpenAPI_lmf_data_exposure_notification_convertToJSON() failed [reports]");
        goto end;
    }

    OpenAPI_lnode_t *reports_node;
    if (lmf_data_exposure_notification->reports) {
        OpenAPI_list_for_each(lmf_data_exposure_notification->reports, reports_node) {
            cJSON *itemLocal = OpenAPI_lmf_data_exposure_report_convertToJSON(reports_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_lmf_data_exposure_notification_convertToJSON() failed [reports]");
                goto end;
            }
            cJSON_AddItemToArray(reportsList, itemLocal);
        }
    }

end:
    return item;
}

OpenAPI_lmf_data_exposure_notification_t *OpenAPI_lmf_data_exposure_notification_parseFromJSON(cJSON *lmf_data_exposure_notificationJSON)
{
    OpenAPI_lmf_data_exposure_notification_t *lmf_data_exposure_notification_local_var = NULL;
    cJSON *notify_correlation_id = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_notificationJSON, "notifyCorrelationId");
    if (!notify_correlation_id) {
        ogs_error("OpenAPI_lmf_data_exposure_notification_parseFromJSON() failed [notify_correlation_id]");
        goto end;
    }

    if (!cJSON_IsString(notify_correlation_id)) {
        ogs_error("OpenAPI_lmf_data_exposure_notification_parseFromJSON() failed [notify_correlation_id]");
        goto end;
    }

    cJSON *reports = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_notificationJSON, "reports");
    if (!reports) {
        ogs_error("OpenAPI_lmf_data_exposure_notification_parseFromJSON() failed [reports]");
        goto end;
    }

    OpenAPI_list_t *reportsList;
    cJSON *reports_local_nonprimitive;
    if (!cJSON_IsArray(reports)){
        ogs_error("OpenAPI_lmf_data_exposure_notification_parseFromJSON() failed [reports]");
        goto end;
    }

    reportsList = OpenAPI_list_create();

    cJSON_ArrayForEach(reports_local_nonprimitive, reports ) {
        if (!cJSON_IsObject(reports_local_nonprimitive)) {
            ogs_error("OpenAPI_lmf_data_exposure_notification_parseFromJSON() failed [reports]");
            goto end;
        }
        OpenAPI_lmf_data_exposure_report_t *reportsItem = OpenAPI_lmf_data_exposure_report_parseFromJSON(reports_local_nonprimitive);

        if (!reportsItem) {
            ogs_error("No reportsItem");
            OpenAPI_list_free(reportsList);
            goto end;
        }

        OpenAPI_list_add(reportsList, reportsItem);
    }

    lmf_data_exposure_notification_local_var = OpenAPI_lmf_data_exposure_notification_create (
        ogs_strdup(notify_correlation_id->valuestring),
        reportsList
    );

    return lmf_data_exposure_notification_local_var;
end:
    return NULL;
}

OpenAPI_lmf_data_exposure_notification_t *OpenAPI_lmf_data_exposure_notification_copy(OpenAPI_lmf_data_exposure_notification_t *dst, OpenAPI_lmf_data_exposure_notification_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_lmf_data_exposure_notification_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_lmf_data_exposure_notification_convertToJSON() failed");
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

    OpenAPI_lmf_data_exposure_notification_free(dst);
    dst = OpenAPI_lmf_data_exposure_notification_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

