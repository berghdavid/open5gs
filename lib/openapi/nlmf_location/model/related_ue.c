#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "related_ue.h"



static related_ue_t *related_ue_create_internal(
    char *applicationlayer_id,
    related_ue_type_t *related_ue_type
    ) {
    related_ue_t *related_ue_local_var = malloc(sizeof(related_ue_t));
    if (!related_ue_local_var) {
        return NULL;
    }
    memset(related_ue_local_var, 0, sizeof(related_ue_t));
    related_ue_local_var->_library_owned = 1;
    related_ue_local_var->applicationlayer_id = applicationlayer_id;
    related_ue_local_var->related_ue_type = related_ue_type;
    return related_ue_local_var;
}

__attribute__((deprecated)) related_ue_t *related_ue_create(
    char *applicationlayer_id,
    related_ue_type_t *related_ue_type
    ) {
    related_ue_t *result = related_ue_create_internal (
        applicationlayer_id,
        related_ue_type
        );
    if (!result) {
    }
    return result;
}

void related_ue_free(related_ue_t *related_ue) {
    if(NULL == related_ue){
        return ;
    }
    if(related_ue->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "related_ue_free");
        return ;
    }
    listEntry_t *listEntry;
    if (related_ue->applicationlayer_id) {
        free(related_ue->applicationlayer_id);
        related_ue->applicationlayer_id = NULL;
    }
    if (related_ue->related_ue_type) {
        related_ue_type_free(related_ue->related_ue_type);
        related_ue->related_ue_type = NULL;
    }
    free(related_ue);
}

cJSON *related_ue_convertToJSON(related_ue_t *related_ue) {
    cJSON *item = cJSON_CreateObject();

    // related_ue->applicationlayer_id
    if (!related_ue->applicationlayer_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "applicationlayerId", related_ue->applicationlayer_id) == NULL) {
    goto fail; //String
    }


    // related_ue->related_ue_type
    if (!related_ue->related_ue_type) {
        goto fail;
    }
    cJSON *related_ue_type_local_JSON = related_ue_type_convertToJSON(related_ue->related_ue_type);
    if(related_ue_type_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "relatedUeType", related_ue_type_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

related_ue_t *related_ue_parseFromJSON(cJSON *related_ueJSON){

    related_ue_t *related_ue_local_var = NULL;

    char *applicationlayer_id_local_str = NULL;

    // define the local variable for related_ue->related_ue_type
    related_ue_type_t *related_ue_type_local_nonprim = NULL;

    // related_ue->applicationlayer_id
    cJSON *applicationlayer_id = cJSON_GetObjectItemCaseSensitive(related_ueJSON, "applicationlayerId");
    if (cJSON_IsNull(applicationlayer_id)) {
        applicationlayer_id = NULL;
    }
    if (!applicationlayer_id) {
        goto end;
    }

    
    if(!cJSON_IsString(applicationlayer_id))
    {
    goto end; //String
    }

    // related_ue->related_ue_type
    cJSON *related_ue_type = cJSON_GetObjectItemCaseSensitive(related_ueJSON, "relatedUeType");
    if (cJSON_IsNull(related_ue_type)) {
        related_ue_type = NULL;
    }
    if (!related_ue_type) {
        goto end;
    }

    
    related_ue_type_local_nonprim = related_ue_type_parseFromJSON(related_ue_type); //nonprimitive


    if (applicationlayer_id && !cJSON_IsNull(applicationlayer_id)) applicationlayer_id_local_str = strdup(applicationlayer_id->valuestring);

    related_ue_local_var = related_ue_create_internal (
        applicationlayer_id_local_str,
        related_ue_type_local_nonprim
        );

    if (!related_ue_local_var) {
        goto end;
    }

    return related_ue_local_var;
end:
    if (applicationlayer_id_local_str) {
        free(applicationlayer_id_local_str);
        applicationlayer_id_local_str = NULL;
    }
    if (related_ue_type_local_nonprim) {
        related_ue_type_free(related_ue_type_local_nonprim);
        related_ue_type_local_nonprim = NULL;
    }
    return NULL;

}
