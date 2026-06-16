#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "additional_ue_info.h"



static additional_ue_info_t *additional_ue_info_create_internal(
    ncgi_t *ncgi,
    tai_t *tai
    ) {
    additional_ue_info_t *additional_ue_info_local_var = malloc(sizeof(additional_ue_info_t));
    if (!additional_ue_info_local_var) {
        return NULL;
    }
    memset(additional_ue_info_local_var, 0, sizeof(additional_ue_info_t));
    additional_ue_info_local_var->_library_owned = 1;
    additional_ue_info_local_var->ncgi = ncgi;
    additional_ue_info_local_var->tai = tai;
    return additional_ue_info_local_var;
}

__attribute__((deprecated)) additional_ue_info_t *additional_ue_info_create(
    ncgi_t *ncgi,
    tai_t *tai
    ) {
    additional_ue_info_t *result = additional_ue_info_create_internal (
        ncgi,
        tai
        );
    if (!result) {
    }
    return result;
}

void additional_ue_info_free(additional_ue_info_t *additional_ue_info) {
    if(NULL == additional_ue_info){
        return ;
    }
    if(additional_ue_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "additional_ue_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (additional_ue_info->ncgi) {
        ncgi_free(additional_ue_info->ncgi);
        additional_ue_info->ncgi = NULL;
    }
    if (additional_ue_info->tai) {
        tai_free(additional_ue_info->tai);
        additional_ue_info->tai = NULL;
    }
    free(additional_ue_info);
}

cJSON *additional_ue_info_convertToJSON(additional_ue_info_t *additional_ue_info) {
    cJSON *item = cJSON_CreateObject();

    // additional_ue_info->ncgi
    if(additional_ue_info->ncgi) {
    cJSON *ncgi_local_JSON = ncgi_convertToJSON(additional_ue_info->ncgi);
    if(ncgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // additional_ue_info->tai
    if(additional_ue_info->tai) {
    cJSON *tai_local_JSON = tai_convertToJSON(additional_ue_info->tai);
    if(tai_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "tai", tai_local_JSON);
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

additional_ue_info_t *additional_ue_info_parseFromJSON(cJSON *additional_ue_infoJSON){

    additional_ue_info_t *additional_ue_info_local_var = NULL;

    // define the local variable for additional_ue_info->ncgi
    ncgi_t *ncgi_local_nonprim = NULL;

    // define the local variable for additional_ue_info->tai
    tai_t *tai_local_nonprim = NULL;

    // additional_ue_info->ncgi
    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(additional_ue_infoJSON, "ncgi");
    if (cJSON_IsNull(ncgi)) {
        ncgi = NULL;
    }
    if (ncgi) { 
    ncgi_local_nonprim = ncgi_parseFromJSON(ncgi); //nonprimitive
    }

    // additional_ue_info->tai
    cJSON *tai = cJSON_GetObjectItemCaseSensitive(additional_ue_infoJSON, "tai");
    if (cJSON_IsNull(tai)) {
        tai = NULL;
    }
    if (tai) { 
    tai_local_nonprim = tai_parseFromJSON(tai); //nonprimitive
    }



    additional_ue_info_local_var = additional_ue_info_create_internal (
        ncgi ? ncgi_local_nonprim : NULL,
        tai ? tai_local_nonprim : NULL
        );

    if (!additional_ue_info_local_var) {
        goto end;
    }

    return additional_ue_info_local_var;
end:
    if (ncgi_local_nonprim) {
        ncgi_free(ncgi_local_nonprim);
        ncgi_local_nonprim = NULL;
    }
    if (tai_local_nonprim) {
        tai_free(tai_local_nonprim);
        tai_local_nonprim = NULL;
    }
    return NULL;

}
