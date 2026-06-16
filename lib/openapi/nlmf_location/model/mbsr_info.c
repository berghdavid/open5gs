#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "mbsr_info.h"



static mbsr_info_t *mbsr_info_create_internal(
    ncgi_t *ncgi,
    ecgi_t *ecgi
    ) {
    mbsr_info_t *mbsr_info_local_var = malloc(sizeof(mbsr_info_t));
    if (!mbsr_info_local_var) {
        return NULL;
    }
    memset(mbsr_info_local_var, 0, sizeof(mbsr_info_t));
    mbsr_info_local_var->_library_owned = 1;
    mbsr_info_local_var->ncgi = ncgi;
    mbsr_info_local_var->ecgi = ecgi;
    return mbsr_info_local_var;
}

__attribute__((deprecated)) mbsr_info_t *mbsr_info_create(
    ncgi_t *ncgi,
    ecgi_t *ecgi
    ) {
    mbsr_info_t *result = mbsr_info_create_internal (
        ncgi,
        ecgi
        );
    if (!result) {
    }
    return result;
}

void mbsr_info_free(mbsr_info_t *mbsr_info) {
    if(NULL == mbsr_info){
        return ;
    }
    if(mbsr_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "mbsr_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (mbsr_info->ncgi) {
        ncgi_free(mbsr_info->ncgi);
        mbsr_info->ncgi = NULL;
    }
    if (mbsr_info->ecgi) {
        ecgi_free(mbsr_info->ecgi);
        mbsr_info->ecgi = NULL;
    }
    free(mbsr_info);
}

cJSON *mbsr_info_convertToJSON(mbsr_info_t *mbsr_info) {
    cJSON *item = cJSON_CreateObject();

    // mbsr_info->ncgi
    if(mbsr_info->ncgi) {
    cJSON *ncgi_local_JSON = ncgi_convertToJSON(mbsr_info->ncgi);
    if(ncgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ncgi", ncgi_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // mbsr_info->ecgi
    if(mbsr_info->ecgi) {
    cJSON *ecgi_local_JSON = ecgi_convertToJSON(mbsr_info->ecgi);
    if(ecgi_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "ecgi", ecgi_local_JSON);
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

mbsr_info_t *mbsr_info_parseFromJSON(cJSON *mbsr_infoJSON){

    mbsr_info_t *mbsr_info_local_var = NULL;

    // define the local variable for mbsr_info->ncgi
    ncgi_t *ncgi_local_nonprim = NULL;

    // define the local variable for mbsr_info->ecgi
    ecgi_t *ecgi_local_nonprim = NULL;

    // mbsr_info->ncgi
    cJSON *ncgi = cJSON_GetObjectItemCaseSensitive(mbsr_infoJSON, "ncgi");
    if (cJSON_IsNull(ncgi)) {
        ncgi = NULL;
    }
    if (ncgi) { 
    ncgi_local_nonprim = ncgi_parseFromJSON(ncgi); //nonprimitive
    }

    // mbsr_info->ecgi
    cJSON *ecgi = cJSON_GetObjectItemCaseSensitive(mbsr_infoJSON, "ecgi");
    if (cJSON_IsNull(ecgi)) {
        ecgi = NULL;
    }
    if (ecgi) { 
    ecgi_local_nonprim = ecgi_parseFromJSON(ecgi); //nonprimitive
    }



    mbsr_info_local_var = mbsr_info_create_internal (
        ncgi ? ncgi_local_nonprim : NULL,
        ecgi ? ecgi_local_nonprim : NULL
        );

    if (!mbsr_info_local_var) {
        goto end;
    }

    return mbsr_info_local_var;
end:
    if (ncgi_local_nonprim) {
        ncgi_free(ncgi_local_nonprim);
        ncgi_local_nonprim = NULL;
    }
    if (ecgi_local_nonprim) {
        ecgi_free(ecgi_local_nonprim);
        ecgi_local_nonprim = NULL;
    }
    return NULL;

}
