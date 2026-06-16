#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_cum_evt_rpt_criteria.h"



static up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_create_internal(
    int *evt_rpt_time_criteria,
    int *evt_rpt_count_criteria
    ) {
    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_var = malloc(sizeof(up_cum_evt_rpt_criteria_t));
    if (!up_cum_evt_rpt_criteria_local_var) {
        return NULL;
    }
    memset(up_cum_evt_rpt_criteria_local_var, 0, sizeof(up_cum_evt_rpt_criteria_t));
    up_cum_evt_rpt_criteria_local_var->_library_owned = 1;
    up_cum_evt_rpt_criteria_local_var->evt_rpt_time_criteria = evt_rpt_time_criteria;
    up_cum_evt_rpt_criteria_local_var->evt_rpt_count_criteria = evt_rpt_count_criteria;
    return up_cum_evt_rpt_criteria_local_var;
}

__attribute__((deprecated)) up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_create(
    int *evt_rpt_time_criteria,
    int *evt_rpt_count_criteria
    ) {
    int *evt_rpt_time_criteria_copy = NULL;
    if (evt_rpt_time_criteria) {
        evt_rpt_time_criteria_copy = malloc(sizeof(int));
        if (evt_rpt_time_criteria_copy) *evt_rpt_time_criteria_copy = *evt_rpt_time_criteria;
    }
    int *evt_rpt_count_criteria_copy = NULL;
    if (evt_rpt_count_criteria) {
        evt_rpt_count_criteria_copy = malloc(sizeof(int));
        if (evt_rpt_count_criteria_copy) *evt_rpt_count_criteria_copy = *evt_rpt_count_criteria;
    }
    up_cum_evt_rpt_criteria_t *result = up_cum_evt_rpt_criteria_create_internal (
        evt_rpt_time_criteria_copy,
        evt_rpt_count_criteria_copy
        );
    if (!result) {
        free(evt_rpt_time_criteria_copy);
        free(evt_rpt_count_criteria_copy);
    }
    return result;
}

void up_cum_evt_rpt_criteria_free(up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria) {
    if(NULL == up_cum_evt_rpt_criteria){
        return ;
    }
    if(up_cum_evt_rpt_criteria->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "up_cum_evt_rpt_criteria_free");
        return ;
    }
    listEntry_t *listEntry;
    if (up_cum_evt_rpt_criteria->evt_rpt_time_criteria) {
        free(up_cum_evt_rpt_criteria->evt_rpt_time_criteria);
        up_cum_evt_rpt_criteria->evt_rpt_time_criteria = NULL;
    }
    if (up_cum_evt_rpt_criteria->evt_rpt_count_criteria) {
        free(up_cum_evt_rpt_criteria->evt_rpt_count_criteria);
        up_cum_evt_rpt_criteria->evt_rpt_count_criteria = NULL;
    }
    free(up_cum_evt_rpt_criteria);
}

cJSON *up_cum_evt_rpt_criteria_convertToJSON(up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria) {
    cJSON *item = cJSON_CreateObject();

    // up_cum_evt_rpt_criteria->evt_rpt_time_criteria
    if(up_cum_evt_rpt_criteria->evt_rpt_time_criteria) {
    if(cJSON_AddNumberToObject(item, "evtRptTimeCriteria", *up_cum_evt_rpt_criteria->evt_rpt_time_criteria) == NULL) {
    goto fail; //Numeric
    }
    }


    // up_cum_evt_rpt_criteria->evt_rpt_count_criteria
    if(up_cum_evt_rpt_criteria->evt_rpt_count_criteria) {
    if(cJSON_AddNumberToObject(item, "evtRptCountCriteria", *up_cum_evt_rpt_criteria->evt_rpt_count_criteria) == NULL) {
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

up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_parseFromJSON(cJSON *up_cum_evt_rpt_criteriaJSON){

    up_cum_evt_rpt_criteria_t *up_cum_evt_rpt_criteria_local_var = NULL;

    // define the local variable for up_cum_evt_rpt_criteria->evt_rpt_time_criteria
    int *evt_rpt_time_criteria_local_var = NULL;

    // define the local variable for up_cum_evt_rpt_criteria->evt_rpt_count_criteria
    int *evt_rpt_count_criteria_local_var = NULL;

    // up_cum_evt_rpt_criteria->evt_rpt_time_criteria
    cJSON *evt_rpt_time_criteria = cJSON_GetObjectItemCaseSensitive(up_cum_evt_rpt_criteriaJSON, "evtRptTimeCriteria");
    if (cJSON_IsNull(evt_rpt_time_criteria)) {
        evt_rpt_time_criteria = NULL;
    }
    if (evt_rpt_time_criteria) { 
    if(!cJSON_IsNumber(evt_rpt_time_criteria))
    {
    goto end; //Numeric
    }
    evt_rpt_time_criteria_local_var = malloc(sizeof(int));
    if(!evt_rpt_time_criteria_local_var)
    {
        goto end;
    }
    *evt_rpt_time_criteria_local_var = evt_rpt_time_criteria->valuedouble;
    }

    // up_cum_evt_rpt_criteria->evt_rpt_count_criteria
    cJSON *evt_rpt_count_criteria = cJSON_GetObjectItemCaseSensitive(up_cum_evt_rpt_criteriaJSON, "evtRptCountCriteria");
    if (cJSON_IsNull(evt_rpt_count_criteria)) {
        evt_rpt_count_criteria = NULL;
    }
    if (evt_rpt_count_criteria) { 
    if(!cJSON_IsNumber(evt_rpt_count_criteria))
    {
    goto end; //Numeric
    }
    evt_rpt_count_criteria_local_var = malloc(sizeof(int));
    if(!evt_rpt_count_criteria_local_var)
    {
        goto end;
    }
    *evt_rpt_count_criteria_local_var = evt_rpt_count_criteria->valuedouble;
    }



    up_cum_evt_rpt_criteria_local_var = up_cum_evt_rpt_criteria_create_internal (
        evt_rpt_time_criteria_local_var,
        evt_rpt_count_criteria_local_var
        );

    if (!up_cum_evt_rpt_criteria_local_var) {
        goto end;
    }

    return up_cum_evt_rpt_criteria_local_var;
end:
    if (evt_rpt_time_criteria_local_var) {
        free(evt_rpt_time_criteria_local_var);
        evt_rpt_time_criteria_local_var = NULL;
    }
    if (evt_rpt_count_criteria_local_var) {
        free(evt_rpt_count_criteria_local_var);
        evt_rpt_count_criteria_local_var = NULL;
    }
    return NULL;

}
