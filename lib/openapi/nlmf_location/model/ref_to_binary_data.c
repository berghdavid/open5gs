#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ref_to_binary_data.h"



static ref_to_binary_data_t *ref_to_binary_data_create_internal(
    char *content_id
    ) {
    ref_to_binary_data_t *ref_to_binary_data_local_var = malloc(sizeof(ref_to_binary_data_t));
    if (!ref_to_binary_data_local_var) {
        return NULL;
    }
    memset(ref_to_binary_data_local_var, 0, sizeof(ref_to_binary_data_t));
    ref_to_binary_data_local_var->_library_owned = 1;
    ref_to_binary_data_local_var->content_id = content_id;
    return ref_to_binary_data_local_var;
}

__attribute__((deprecated)) ref_to_binary_data_t *ref_to_binary_data_create(
    char *content_id
    ) {
    ref_to_binary_data_t *result = ref_to_binary_data_create_internal (
        content_id
        );
    if (!result) {
    }
    return result;
}

void ref_to_binary_data_free(ref_to_binary_data_t *ref_to_binary_data) {
    if(NULL == ref_to_binary_data){
        return ;
    }
    if(ref_to_binary_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ref_to_binary_data_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ref_to_binary_data->content_id) {
        free(ref_to_binary_data->content_id);
        ref_to_binary_data->content_id = NULL;
    }
    free(ref_to_binary_data);
}

cJSON *ref_to_binary_data_convertToJSON(ref_to_binary_data_t *ref_to_binary_data) {
    cJSON *item = cJSON_CreateObject();

    // ref_to_binary_data->content_id
    if (!ref_to_binary_data->content_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "contentId", ref_to_binary_data->content_id) == NULL) {
    goto fail; //String
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ref_to_binary_data_t *ref_to_binary_data_parseFromJSON(cJSON *ref_to_binary_dataJSON){

    ref_to_binary_data_t *ref_to_binary_data_local_var = NULL;

    char *content_id_local_str = NULL;

    // ref_to_binary_data->content_id
    cJSON *content_id = cJSON_GetObjectItemCaseSensitive(ref_to_binary_dataJSON, "contentId");
    if (cJSON_IsNull(content_id)) {
        content_id = NULL;
    }
    if (!content_id) {
        goto end;
    }

    
    if(!cJSON_IsString(content_id))
    {
    goto end; //String
    }


    if (content_id && !cJSON_IsNull(content_id)) content_id_local_str = strdup(content_id->valuestring);

    ref_to_binary_data_local_var = ref_to_binary_data_create_internal (
        content_id_local_str
        );

    if (!ref_to_binary_data_local_var) {
        goto end;
    }

    return ref_to_binary_data_local_var;
end:
    if (content_id_local_str) {
        free(content_id_local_str);
        content_id_local_str = NULL;
    }
    return NULL;

}
