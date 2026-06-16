#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ecgi.h"



static ecgi_t *ecgi_create_internal(
    plmn_id_t *plmn_id,
    char *eutra_cell_id,
    char *nid
    ) {
    ecgi_t *ecgi_local_var = malloc(sizeof(ecgi_t));
    if (!ecgi_local_var) {
        return NULL;
    }
    memset(ecgi_local_var, 0, sizeof(ecgi_t));
    ecgi_local_var->_library_owned = 1;
    ecgi_local_var->plmn_id = plmn_id;
    ecgi_local_var->eutra_cell_id = eutra_cell_id;
    ecgi_local_var->nid = nid;
    return ecgi_local_var;
}

__attribute__((deprecated)) ecgi_t *ecgi_create(
    plmn_id_t *plmn_id,
    char *eutra_cell_id,
    char *nid
    ) {
    ecgi_t *result = ecgi_create_internal (
        plmn_id,
        eutra_cell_id,
        nid
        );
    if (!result) {
    }
    return result;
}

void ecgi_free(ecgi_t *ecgi) {
    if(NULL == ecgi){
        return ;
    }
    if(ecgi->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ecgi_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ecgi->plmn_id) {
        plmn_id_free(ecgi->plmn_id);
        ecgi->plmn_id = NULL;
    }
    if (ecgi->eutra_cell_id) {
        free(ecgi->eutra_cell_id);
        ecgi->eutra_cell_id = NULL;
    }
    if (ecgi->nid) {
        free(ecgi->nid);
        ecgi->nid = NULL;
    }
    free(ecgi);
}

cJSON *ecgi_convertToJSON(ecgi_t *ecgi) {
    cJSON *item = cJSON_CreateObject();

    // ecgi->plmn_id
    if (!ecgi->plmn_id) {
        goto fail;
    }
    cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(ecgi->plmn_id);
    if(plmn_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ecgi->eutra_cell_id
    if (!ecgi->eutra_cell_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "eutraCellId", ecgi->eutra_cell_id) == NULL) {
    goto fail; //String
    }


    // ecgi->nid
    if(ecgi->nid) {
    if(cJSON_AddStringToObject(item, "nid", ecgi->nid) == NULL) {
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

ecgi_t *ecgi_parseFromJSON(cJSON *ecgiJSON){

    ecgi_t *ecgi_local_var = NULL;

    // define the local variable for ecgi->plmn_id
    plmn_id_t *plmn_id_local_nonprim = NULL;

    char *eutra_cell_id_local_str = NULL;

    char *nid_local_str = NULL;

    // ecgi->plmn_id
    cJSON *plmn_id = cJSON_GetObjectItemCaseSensitive(ecgiJSON, "plmnId");
    if (cJSON_IsNull(plmn_id)) {
        plmn_id = NULL;
    }
    if (!plmn_id) {
        goto end;
    }

    
    plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id); //nonprimitive

    // ecgi->eutra_cell_id
    cJSON *eutra_cell_id = cJSON_GetObjectItemCaseSensitive(ecgiJSON, "eutraCellId");
    if (cJSON_IsNull(eutra_cell_id)) {
        eutra_cell_id = NULL;
    }
    if (!eutra_cell_id) {
        goto end;
    }

    
    if(!cJSON_IsString(eutra_cell_id))
    {
    goto end; //String
    }

    // ecgi->nid
    cJSON *nid = cJSON_GetObjectItemCaseSensitive(ecgiJSON, "nid");
    if (cJSON_IsNull(nid)) {
        nid = NULL;
    }
    if (nid) { 
    if(!cJSON_IsString(nid) && !cJSON_IsNull(nid))
    {
    goto end; //String
    }
    }


    if (eutra_cell_id && !cJSON_IsNull(eutra_cell_id)) eutra_cell_id_local_str = strdup(eutra_cell_id->valuestring);
    if (nid && !cJSON_IsNull(nid)) nid_local_str = strdup(nid->valuestring);

    ecgi_local_var = ecgi_create_internal (
        plmn_id_local_nonprim,
        eutra_cell_id_local_str,
        nid_local_str
        );

    if (!ecgi_local_var) {
        goto end;
    }

    return ecgi_local_var;
end:
    if (plmn_id_local_nonprim) {
        plmn_id_free(plmn_id_local_nonprim);
        plmn_id_local_nonprim = NULL;
    }
    if (eutra_cell_id_local_str) {
        free(eutra_cell_id_local_str);
        eutra_cell_id_local_str = NULL;
    }
    if (nid_local_str) {
        free(nid_local_str);
        nid_local_str = NULL;
    }
    return NULL;

}
