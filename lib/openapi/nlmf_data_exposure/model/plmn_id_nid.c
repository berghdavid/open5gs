#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "plmn_id_nid.h"



static plmn_id_nid_t *plmn_id_nid_create_internal(
    char *mcc,
    char *mnc,
    char *nid
    ) {
    plmn_id_nid_t *plmn_id_nid_local_var = malloc(sizeof(plmn_id_nid_t));
    if (!plmn_id_nid_local_var) {
        return NULL;
    }
    memset(plmn_id_nid_local_var, 0, sizeof(plmn_id_nid_t));
    plmn_id_nid_local_var->_library_owned = 1;
    plmn_id_nid_local_var->mcc = mcc;
    plmn_id_nid_local_var->mnc = mnc;
    plmn_id_nid_local_var->nid = nid;
    return plmn_id_nid_local_var;
}

__attribute__((deprecated)) plmn_id_nid_t *plmn_id_nid_create(
    char *mcc,
    char *mnc,
    char *nid
    ) {
    plmn_id_nid_t *result = plmn_id_nid_create_internal (
        mcc,
        mnc,
        nid
        );
    if (!result) {
    }
    return result;
}

void plmn_id_nid_free(plmn_id_nid_t *plmn_id_nid) {
    if(NULL == plmn_id_nid){
        return ;
    }
    if(plmn_id_nid->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "plmn_id_nid_free");
        return ;
    }
    listEntry_t *listEntry;
    if (plmn_id_nid->mcc) {
        free(plmn_id_nid->mcc);
        plmn_id_nid->mcc = NULL;
    }
    if (plmn_id_nid->mnc) {
        free(plmn_id_nid->mnc);
        plmn_id_nid->mnc = NULL;
    }
    if (plmn_id_nid->nid) {
        free(plmn_id_nid->nid);
        plmn_id_nid->nid = NULL;
    }
    free(plmn_id_nid);
}

cJSON *plmn_id_nid_convertToJSON(plmn_id_nid_t *plmn_id_nid) {
    cJSON *item = cJSON_CreateObject();

    // plmn_id_nid->mcc
    if (!plmn_id_nid->mcc) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mcc", plmn_id_nid->mcc) == NULL) {
    goto fail; //String
    }


    // plmn_id_nid->mnc
    if (!plmn_id_nid->mnc) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "mnc", plmn_id_nid->mnc) == NULL) {
    goto fail; //String
    }


    // plmn_id_nid->nid
    if(plmn_id_nid->nid) {
    if(cJSON_AddStringToObject(item, "nid", plmn_id_nid->nid) == NULL) {
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

plmn_id_nid_t *plmn_id_nid_parseFromJSON(cJSON *plmn_id_nidJSON){

    plmn_id_nid_t *plmn_id_nid_local_var = NULL;

    char *mcc_local_str = NULL;

    char *mnc_local_str = NULL;

    char *nid_local_str = NULL;

    // plmn_id_nid->mcc
    cJSON *mcc = cJSON_GetObjectItemCaseSensitive(plmn_id_nidJSON, "mcc");
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

    // plmn_id_nid->mnc
    cJSON *mnc = cJSON_GetObjectItemCaseSensitive(plmn_id_nidJSON, "mnc");
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

    // plmn_id_nid->nid
    cJSON *nid = cJSON_GetObjectItemCaseSensitive(plmn_id_nidJSON, "nid");
    if (cJSON_IsNull(nid)) {
        nid = NULL;
    }
    if (nid) { 
    if(!cJSON_IsString(nid) && !cJSON_IsNull(nid))
    {
    goto end; //String
    }
    }


    if (mcc && !cJSON_IsNull(mcc)) mcc_local_str = strdup(mcc->valuestring);
    if (mnc && !cJSON_IsNull(mnc)) mnc_local_str = strdup(mnc->valuestring);
    if (nid && !cJSON_IsNull(nid)) nid_local_str = strdup(nid->valuestring);

    plmn_id_nid_local_var = plmn_id_nid_create_internal (
        mcc_local_str,
        mnc_local_str,
        nid_local_str
        );

    if (!plmn_id_nid_local_var) {
        goto end;
    }

    return plmn_id_nid_local_var;
end:
    if (mcc_local_str) {
        free(mcc_local_str);
        mcc_local_str = NULL;
    }
    if (mnc_local_str) {
        free(mnc_local_str);
        mnc_local_str = NULL;
    }
    if (nid_local_str) {
        free(nid_local_str);
        nid_local_str = NULL;
    }
    return NULL;

}
