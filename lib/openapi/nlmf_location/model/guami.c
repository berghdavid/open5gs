#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "guami.h"



static guami_t *guami_create_internal(
    plmn_id_nid_t *plmn_id,
    char *amf_id
    ) {
    guami_t *guami_local_var = malloc(sizeof(guami_t));
    if (!guami_local_var) {
        return NULL;
    }
    memset(guami_local_var, 0, sizeof(guami_t));
    guami_local_var->_library_owned = 1;
    guami_local_var->plmn_id = plmn_id;
    guami_local_var->amf_id = amf_id;
    return guami_local_var;
}

__attribute__((deprecated)) guami_t *guami_create(
    plmn_id_nid_t *plmn_id,
    char *amf_id
    ) {
    guami_t *result = guami_create_internal (
        plmn_id,
        amf_id
        );
    if (!result) {
    }
    return result;
}

void guami_free(guami_t *guami) {
    if(NULL == guami){
        return ;
    }
    if(guami->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "guami_free");
        return ;
    }
    listEntry_t *listEntry;
    if (guami->plmn_id) {
        plmn_id_nid_free(guami->plmn_id);
        guami->plmn_id = NULL;
    }
    if (guami->amf_id) {
        free(guami->amf_id);
        guami->amf_id = NULL;
    }
    free(guami);
}

cJSON *guami_convertToJSON(guami_t *guami) {
    cJSON *item = cJSON_CreateObject();

    // guami->plmn_id
    if (!guami->plmn_id) {
        goto fail;
    }
    cJSON *plmn_id_local_JSON = plmn_id_nid_convertToJSON(guami->plmn_id);
    if(plmn_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "plmnId", plmn_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // guami->amf_id
    if (!guami->amf_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "amfId", guami->amf_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

guami_t *guami_parseFromJSON(cJSON *guamiJSON){

    guami_t *guami_local_var = NULL;

    // define the local variable for guami->plmn_id
    plmn_id_nid_t *plmn_id_local_nonprim = NULL;

    char *amf_id_local_str = NULL;

    // guami->plmn_id
    cJSON *plmn_id = cJSON_GetObjectItemCaseSensitive(guamiJSON, "plmnId");
    if (cJSON_IsNull(plmn_id)) {
        plmn_id = NULL;
    }
    if (!plmn_id) {
        goto end;
    }

    
    plmn_id_local_nonprim = plmn_id_nid_parseFromJSON(plmn_id); //nonprimitive

    // guami->amf_id
    cJSON *amf_id = cJSON_GetObjectItemCaseSensitive(guamiJSON, "amfId");
    if (cJSON_IsNull(amf_id)) {
        amf_id = NULL;
    }
    if (!amf_id) {
        goto end;
    }

    
    if(!cJSON_IsString(amf_id))
    {
    goto end; //String
    }


    if (amf_id && !cJSON_IsNull(amf_id)) amf_id_local_str = strdup(amf_id->valuestring);

    guami_local_var = guami_create_internal (
        plmn_id_local_nonprim,
        amf_id_local_str
        );

    if (!guami_local_var) {
        goto end;
    }

    return guami_local_var;
end:
    if (plmn_id_local_nonprim) {
        plmn_id_nid_free(plmn_id_local_nonprim);
        plmn_id_local_nonprim = NULL;
    }
    if (amf_id_local_str) {
        free(amf_id_local_str);
        amf_id_local_str = NULL;
    }
    return NULL;

}
