#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "integrity_requirements.h"



static integrity_requirements_t *integrity_requirements_create_internal(
    int *time_to_alert,
    int *target_integrity_risk,
    alert_limit_t *alert_limit
    ) {
    integrity_requirements_t *integrity_requirements_local_var = malloc(sizeof(integrity_requirements_t));
    if (!integrity_requirements_local_var) {
        return NULL;
    }
    memset(integrity_requirements_local_var, 0, sizeof(integrity_requirements_t));
    integrity_requirements_local_var->_library_owned = 1;
    integrity_requirements_local_var->time_to_alert = time_to_alert;
    integrity_requirements_local_var->target_integrity_risk = target_integrity_risk;
    integrity_requirements_local_var->alert_limit = alert_limit;
    return integrity_requirements_local_var;
}

__attribute__((deprecated)) integrity_requirements_t *integrity_requirements_create(
    int *time_to_alert,
    int *target_integrity_risk,
    alert_limit_t *alert_limit
    ) {
    int *time_to_alert_copy = NULL;
    if (time_to_alert) {
        time_to_alert_copy = malloc(sizeof(int));
        if (time_to_alert_copy) *time_to_alert_copy = *time_to_alert;
    }
    int *target_integrity_risk_copy = NULL;
    if (target_integrity_risk) {
        target_integrity_risk_copy = malloc(sizeof(int));
        if (target_integrity_risk_copy) *target_integrity_risk_copy = *target_integrity_risk;
    }
    integrity_requirements_t *result = integrity_requirements_create_internal (
        time_to_alert_copy,
        target_integrity_risk_copy,
        alert_limit
        );
    if (!result) {
        free(time_to_alert_copy);
        free(target_integrity_risk_copy);
    }
    return result;
}

void integrity_requirements_free(integrity_requirements_t *integrity_requirements) {
    if(NULL == integrity_requirements){
        return ;
    }
    if(integrity_requirements->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "integrity_requirements_free");
        return ;
    }
    listEntry_t *listEntry;
    if (integrity_requirements->time_to_alert) {
        free(integrity_requirements->time_to_alert);
        integrity_requirements->time_to_alert = NULL;
    }
    if (integrity_requirements->target_integrity_risk) {
        free(integrity_requirements->target_integrity_risk);
        integrity_requirements->target_integrity_risk = NULL;
    }
    if (integrity_requirements->alert_limit) {
        alert_limit_free(integrity_requirements->alert_limit);
        integrity_requirements->alert_limit = NULL;
    }
    free(integrity_requirements);
}

cJSON *integrity_requirements_convertToJSON(integrity_requirements_t *integrity_requirements) {
    cJSON *item = cJSON_CreateObject();

    // integrity_requirements->time_to_alert
    if(integrity_requirements->time_to_alert) {
    if(cJSON_AddNumberToObject(item, "timeToAlert", *integrity_requirements->time_to_alert) == NULL) {
    goto fail; //Numeric
    }
    }


    // integrity_requirements->target_integrity_risk
    if(integrity_requirements->target_integrity_risk) {
    if(cJSON_AddNumberToObject(item, "targetIntegrityRisk", *integrity_requirements->target_integrity_risk) == NULL) {
    goto fail; //Numeric
    }
    }


    // integrity_requirements->alert_limit
    if(integrity_requirements->alert_limit) {
    cJSON *alert_limit_local_JSON = alert_limit_convertToJSON(integrity_requirements->alert_limit);
    if(alert_limit_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "alertLimit", alert_limit_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

integrity_requirements_t *integrity_requirements_parseFromJSON(cJSON *integrity_requirementsJSON){

    integrity_requirements_t *integrity_requirements_local_var = NULL;

    // define the local variable for integrity_requirements->time_to_alert
    int *time_to_alert_local_var = NULL;

    // define the local variable for integrity_requirements->target_integrity_risk
    int *target_integrity_risk_local_var = NULL;

    // define the local variable for integrity_requirements->alert_limit
    alert_limit_t *alert_limit_local_nonprim = NULL;

    // integrity_requirements->time_to_alert
    cJSON *time_to_alert = cJSON_GetObjectItemCaseSensitive(integrity_requirementsJSON, "timeToAlert");
    if (cJSON_IsNull(time_to_alert)) {
        time_to_alert = NULL;
    }
    if (time_to_alert) { 
    if(!cJSON_IsNumber(time_to_alert))
    {
    goto end; //Numeric
    }
    time_to_alert_local_var = malloc(sizeof(int));
    if(!time_to_alert_local_var)
    {
        goto end;
    }
    *time_to_alert_local_var = time_to_alert->valuedouble;
    }

    // integrity_requirements->target_integrity_risk
    cJSON *target_integrity_risk = cJSON_GetObjectItemCaseSensitive(integrity_requirementsJSON, "targetIntegrityRisk");
    if (cJSON_IsNull(target_integrity_risk)) {
        target_integrity_risk = NULL;
    }
    if (target_integrity_risk) { 
    if(!cJSON_IsNumber(target_integrity_risk))
    {
    goto end; //Numeric
    }
    target_integrity_risk_local_var = malloc(sizeof(int));
    if(!target_integrity_risk_local_var)
    {
        goto end;
    }
    *target_integrity_risk_local_var = target_integrity_risk->valuedouble;
    }

    // integrity_requirements->alert_limit
    cJSON *alert_limit = cJSON_GetObjectItemCaseSensitive(integrity_requirementsJSON, "alertLimit");
    if (cJSON_IsNull(alert_limit)) {
        alert_limit = NULL;
    }
    if (alert_limit) { 
    alert_limit_local_nonprim = alert_limit_parseFromJSON(alert_limit); //nonprimitive
    }



    integrity_requirements_local_var = integrity_requirements_create_internal (
        time_to_alert_local_var,
        target_integrity_risk_local_var,
        alert_limit ? alert_limit_local_nonprim : NULL
        );

    if (!integrity_requirements_local_var) {
        goto end;
    }

    return integrity_requirements_local_var;
end:
    if (time_to_alert_local_var) {
        free(time_to_alert_local_var);
        time_to_alert_local_var = NULL;
    }
    if (target_integrity_risk_local_var) {
        free(target_integrity_risk_local_var);
        target_integrity_risk_local_var = NULL;
    }
    if (alert_limit_local_nonprim) {
        alert_limit_free(alert_limit_local_nonprim);
        alert_limit_local_nonprim = NULL;
    }
    return NULL;

}
