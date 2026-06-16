#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lmf_data_exposure_notification.h"



static lmf_data_exposure_notification_t *lmf_data_exposure_notification_create_internal(
    char *notify_correlation_id,
    list_t *reports
    ) {
    lmf_data_exposure_notification_t *lmf_data_exposure_notification_local_var = malloc(sizeof(lmf_data_exposure_notification_t));
    if (!lmf_data_exposure_notification_local_var) {
        return NULL;
    }
    memset(lmf_data_exposure_notification_local_var, 0, sizeof(lmf_data_exposure_notification_t));
    lmf_data_exposure_notification_local_var->_library_owned = 1;
    lmf_data_exposure_notification_local_var->notify_correlation_id = notify_correlation_id;
    lmf_data_exposure_notification_local_var->reports = reports;
    return lmf_data_exposure_notification_local_var;
}

__attribute__((deprecated)) lmf_data_exposure_notification_t *lmf_data_exposure_notification_create(
    char *notify_correlation_id,
    list_t *reports
    ) {
    lmf_data_exposure_notification_t *result = lmf_data_exposure_notification_create_internal (
        notify_correlation_id,
        reports
        );
    if (!result) {
    }
    return result;
}

void lmf_data_exposure_notification_free(lmf_data_exposure_notification_t *lmf_data_exposure_notification) {
    if(NULL == lmf_data_exposure_notification){
        return ;
    }
    if(lmf_data_exposure_notification->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lmf_data_exposure_notification_free");
        return ;
    }
    listEntry_t *listEntry;
    if (lmf_data_exposure_notification->notify_correlation_id) {
        free(lmf_data_exposure_notification->notify_correlation_id);
        lmf_data_exposure_notification->notify_correlation_id = NULL;
    }
    if (lmf_data_exposure_notification->reports) {
        list_ForEach(listEntry, lmf_data_exposure_notification->reports) {
            lmf_data_exposure_report_free(listEntry->data);
        }
        list_freeList(lmf_data_exposure_notification->reports);
        lmf_data_exposure_notification->reports = NULL;
    }
    free(lmf_data_exposure_notification);
}

cJSON *lmf_data_exposure_notification_convertToJSON(lmf_data_exposure_notification_t *lmf_data_exposure_notification) {
    cJSON *item = cJSON_CreateObject();

    // lmf_data_exposure_notification->notify_correlation_id
    if (!lmf_data_exposure_notification->notify_correlation_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "notifyCorrelationId", lmf_data_exposure_notification->notify_correlation_id) == NULL) {
    goto fail; //String
    }


    // lmf_data_exposure_notification->reports
    if (!lmf_data_exposure_notification->reports) {
        goto fail;
    }
    cJSON *reports = cJSON_AddArrayToObject(item, "reports");
    if(reports == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *reportsListEntry;
    if (lmf_data_exposure_notification->reports) {
    list_ForEach(reportsListEntry, lmf_data_exposure_notification->reports) {
    cJSON *itemLocal = lmf_data_exposure_report_convertToJSON(reportsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(reports, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lmf_data_exposure_notification_t *lmf_data_exposure_notification_parseFromJSON(cJSON *lmf_data_exposure_notificationJSON){

    lmf_data_exposure_notification_t *lmf_data_exposure_notification_local_var = NULL;

    char *notify_correlation_id_local_str = NULL;

    // define the local list for lmf_data_exposure_notification->reports
    list_t *reportsList = NULL;

    // lmf_data_exposure_notification->notify_correlation_id
    cJSON *notify_correlation_id = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_notificationJSON, "notifyCorrelationId");
    if (cJSON_IsNull(notify_correlation_id)) {
        notify_correlation_id = NULL;
    }
    if (!notify_correlation_id) {
        goto end;
    }

    
    if(!cJSON_IsString(notify_correlation_id))
    {
    goto end; //String
    }

    // lmf_data_exposure_notification->reports
    cJSON *reports = cJSON_GetObjectItemCaseSensitive(lmf_data_exposure_notificationJSON, "reports");
    if (cJSON_IsNull(reports)) {
        reports = NULL;
    }
    if (!reports) {
        goto end;
    }

    
    cJSON *reports_local_nonprimitive = NULL;
    if(!cJSON_IsArray(reports)){
        goto end; //nonprimitive container
    }

    reportsList = list_createList();

    cJSON_ArrayForEach(reports_local_nonprimitive,reports )
    {
        if(!cJSON_IsObject(reports_local_nonprimitive)){
            goto end;
        }
        lmf_data_exposure_report_t *reportsItem = lmf_data_exposure_report_parseFromJSON(reports_local_nonprimitive);

        list_addElement(reportsList, reportsItem);
    }


    if (notify_correlation_id && !cJSON_IsNull(notify_correlation_id)) notify_correlation_id_local_str = strdup(notify_correlation_id->valuestring);

    lmf_data_exposure_notification_local_var = lmf_data_exposure_notification_create_internal (
        notify_correlation_id_local_str,
        reportsList
        );

    if (!lmf_data_exposure_notification_local_var) {
        goto end;
    }

    return lmf_data_exposure_notification_local_var;
end:
    if (notify_correlation_id_local_str) {
        free(notify_correlation_id_local_str);
        notify_correlation_id_local_str = NULL;
    }
    if (reportsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, reportsList) {
            lmf_data_exposure_report_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(reportsList);
        reportsList = NULL;
    }
    return NULL;

}
