#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tai.h"



static tai_t *tai_create_internal(
    plmn_id_t *plmn_id,
    char *tac,
    char *nid
    ) {
    tai_t *tai_local_var = malloc(sizeof(tai_t));
    if (!tai_local_var) {
        return NULL;
    }
    memset(tai_local_var, 0, sizeof(tai_t));
    tai_local_var->_library_owned = 1;
    tai_local_var->plmn_id = plmn_id;
    tai_local_var->tac = tac;
    tai_local_var->nid = nid;
    return tai_local_var;
}

__attribute__((deprecated)) tai_t *tai_create(
    plmn_id_t *plmn_id,
    char *tac,
    char *nid
    ) {
    tai_t *result = tai_create_internal (
        plmn_id,
        tac,
        nid
        );
    if (!result) {
    }
    return result;
}

void tai_free(tai_t *tai) {
    if(NULL == tai){
        return ;
    }
    if(tai->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "tai_free");
        return ;
    }
    listEntry_t *listEntry;
    if (tai->plmn_id) {
        plmn_id_free(tai->plmn_id);
        tai->plmn_id = NULL;
    }
    if (tai->tac) {
        free(tai->tac);
        tai->tac = NULL;
    }
    if (tai->nid) {
        free(tai->nid);
        tai->nid = NULL;
    }
    free(tai);
}

cJSON *tai_convertToJSON(tai_t *tai) {
    cJSON *item = cJSON_CreateObject();

    // tai->plmn_id
    if (!tai->plmn_id) {
        goto fail;
    }
    cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(tai->plmn_id);
    if(plmn_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // tai->tac
    if (!tai->tac) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "tac", tai->tac) == NULL) {
    goto fail; //String
    }


    // tai->nid
    if(tai->nid) {
    if(cJSON_AddStringToObject(item, "nid", tai->nid) == NULL) {
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

tai_t *tai_parseFromJSON(cJSON *taiJSON){

    tai_t *tai_local_var = NULL;

    // define the local variable for tai->plmn_id
    plmn_id_t *plmn_id_local_nonprim = NULL;

    char *tac_local_str = NULL;

    char *nid_local_str = NULL;

    // tai->plmn_id
    cJSON *plmn_id = cJSON_GetObjectItemCaseSensitive(taiJSON, "plmnId");
    if (cJSON_IsNull(plmn_id)) {
        plmn_id = NULL;
    }
    if (!plmn_id) {
        goto end;
    }

    
    plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id); //nonprimitive

    // tai->tac
    cJSON *tac = cJSON_GetObjectItemCaseSensitive(taiJSON, "tac");
    if (cJSON_IsNull(tac)) {
        tac = NULL;
    }
    if (!tac) {
        goto end;
    }

    
    if(!cJSON_IsString(tac))
    {
    goto end; //String
    }

    // tai->nid
    cJSON *nid = cJSON_GetObjectItemCaseSensitive(taiJSON, "nid");
    if (cJSON_IsNull(nid)) {
        nid = NULL;
    }
    if (nid) { 
    if(!cJSON_IsString(nid) && !cJSON_IsNull(nid))
    {
    goto end; //String
    }
    }


    if (tac && !cJSON_IsNull(tac)) tac_local_str = strdup(tac->valuestring);
    if (nid && !cJSON_IsNull(nid)) nid_local_str = strdup(nid->valuestring);

    tai_local_var = tai_create_internal (
        plmn_id_local_nonprim,
        tac_local_str,
        nid_local_str
        );

    if (!tai_local_var) {
        goto end;
    }

    return tai_local_var;
end:
    if (plmn_id_local_nonprim) {
        plmn_id_free(plmn_id_local_nonprim);
        plmn_id_local_nonprim = NULL;
    }
    if (tac_local_str) {
        free(tac_local_str);
        tac_local_str = NULL;
    }
    if (nid_local_str) {
        free(nid_local_str);
        nid_local_str = NULL;
    }
    return NULL;

}
