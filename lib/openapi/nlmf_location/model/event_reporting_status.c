#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_reporting_status.h"



static event_reporting_status_t *event_reporting_status_create_internal(
    int *event_report_counter,
    int *event_report_duration
    ) {
    event_reporting_status_t *event_reporting_status_local_var = malloc(sizeof(event_reporting_status_t));
    if (!event_reporting_status_local_var) {
        return NULL;
    }
    memset(event_reporting_status_local_var, 0, sizeof(event_reporting_status_t));
    event_reporting_status_local_var->_library_owned = 1;
    event_reporting_status_local_var->event_report_counter = event_report_counter;
    event_reporting_status_local_var->event_report_duration = event_report_duration;
    return event_reporting_status_local_var;
}

__attribute__((deprecated)) event_reporting_status_t *event_reporting_status_create(
    int *event_report_counter,
    int *event_report_duration
    ) {
    int *event_report_counter_copy = NULL;
    if (event_report_counter) {
        event_report_counter_copy = malloc(sizeof(int));
        if (event_report_counter_copy) *event_report_counter_copy = *event_report_counter;
    }
    int *event_report_duration_copy = NULL;
    if (event_report_duration) {
        event_report_duration_copy = malloc(sizeof(int));
        if (event_report_duration_copy) *event_report_duration_copy = *event_report_duration;
    }
    event_reporting_status_t *result = event_reporting_status_create_internal (
        event_report_counter_copy,
        event_report_duration_copy
        );
    if (!result) {
        free(event_report_counter_copy);
        free(event_report_duration_copy);
    }
    return result;
}

void event_reporting_status_free(event_reporting_status_t *event_reporting_status) {
    if(NULL == event_reporting_status){
        return ;
    }
    if(event_reporting_status->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "event_reporting_status_free");
        return ;
    }
    listEntry_t *listEntry;
    if (event_reporting_status->event_report_counter) {
        free(event_reporting_status->event_report_counter);
        event_reporting_status->event_report_counter = NULL;
    }
    if (event_reporting_status->event_report_duration) {
        free(event_reporting_status->event_report_duration);
        event_reporting_status->event_report_duration = NULL;
    }
    free(event_reporting_status);
}

cJSON *event_reporting_status_convertToJSON(event_reporting_status_t *event_reporting_status) {
    cJSON *item = cJSON_CreateObject();

    // event_reporting_status->event_report_counter
    if(event_reporting_status->event_report_counter) {
    if(cJSON_AddNumberToObject(item, "eventReportCounter", *event_reporting_status->event_report_counter) == NULL) {
    goto fail; //Numeric
    }
    }


    // event_reporting_status->event_report_duration
    if(event_reporting_status->event_report_duration) {
    if(cJSON_AddNumberToObject(item, "eventReportDuration", *event_reporting_status->event_report_duration) == NULL) {
    goto fail; //Numeric
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

event_reporting_status_t *event_reporting_status_parseFromJSON(cJSON *event_reporting_statusJSON){

    event_reporting_status_t *event_reporting_status_local_var = NULL;

    // define the local variable for event_reporting_status->event_report_counter
    int *event_report_counter_local_var = NULL;

    // define the local variable for event_reporting_status->event_report_duration
    int *event_report_duration_local_var = NULL;

    // event_reporting_status->event_report_counter
    cJSON *event_report_counter = cJSON_GetObjectItemCaseSensitive(event_reporting_statusJSON, "eventReportCounter");
    if (cJSON_IsNull(event_report_counter)) {
        event_report_counter = NULL;
    }
    if (event_report_counter) { 
    if(!cJSON_IsNumber(event_report_counter))
    {
    goto end; //Numeric
    }
    event_report_counter_local_var = malloc(sizeof(int));
    if(!event_report_counter_local_var)
    {
        goto end;
    }
    *event_report_counter_local_var = event_report_counter->valuedouble;
    }

    // event_reporting_status->event_report_duration
    cJSON *event_report_duration = cJSON_GetObjectItemCaseSensitive(event_reporting_statusJSON, "eventReportDuration");
    if (cJSON_IsNull(event_report_duration)) {
        event_report_duration = NULL;
    }
    if (event_report_duration) { 
    if(!cJSON_IsNumber(event_report_duration))
    {
    goto end; //Numeric
    }
    event_report_duration_local_var = malloc(sizeof(int));
    if(!event_report_duration_local_var)
    {
        goto end;
    }
    *event_report_duration_local_var = event_report_duration->valuedouble;
    }



    event_reporting_status_local_var = event_reporting_status_create_internal (
        event_report_counter_local_var,
        event_report_duration_local_var
        );

    if (!event_reporting_status_local_var) {
        goto end;
    }

    return event_reporting_status_local_var;
end:
    if (event_report_counter_local_var) {
        free(event_report_counter_local_var);
        event_report_counter_local_var = NULL;
    }
    if (event_report_duration_local_var) {
        free(event_report_duration_local_var);
        event_report_duration_local_var = NULL;
    }
    return NULL;

}
