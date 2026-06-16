#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_subscription.h"



static up_subscription_t *up_subscription_create_internal(
    char *up_notify_call_back_uri,
    char *notif_correlation_id,
    char *supi,
    char *gpsi
    ) {
    up_subscription_t *up_subscription_local_var = malloc(sizeof(up_subscription_t));
    if (!up_subscription_local_var) {
        return NULL;
    }
    memset(up_subscription_local_var, 0, sizeof(up_subscription_t));
    up_subscription_local_var->_library_owned = 1;
    up_subscription_local_var->up_notify_call_back_uri = up_notify_call_back_uri;
    up_subscription_local_var->notif_correlation_id = notif_correlation_id;
    up_subscription_local_var->supi = supi;
    up_subscription_local_var->gpsi = gpsi;
    return up_subscription_local_var;
}

__attribute__((deprecated)) up_subscription_t *up_subscription_create(
    char *up_notify_call_back_uri,
    char *notif_correlation_id,
    char *supi,
    char *gpsi
    ) {
    up_subscription_t *result = up_subscription_create_internal (
        up_notify_call_back_uri,
        notif_correlation_id,
        supi,
        gpsi
        );
    if (!result) {
    }
    return result;
}

void up_subscription_free(up_subscription_t *up_subscription) {
    if(NULL == up_subscription){
        return ;
    }
    if(up_subscription->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "up_subscription_free");
        return ;
    }
    listEntry_t *listEntry;
    if (up_subscription->up_notify_call_back_uri) {
        free(up_subscription->up_notify_call_back_uri);
        up_subscription->up_notify_call_back_uri = NULL;
    }
    if (up_subscription->notif_correlation_id) {
        free(up_subscription->notif_correlation_id);
        up_subscription->notif_correlation_id = NULL;
    }
    if (up_subscription->supi) {
        free(up_subscription->supi);
        up_subscription->supi = NULL;
    }
    if (up_subscription->gpsi) {
        free(up_subscription->gpsi);
        up_subscription->gpsi = NULL;
    }
    free(up_subscription);
}

cJSON *up_subscription_convertToJSON(up_subscription_t *up_subscription) {
    cJSON *item = cJSON_CreateObject();

    // up_subscription->up_notify_call_back_uri
    if (!up_subscription->up_notify_call_back_uri) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "upNotifyCallBackUri", up_subscription->up_notify_call_back_uri) == NULL) {
    goto fail; //String
    }


    // up_subscription->notif_correlation_id
    if (!up_subscription->notif_correlation_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "notifCorrelationId", up_subscription->notif_correlation_id) == NULL) {
    goto fail; //String
    }


    // up_subscription->supi
    if (!up_subscription->supi) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "supi", up_subscription->supi) == NULL) {
    goto fail; //String
    }


    // up_subscription->gpsi
    if(up_subscription->gpsi) {
    if(cJSON_AddStringToObject(item, "gpsi", up_subscription->gpsi) == NULL) {
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

up_subscription_t *up_subscription_parseFromJSON(cJSON *up_subscriptionJSON){

    up_subscription_t *up_subscription_local_var = NULL;

    char *up_notify_call_back_uri_local_str = NULL;

    char *notif_correlation_id_local_str = NULL;

    char *supi_local_str = NULL;

    char *gpsi_local_str = NULL;

    // up_subscription->up_notify_call_back_uri
    cJSON *up_notify_call_back_uri = cJSON_GetObjectItemCaseSensitive(up_subscriptionJSON, "upNotifyCallBackUri");
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

    // up_subscription->notif_correlation_id
    cJSON *notif_correlation_id = cJSON_GetObjectItemCaseSensitive(up_subscriptionJSON, "notifCorrelationId");
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

    // up_subscription->supi
    cJSON *supi = cJSON_GetObjectItemCaseSensitive(up_subscriptionJSON, "supi");
    if (cJSON_IsNull(supi)) {
        supi = NULL;
    }
    if (!supi) {
        goto end;
    }

    
    if(!cJSON_IsString(supi))
    {
    goto end; //String
    }

    // up_subscription->gpsi
    cJSON *gpsi = cJSON_GetObjectItemCaseSensitive(up_subscriptionJSON, "gpsi");
    if (cJSON_IsNull(gpsi)) {
        gpsi = NULL;
    }
    if (gpsi) { 
    if(!cJSON_IsString(gpsi) && !cJSON_IsNull(gpsi))
    {
    goto end; //String
    }
    }


    if (up_notify_call_back_uri && !cJSON_IsNull(up_notify_call_back_uri)) up_notify_call_back_uri_local_str = strdup(up_notify_call_back_uri->valuestring);
    if (notif_correlation_id && !cJSON_IsNull(notif_correlation_id)) notif_correlation_id_local_str = strdup(notif_correlation_id->valuestring);
    if (supi && !cJSON_IsNull(supi)) supi_local_str = strdup(supi->valuestring);
    if (gpsi && !cJSON_IsNull(gpsi)) gpsi_local_str = strdup(gpsi->valuestring);

    up_subscription_local_var = up_subscription_create_internal (
        up_notify_call_back_uri_local_str,
        notif_correlation_id_local_str,
        supi_local_str,
        gpsi_local_str
        );

    if (!up_subscription_local_var) {
        goto end;
    }

    return up_subscription_local_var;
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
    return NULL;

}
