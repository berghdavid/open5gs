#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "reporting_area.h"



static reporting_area_t *reporting_area_create_internal(
    reporting_area_type_t *area_type,
    tai_t *tai,
    ecgi_t *ecgi,
    ncgi_t *ncgi
    ) {
    reporting_area_t *reporting_area_local_var = malloc(sizeof(reporting_area_t));
    if (!reporting_area_local_var) {
        return NULL;
    }
    memset(reporting_area_local_var, 0, sizeof(reporting_area_t));
    reporting_area_local_var->_library_owned = 1;
    reporting_area_local_var->area_type = area_type;
    reporting_area_local_var->tai = tai;
    reporting_area_local_var->ecgi = ecgi;
    reporting_area_local_var->ncgi = ncgi;
    return reporting_area_local_var;
}

__attribute__((deprecated)) reporting_area_t *reporting_area_create(
    reporting_area_type_t *area_type,
    tai_t *tai,
    ecgi_t *ecgi,
    ncgi_t *ncgi
    ) {
    reporting_area_t *result = reporting_area_create_internal (
        area_type,
        tai,
        ecgi,
        ncgi
        );
    if (!result) {
    }
    return result;
}

void reporting_area_free(reporting_area_t *reporting_area) {
    if(NULL == reporting_area){
        return ;
    }
    if(reporting_area->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "reporting_area_free");
        return ;
    }
    listEntry_t *listEntry;
    if (reporting_area->area_type) {
        reporting_area_type_free(reporting_area->area_type);
        reporting_area->area_type = NULL;
    }
    if (reporting_area->tai) {
        tai_free(reporting_area->tai);
        reporting_area->tai = NULL;
    }
    if (reporting_area->ecgi) {
        ecgi_free(reporting_area->ecgi);
        reporting_area->ecgi = NULL;
    }
    if (reporting_area->ncgi) {
        ncgi_free(reporting_area->ncgi);
        reporting_area->ncgi = NULL;
    }
    free(reporting_area);
}

cJSON *reporting_area_convertToJSON(reporting_area_t *reporting_area) {
    cJSON *item = cJSON_CreateObject();

    // reporting_area->area_type
    if (!reporting_area->area_type) {
        goto fail;
    }
    cJSON *area_type_local_JSON = reporting_area_type_convertToJSON(reporting_area->area_type);
    if(area_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "areaType", area_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // reporting_area->tai
    if(reporting_area->tai) {
    cJSON *tai_local_JSON = tai_convertToJSON(reporting_area->tai);
    if(tai_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "tai", tai_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // reporting_area->ecgi
    if(reporting_area->ecgi) {
    cJSON *ecgi_local_JSON = ecgi_convertToJSON(reporting_area->ecgi);
    if(ecgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // reporting_area->ncgi
    if(reporting_area->ncgi) {
    cJSON *ncgi_local_JSON = ncgi_convertToJSON(reporting_area->ncgi);
    if(ncgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
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

reporting_area_t *reporting_area_parseFromJSON(cJSON *reporting_areaJSON){

    reporting_area_t *reporting_area_local_var = NULL;

    // define the local variable for reporting_area->area_type
    reporting_area_type_t *area_type_local_nonprim = NULL;

    // define the local variable for reporting_area->tai
    tai_t *tai_local_nonprim = NULL;

    // define the local variable for reporting_area->ecgi
    ecgi_t *ecgi_local_nonprim = NULL;

    // define the local variable for reporting_area->ncgi
    ncgi_t *ncgi_local_nonprim = NULL;

    // reporting_area->area_type
    cJSON *area_type = cJSON_GetObjectItemCaseSensitive(reporting_areaJSON, "areaType");
    if (cJSON_IsNull(area_type)) {
        area_type = NULL;
    }
    if (!area_type) {
        goto end;
    }

    
    area_type_local_nonprim = reporting_area_type_parseFromJSON(area_type); //nonprimitive

    // reporting_area->tai
    cJSON *tai = cJSON_GetObjectItemCaseSensitive(reporting_areaJSON, "tai");
    if (cJSON_IsNull(tai)) {
        tai = NULL;
    }
    if (tai) { 
    tai_local_nonprim = tai_parseFromJSON(tai); //nonprimitive
    }

    // reporting_area->ecgi
    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(reporting_areaJSON, "ecgi");
    if (cJSON_IsNull(ecgi)) {
        ecgi = NULL;
    }
    if (ecgi) { 
    ecgi_local_nonprim = ecgi_parseFromJSON(ecgi); //nonprimitive
    }

    // reporting_area->ncgi
    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(reporting_areaJSON, "ncgi");
    if (cJSON_IsNull(ncgi)) {
        ncgi = NULL;
    }
    if (ncgi) { 
    ncgi_local_nonprim = ncgi_parseFromJSON(ncgi); //nonprimitive
    }



    reporting_area_local_var = reporting_area_create_internal (
        area_type_local_nonprim,
        tai ? tai_local_nonprim : NULL,
        ecgi ? ecgi_local_nonprim : NULL,
        ncgi ? ncgi_local_nonprim : NULL
        );

    if (!reporting_area_local_var) {
        goto end;
    }

    return reporting_area_local_var;
end:
    if (area_type_local_nonprim) {
        reporting_area_type_free(area_type_local_nonprim);
        area_type_local_nonprim = NULL;
    }
    if (tai_local_nonprim) {
        tai_free(tai_local_nonprim);
        tai_local_nonprim = NULL;
    }
    if (ecgi_local_nonprim) {
        ecgi_free(ecgi_local_nonprim);
        ecgi_local_nonprim = NULL;
    }
    if (ncgi_local_nonprim) {
        ncgi_free(ncgi_local_nonprim);
        ncgi_local_nonprim = NULL;
    }
    return NULL;

}
