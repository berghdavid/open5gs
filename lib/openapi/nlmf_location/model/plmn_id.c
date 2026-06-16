#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plmn_id.h"



static plmn_id_t *plmn_id_create_internal(
    char *mcc,
    char *mnc
    ) {
    plmn_id_t *plmn_id_local_var = malloc(sizeof(plmn_id_t));
    if (!plmn_id_local_var) {
        return NULL;
    }
    memset(plmn_id_local_var, 0, sizeof(plmn_id_t));
    plmn_id_local_var->_library_owned = 1;
    plmn_id_local_var->mcc = mcc;
    plmn_id_local_var->mnc = mnc;
    return plmn_id_local_var;
}

__attribute__((deprecated)) plmn_id_t *plmn_id_create(
    char *mcc,
    char *mnc
    ) {
    plmn_id_t *result = plmn_id_create_internal (
        mcc,
        mnc
        );
    if (!result) {
    }
    return result;
}

void plmn_id_free(plmn_id_t *plmn_id) {
    if(NULL == plmn_id){
        return ;
    }
    if(plmn_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plmn_id_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plmn_id->mcc) {
        free(plmn_id->mcc);
        plmn_id->mcc = NULL;
    }
    if (plmn_id->mnc) {
        free(plmn_id->mnc);
        plmn_id->mnc = NULL;
    }
    free(plmn_id);
}

cJSON *plmn_id_convertToJSON(plmn_id_t *plmn_id) {
    cJSON *item = cJSON_CreateObject();

    // plmn_id->mcc
    if (!plmn_id->mcc) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mcc", plmn_id->mcc) == NULL) {
    goto fail; //String
    }


    // plmn_id->mnc
    if (!plmn_id->mnc) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mnc", plmn_id->mnc) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

plmn_id_t *plmn_id_parseFromJSON(cJSON *plmn_idJSON){

    plmn_id_t *plmn_id_local_var = NULL;

    char *mcc_local_str = NULL;

    char *mnc_local_str = NULL;

    // plmn_id->mcc
    cJSON *mcc = cJSON_GetObjectItemCaseSensitive(plmn_idJSON, "mcc");
    if (cJSON_IsNull(mcc)) {
        mcc = NULL;
    }
    if (!mcc) {
        goto end;
    }

    
    if(!cJSON_IsString(mcc))
    {
    goto end; //String
    }

    // plmn_id->mnc
    cJSON *mnc = cJSON_GetObjectItemCaseSensitive(plmn_idJSON, "mnc");
    if (cJSON_IsNull(mnc)) {
        mnc = NULL;
    }
    if (!mnc) {
        goto end;
    }

    
    if(!cJSON_IsString(mnc))
    {
    goto end; //String
    }


    if (mcc && !cJSON_IsNull(mcc)) mcc_local_str = strdup(mcc->valuestring);
    if (mnc && !cJSON_IsNull(mnc)) mnc_local_str = strdup(mnc->valuestring);

    plmn_id_local_var = plmn_id_create_internal (
        mcc_local_str,
        mnc_local_str
        );

    if (!plmn_id_local_var) {
        goto end;
    }

    return plmn_id_local_var;
end:
    if (mcc_local_str) {
        free(mcc_local_str);
        mcc_local_str = NULL;
    }
    if (mnc_local_str) {
        free(mnc_local_str);
        mnc_local_str = NULL;
    }
    return NULL;

}
