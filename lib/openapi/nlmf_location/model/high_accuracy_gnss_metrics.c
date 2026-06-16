#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "high_accuracy_gnss_metrics.h"



static high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_create_internal(
    int *nr_of_used_satellites,
    int *hdopi,
    int *pdopi,
    int *age,
    fix_type_t *fix_type
    ) {
    high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_local_var = malloc(sizeof(high_accuracy_gnss_metrics_t));
    if (!high_accuracy_gnss_metrics_local_var) {
        return NULL;
    }
    memset(high_accuracy_gnss_metrics_local_var, 0, sizeof(high_accuracy_gnss_metrics_t));
    high_accuracy_gnss_metrics_local_var->_library_owned = 1;
    high_accuracy_gnss_metrics_local_var->nr_of_used_satellites = nr_of_used_satellites;
    high_accuracy_gnss_metrics_local_var->hdopi = hdopi;
    high_accuracy_gnss_metrics_local_var->pdopi = pdopi;
    high_accuracy_gnss_metrics_local_var->age = age;
    high_accuracy_gnss_metrics_local_var->fix_type = fix_type;
    return high_accuracy_gnss_metrics_local_var;
}

__attribute__((deprecated)) high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_create(
    int *nr_of_used_satellites,
    int *hdopi,
    int *pdopi,
    int *age,
    fix_type_t *fix_type
    ) {
    int *nr_of_used_satellites_copy = NULL;
    if (nr_of_used_satellites) {
        nr_of_used_satellites_copy = malloc(sizeof(int));
        if (nr_of_used_satellites_copy) *nr_of_used_satellites_copy = *nr_of_used_satellites;
    }
    int *hdopi_copy = NULL;
    if (hdopi) {
        hdopi_copy = malloc(sizeof(int));
        if (hdopi_copy) *hdopi_copy = *hdopi;
    }
    int *pdopi_copy = NULL;
    if (pdopi) {
        pdopi_copy = malloc(sizeof(int));
        if (pdopi_copy) *pdopi_copy = *pdopi;
    }
    int *age_copy = NULL;
    if (age) {
        age_copy = malloc(sizeof(int));
        if (age_copy) *age_copy = *age;
    }
    high_accuracy_gnss_metrics_t *result = high_accuracy_gnss_metrics_create_internal (
        nr_of_used_satellites_copy,
        hdopi_copy,
        pdopi_copy,
        age_copy,
        fix_type
        );
    if (!result) {
        free(nr_of_used_satellites_copy);
        free(hdopi_copy);
        free(pdopi_copy);
        free(age_copy);
    }
    return result;
}

void high_accuracy_gnss_metrics_free(high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics) {
    if(NULL == high_accuracy_gnss_metrics){
        return ;
    }
    if(high_accuracy_gnss_metrics->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "high_accuracy_gnss_metrics_free");
        return ;
    }
    listEntry_t *listEntry;
    if (high_accuracy_gnss_metrics->nr_of_used_satellites) {
        free(high_accuracy_gnss_metrics->nr_of_used_satellites);
        high_accuracy_gnss_metrics->nr_of_used_satellites = NULL;
    }
    if (high_accuracy_gnss_metrics->hdopi) {
        free(high_accuracy_gnss_metrics->hdopi);
        high_accuracy_gnss_metrics->hdopi = NULL;
    }
    if (high_accuracy_gnss_metrics->pdopi) {
        free(high_accuracy_gnss_metrics->pdopi);
        high_accuracy_gnss_metrics->pdopi = NULL;
    }
    if (high_accuracy_gnss_metrics->age) {
        free(high_accuracy_gnss_metrics->age);
        high_accuracy_gnss_metrics->age = NULL;
    }
    if (high_accuracy_gnss_metrics->fix_type) {
        fix_type_free(high_accuracy_gnss_metrics->fix_type);
        high_accuracy_gnss_metrics->fix_type = NULL;
    }
    free(high_accuracy_gnss_metrics);
}

cJSON *high_accuracy_gnss_metrics_convertToJSON(high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics) {
    cJSON *item = cJSON_CreateObject();

    // high_accuracy_gnss_metrics->nr_of_used_satellites
    if(high_accuracy_gnss_metrics->nr_of_used_satellites) {
    if(cJSON_AddNumberToObject(item, "nrOfUsedSatellites", *high_accuracy_gnss_metrics->nr_of_used_satellites) == NULL) {
    goto fail; //Numeric
    }
    }


    // high_accuracy_gnss_metrics->hdopi
    if(high_accuracy_gnss_metrics->hdopi) {
    if(cJSON_AddNumberToObject(item, "hdopi", *high_accuracy_gnss_metrics->hdopi) == NULL) {
    goto fail; //Numeric
    }
    }


    // high_accuracy_gnss_metrics->pdopi
    if(high_accuracy_gnss_metrics->pdopi) {
    if(cJSON_AddNumberToObject(item, "pdopi", *high_accuracy_gnss_metrics->pdopi) == NULL) {
    goto fail; //Numeric
    }
    }


    // high_accuracy_gnss_metrics->age
    if(high_accuracy_gnss_metrics->age) {
    if(cJSON_AddNumberToObject(item, "age", *high_accuracy_gnss_metrics->age) == NULL) {
    goto fail; //Numeric
    }
    }


    // high_accuracy_gnss_metrics->fix_type
    if(high_accuracy_gnss_metrics->fix_type) {
    cJSON *fix_type_local_JSON = fix_type_convertToJSON(high_accuracy_gnss_metrics->fix_type);
    if(fix_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "fixType", fix_type_local_JSON);
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

high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_parseFromJSON(cJSON *high_accuracy_gnss_metricsJSON){

    high_accuracy_gnss_metrics_t *high_accuracy_gnss_metrics_local_var = NULL;

    // define the local variable for high_accuracy_gnss_metrics->nr_of_used_satellites
    int *nr_of_used_satellites_local_var = NULL;

    // define the local variable for high_accuracy_gnss_metrics->hdopi
    int *hdopi_local_var = NULL;

    // define the local variable for high_accuracy_gnss_metrics->pdopi
    int *pdopi_local_var = NULL;

    // define the local variable for high_accuracy_gnss_metrics->age
    int *age_local_var = NULL;

    // define the local variable for high_accuracy_gnss_metrics->fix_type
    fix_type_t *fix_type_local_nonprim = NULL;

    // high_accuracy_gnss_metrics->nr_of_used_satellites
    cJSON *nr_of_used_satellites = cJSON_GetObjectItemCaseSensitive(high_accuracy_gnss_metricsJSON, "nrOfUsedSatellites");
    if (cJSON_IsNull(nr_of_used_satellites)) {
        nr_of_used_satellites = NULL;
    }
    if (nr_of_used_satellites) { 
    if(!cJSON_IsNumber(nr_of_used_satellites))
    {
    goto end; //Numeric
    }
    nr_of_used_satellites_local_var = malloc(sizeof(int));
    if(!nr_of_used_satellites_local_var)
    {
        goto end;
    }
    *nr_of_used_satellites_local_var = nr_of_used_satellites->valuedouble;
    }

    // high_accuracy_gnss_metrics->hdopi
    cJSON *hdopi = cJSON_GetObjectItemCaseSensitive(high_accuracy_gnss_metricsJSON, "hdopi");
    if (cJSON_IsNull(hdopi)) {
        hdopi = NULL;
    }
    if (hdopi) { 
    if(!cJSON_IsNumber(hdopi))
    {
    goto end; //Numeric
    }
    hdopi_local_var = malloc(sizeof(int));
    if(!hdopi_local_var)
    {
        goto end;
    }
    *hdopi_local_var = hdopi->valuedouble;
    }

    // high_accuracy_gnss_metrics->pdopi
    cJSON *pdopi = cJSON_GetObjectItemCaseSensitive(high_accuracy_gnss_metricsJSON, "pdopi");
    if (cJSON_IsNull(pdopi)) {
        pdopi = NULL;
    }
    if (pdopi) { 
    if(!cJSON_IsNumber(pdopi))
    {
    goto end; //Numeric
    }
    pdopi_local_var = malloc(sizeof(int));
    if(!pdopi_local_var)
    {
        goto end;
    }
    *pdopi_local_var = pdopi->valuedouble;
    }

    // high_accuracy_gnss_metrics->age
    cJSON *age = cJSON_GetObjectItemCaseSensitive(high_accuracy_gnss_metricsJSON, "age");
    if (cJSON_IsNull(age)) {
        age = NULL;
    }
    if (age) { 
    if(!cJSON_IsNumber(age))
    {
    goto end; //Numeric
    }
    age_local_var = malloc(sizeof(int));
    if(!age_local_var)
    {
        goto end;
    }
    *age_local_var = age->valuedouble;
    }

    // high_accuracy_gnss_metrics->fix_type
    cJSON *fix_type = cJSON_GetObjectItemCaseSensitive(high_accuracy_gnss_metricsJSON, "fixType");
    if (cJSON_IsNull(fix_type)) {
        fix_type = NULL;
    }
    if (fix_type) { 
    fix_type_local_nonprim = fix_type_parseFromJSON(fix_type); //nonprimitive
    }



    high_accuracy_gnss_metrics_local_var = high_accuracy_gnss_metrics_create_internal (
        nr_of_used_satellites_local_var,
        hdopi_local_var,
        pdopi_local_var,
        age_local_var,
        fix_type ? fix_type_local_nonprim : NULL
        );

    if (!high_accuracy_gnss_metrics_local_var) {
        goto end;
    }

    return high_accuracy_gnss_metrics_local_var;
end:
    if (nr_of_used_satellites_local_var) {
        free(nr_of_used_satellites_local_var);
        nr_of_used_satellites_local_var = NULL;
    }
    if (hdopi_local_var) {
        free(hdopi_local_var);
        hdopi_local_var = NULL;
    }
    if (pdopi_local_var) {
        free(pdopi_local_var);
        pdopi_local_var = NULL;
    }
    if (age_local_var) {
        free(age_local_var);
        age_local_var = NULL;
    }
    if (fix_type_local_nonprim) {
        fix_type_free(fix_type_local_nonprim);
        fix_type_local_nonprim = NULL;
    }
    return NULL;

}
