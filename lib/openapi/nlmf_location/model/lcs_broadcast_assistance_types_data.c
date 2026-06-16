#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lcs_broadcast_assistance_types_data.h"



static lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data_create_internal(
    char *location_assistance_type
    ) {
    lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data_local_var = malloc(sizeof(lcs_broadcast_assistance_types_data_t));
    if (!lcs_broadcast_assistance_types_data_local_var) {
        return NULL;
    }
    memset(lcs_broadcast_assistance_types_data_local_var, 0, sizeof(lcs_broadcast_assistance_types_data_t));
    lcs_broadcast_assistance_types_data_local_var->_library_owned = 1;
    lcs_broadcast_assistance_types_data_local_var->location_assistance_type = location_assistance_type;
    return lcs_broadcast_assistance_types_data_local_var;
}

__attribute__((deprecated)) lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data_create(
    char *location_assistance_type
    ) {
    lcs_broadcast_assistance_types_data_t *result = lcs_broadcast_assistance_types_data_create_internal (
        location_assistance_type
        );
    if (!result) {
    }
    return result;
}

void lcs_broadcast_assistance_types_data_free(lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data) {
    if(NULL == lcs_broadcast_assistance_types_data){
        return ;
    }
    if(lcs_broadcast_assistance_types_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "lcs_broadcast_assistance_types_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (lcs_broadcast_assistance_types_data->location_assistance_type) {
        free(lcs_broadcast_assistance_types_data->location_assistance_type);
        lcs_broadcast_assistance_types_data->location_assistance_type = NULL;
    }
    free(lcs_broadcast_assistance_types_data);
}

cJSON *lcs_broadcast_assistance_types_data_convertToJSON(lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data) {
    cJSON *item = cJSON_CreateObject();

    // lcs_broadcast_assistance_types_data->location_assistance_type
    if (!lcs_broadcast_assistance_types_data->location_assistance_type) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "locationAssistanceType", lcs_broadcast_assistance_types_data->location_assistance_type) == NULL) {
    goto fail; //ByteArray
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data_parseFromJSON(cJSON *lcs_broadcast_assistance_types_dataJSON){

    lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data_local_var = NULL;

    char *location_assistance_type_local_str = NULL;

    // lcs_broadcast_assistance_types_data->location_assistance_type
    cJSON *location_assistance_type = cJSON_GetObjectItemCaseSensitive(lcs_broadcast_assistance_types_dataJSON, "locationAssistanceType");
    if (cJSON_IsNull(location_assistance_type)) {
        location_assistance_type = NULL;
    }
    if (!location_assistance_type) {
        goto end;
    }

    
    if(!cJSON_IsString(location_assistance_type))
    {
    goto end; //ByteArray
    }


    if (location_assistance_type) location_assistance_type_local_str = strdup(location_assistance_type->valuestring);

    lcs_broadcast_assistance_types_data_local_var = lcs_broadcast_assistance_types_data_create_internal (
        location_assistance_type_local_str
        );

    if (!lcs_broadcast_assistance_types_data_local_var) {
        goto end;
    }

    return lcs_broadcast_assistance_types_data_local_var;
end:
    if (location_assistance_type_local_str) {
        free(location_assistance_type_local_str);
        location_assistance_type_local_str = NULL;
    }
    return NULL;

}
