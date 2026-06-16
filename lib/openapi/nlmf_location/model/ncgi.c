#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ncgi.h"



static ncgi_t *ncgi_create_internal(
    plmn_id_t *plmn_id,
    char *nr_cell_id,
    char *nid
    ) {
    ncgi_t *ncgi_local_var = malloc(sizeof(ncgi_t));
    if (!ncgi_local_var) {
        return NULL;
    }
    memset(ncgi_local_var, 0, sizeof(ncgi_t));
    ncgi_local_var->_library_owned = 1;
    ncgi_local_var->plmn_id = plmn_id;
    ncgi_local_var->nr_cell_id = nr_cell_id;
    ncgi_local_var->nid = nid;
    return ncgi_local_var;
}

__attribute__((deprecated)) ncgi_t *ncgi_create(
    plmn_id_t *plmn_id,
    char *nr_cell_id,
    char *nid
    ) {
    ncgi_t *result = ncgi_create_internal (
        plmn_id,
        nr_cell_id,
        nid
        );
    if (!result) {
    }
    return result;
}

void ncgi_free(ncgi_t *ncgi) {
    if(NULL == ncgi){
        return ;
    }
    if(ncgi->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ncgi_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ncgi->plmn_id) {
        plmn_id_free(ncgi->plmn_id);
        ncgi->plmn_id = NULL;
    }
    if (ncgi->nr_cell_id) {
        free(ncgi->nr_cell_id);
        ncgi->nr_cell_id = NULL;
    }
    if (ncgi->nid) {
        free(ncgi->nid);
        ncgi->nid = NULL;
    }
    free(ncgi);
}

cJSON *ncgi_convertToJSON(ncgi_t *ncgi) {
    cJSON *item = cJSON_CreateObject();

    // ncgi->plmn_id
    if (!ncgi->plmn_id) {
        goto fail;
    }
    cJSON *plmn_id_local_JSON = plmn_id_convertToJSON(ncgi->plmn_id);
    if(plmn_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ncgi->nr_cell_id
    if (!ncgi->nr_cell_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "nrCellId", ncgi->nr_cell_id) == NULL) {
    goto fail; //String
    }


    // ncgi->nid
    if(ncgi->nid) {
    if(cJSON_AddStringToObject(item, "nid", ncgi->nid) == NULL) {
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

ncgi_t *ncgi_parseFromJSON(cJSON *ncgiJSON){

    ncgi_t *ncgi_local_var = NULL;

    // define the local variable for ncgi->plmn_id
    plmn_id_t *plmn_id_local_nonprim = NULL;

    char *nr_cell_id_local_str = NULL;

    char *nid_local_str = NULL;

    // ncgi->plmn_id
    cJSON *plmn_id = cJSON_GetObjectItemCaseSensitive(ncgiJSON, "plmnId");
    if (cJSON_IsNull(plmn_id)) {
        plmn_id = NULL;
    }
    if (!plmn_id) {
        goto end;
    }

    
    plmn_id_local_nonprim = plmn_id_parseFromJSON(plmn_id); //nonprimitive

    // ncgi->nr_cell_id
    cJSON *nr_cell_id = cJSON_GetObjectItemCaseSensitive(ncgiJSON, "nrCellId");
    if (cJSON_IsNull(nr_cell_id)) {
        nr_cell_id = NULL;
    }
    if (!nr_cell_id) {
        goto end;
    }

    
    if(!cJSON_IsString(nr_cell_id))
    {
    goto end; //String
    }

    // ncgi->nid
    cJSON *nid = cJSON_GetObjectItemCaseSensitive(ncgiJSON, "nid");
    if (cJSON_IsNull(nid)) {
        nid = NULL;
    }
    if (nid) { 
    if(!cJSON_IsString(nid) && !cJSON_IsNull(nid))
    {
    goto end; //String
    }
    }


    if (nr_cell_id && !cJSON_IsNull(nr_cell_id)) nr_cell_id_local_str = strdup(nr_cell_id->valuestring);
    if (nid && !cJSON_IsNull(nid)) nid_local_str = strdup(nid->valuestring);

    ncgi_local_var = ncgi_create_internal (
        plmn_id_local_nonprim,
        nr_cell_id_local_str,
        nid_local_str
        );

    if (!ncgi_local_var) {
        goto end;
    }

    return ncgi_local_var;
end:
    if (plmn_id_local_nonprim) {
        plmn_id_free(plmn_id_local_nonprim);
        plmn_id_local_nonprim = NULL;
    }
    if (nr_cell_id_local_str) {
        free(nr_cell_id_local_str);
        nr_cell_id_local_str = NULL;
    }
    if (nid_local_str) {
        free(nid_local_str);
        nid_local_str = NULL;
    }
    return NULL;

}
