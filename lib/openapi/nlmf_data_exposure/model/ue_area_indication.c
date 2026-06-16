#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ue_area_indication.h"



static ue_area_indication_t *ue_area_indication_create_internal(
    char *country,
    int *international_area_ind
    ) {
    ue_area_indication_t *ue_area_indication_local_var = malloc(sizeof(ue_area_indication_t));
    if (!ue_area_indication_local_var) {
        return NULL;
    }
    memset(ue_area_indication_local_var, 0, sizeof(ue_area_indication_t));
    ue_area_indication_local_var->_library_owned = 1;
    ue_area_indication_local_var->country = country;
    ue_area_indication_local_var->international_area_ind = international_area_ind;
    return ue_area_indication_local_var;
}

__attribute__((deprecated)) ue_area_indication_t *ue_area_indication_create(
    char *country,
    int *international_area_ind
    ) {
    int *international_area_ind_copy = NULL;
    if (international_area_ind) {
        international_area_ind_copy = malloc(sizeof(int));
        if (international_area_ind_copy) *international_area_ind_copy = *international_area_ind;
    }
    ue_area_indication_t *result = ue_area_indication_create_internal (
        country,
        international_area_ind_copy
        );
    if (!result) {
        free(international_area_ind_copy);
    }
    return result;
}

void ue_area_indication_free(ue_area_indication_t *ue_area_indication) {
    if(NULL == ue_area_indication){
        return ;
    }
    if(ue_area_indication->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ue_area_indication_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ue_area_indication->country) {
        free(ue_area_indication->country);
        ue_area_indication->country = NULL;
    }
    if (ue_area_indication->international_area_ind) {
        free(ue_area_indication->international_area_ind);
        ue_area_indication->international_area_ind = NULL;
    }
    free(ue_area_indication);
}

cJSON *ue_area_indication_convertToJSON(ue_area_indication_t *ue_area_indication) {
    cJSON *item = cJSON_CreateObject();

    // ue_area_indication->country
    if(ue_area_indication->country) {
    if(cJSON_AddStringToObject(item, "country", ue_area_indication->country) == NULL) {
    goto fail; //String
    }
    }


    // ue_area_indication->international_area_ind
    if(ue_area_indication->international_area_ind) {
    if(cJSON_AddBoolToObject(item, "internationalAreaInd", *ue_area_indication->international_area_ind) == NULL) {
    goto fail; //Bool
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ue_area_indication_t *ue_area_indication_parseFromJSON(cJSON *ue_area_indicationJSON){

    ue_area_indication_t *ue_area_indication_local_var = NULL;

    char *country_local_str = NULL;

    // define the local variable for ue_area_indication->international_area_ind
    int *international_area_ind_local_var = NULL;

    // ue_area_indication->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(ue_area_indicationJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    if(!cJSON_IsString(country) && !cJSON_IsNull(country))
    {
    goto end; //String
    }
    }

    // ue_area_indication->international_area_ind
    cJSON *international_area_ind = cJSON_GetObjectItemCaseSensitive(ue_area_indicationJSON, "internationalAreaInd");
    if (cJSON_IsNull(international_area_ind)) {
        international_area_ind = NULL;
    }
    if (international_area_ind) { 
    if(!cJSON_IsBool(international_area_ind))
    {
    goto end; //Bool
    }
    international_area_ind_local_var = malloc(sizeof(int));
    if(!international_area_ind_local_var)
    {
        goto end;
    }
    *international_area_ind_local_var = international_area_ind->valueint;
    }


    if (country && !cJSON_IsNull(country)) country_local_str = strdup(country->valuestring);

    ue_area_indication_local_var = ue_area_indication_create_internal (
        country_local_str,
        international_area_ind_local_var
        );

    if (!ue_area_indication_local_var) {
        goto end;
    }

    return ue_area_indication_local_var;
end:
    if (country_local_str) {
        free(country_local_str);
        country_local_str = NULL;
    }
    if (international_area_ind_local_var) {
        free(international_area_ind_local_var);
        international_area_ind_local_var = NULL;
    }
    return NULL;

}
