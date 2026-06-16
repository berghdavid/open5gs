#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cipher_response_data.h"



static cipher_response_data_t *cipher_response_data_create_internal(
    lmf_broadcast_data_availability__e data_availability
    ) {
    cipher_response_data_t *cipher_response_data_local_var = malloc(sizeof(cipher_response_data_t));
    if (!cipher_response_data_local_var) {
        return NULL;
    }
    memset(cipher_response_data_local_var, 0, sizeof(cipher_response_data_t));
    cipher_response_data_local_var->_library_owned = 1;
    cipher_response_data_local_var->data_availability = data_availability;
    return cipher_response_data_local_var;
}

__attribute__((deprecated)) cipher_response_data_t *cipher_response_data_create(
    lmf_broadcast_data_availability__e data_availability
    ) {
    cipher_response_data_t *result = cipher_response_data_create_internal (
        data_availability
        );
    if (!result) {
    }
    return result;
}

void cipher_response_data_free(cipher_response_data_t *cipher_response_data) {
    if(NULL == cipher_response_data){
        return ;
    }
    if(cipher_response_data->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "cipher_response_data_free");
        return ;
    }
    listEntry_t *listEntry;
    free(cipher_response_data);
}

cJSON *cipher_response_data_convertToJSON(cipher_response_data_t *cipher_response_data) {
    cJSON *item = cJSON_CreateObject();

    // cipher_response_data->data_availability
    if (lmf_broadcast_data_availability__NULL == cipher_response_data->data_availability) {
        goto fail;
    }
    cJSON *data_availability_local_JSON = data_availability_convertToJSON(cipher_response_data->data_availability);
    if(data_availability_local_JSON == NULL) {
        goto fail; // custom
    }
    cJSON_AddItemToObject(item, "dataAvailability", data_availability_local_JSON);
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

cipher_response_data_t *cipher_response_data_parseFromJSON(cJSON *cipher_response_dataJSON){

    cipher_response_data_t *cipher_response_data_local_var = NULL;

    // define the local variable for cipher_response_data->data_availability
    lmf_broadcast_data_availability__e data_availability_local_nonprim = 0;

    // cipher_response_data->data_availability
    cJSON *data_availability = cJSON_GetObjectItemCaseSensitive(cipher_response_dataJSON, "dataAvailability");
    if (cJSON_IsNull(data_availability)) {
        data_availability = NULL;
    }
    if (!data_availability) {
        goto end;
    }

    
    data_availability_local_nonprim = data_availability_parseFromJSON(data_availability); //custom



    cipher_response_data_local_var = cipher_response_data_create_internal (
        data_availability_local_nonprim
        );

    if (!cipher_response_data_local_var) {
        goto end;
    }

    return cipher_response_data_local_var;
end:
    if (data_availability_local_nonprim) {
        data_availability_local_nonprim = 0;
    }
    return NULL;

}
