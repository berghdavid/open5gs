#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "determine_location_request.h"



static determine_location_request_t *determine_location_request_create_internal(
    input_data_t *json_data,
    binary_t* binary_data_lpp_message,
    binary_t* binary_data_lpp_message_ext1,
    binary_t* binary_data_lpp_message_ext2
    ) {
    determine_location_request_t *determine_location_request_local_var = malloc(sizeof(determine_location_request_t));
    if (!determine_location_request_local_var) {
        return NULL;
    }
    memset(determine_location_request_local_var, 0, sizeof(determine_location_request_t));
    determine_location_request_local_var->_library_owned = 1;
    determine_location_request_local_var->json_data = json_data;
    determine_location_request_local_var->binary_data_lpp_message = binary_data_lpp_message;
    determine_location_request_local_var->binary_data_lpp_message_ext1 = binary_data_lpp_message_ext1;
    determine_location_request_local_var->binary_data_lpp_message_ext2 = binary_data_lpp_message_ext2;
    return determine_location_request_local_var;
}

__attribute__((deprecated)) determine_location_request_t *determine_location_request_create(
    input_data_t *json_data,
    binary_t* binary_data_lpp_message,
    binary_t* binary_data_lpp_message_ext1,
    binary_t* binary_data_lpp_message_ext2
    ) {
    determine_location_request_t *result = determine_location_request_create_internal (
        json_data,
        binary_data_lpp_message,
        binary_data_lpp_message_ext1,
        binary_data_lpp_message_ext2
        );
    if (!result) {
    }
    return result;
}

void determine_location_request_free(determine_location_request_t *determine_location_request) {
    if(NULL == determine_location_request){
        return ;
    }
    if(determine_location_request->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "determine_location_request_free");
        return ;
    }
    listEntry_t *listEntry;
    if (determine_location_request->json_data) {
        input_data_free(determine_location_request->json_data);
        determine_location_request->json_data = NULL;
    }
    if (determine_location_request->binary_data_lpp_message) {
        free(determine_location_request->binary_data_lpp_message->data);
        determine_location_request->binary_data_lpp_message = NULL;
    }
    if (determine_location_request->binary_data_lpp_message_ext1) {
        free(determine_location_request->binary_data_lpp_message_ext1->data);
        determine_location_request->binary_data_lpp_message_ext1 = NULL;
    }
    if (determine_location_request->binary_data_lpp_message_ext2) {
        free(determine_location_request->binary_data_lpp_message_ext2->data);
        determine_location_request->binary_data_lpp_message_ext2 = NULL;
    }
    free(determine_location_request);
}

cJSON *determine_location_request_convertToJSON(determine_location_request_t *determine_location_request) {
    cJSON *item = cJSON_CreateObject();

    // determine_location_request->json_data
    if(determine_location_request->json_data) {
    cJSON *json_data_local_JSON = input_data_convertToJSON(determine_location_request->json_data);
    if(json_data_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "jsonData", json_data_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // determine_location_request->binary_data_lpp_message
    if(determine_location_request->binary_data_lpp_message) {
    char* encoded_str_binary_data_lpp_message = base64encode(determine_location_request->binary_data_lpp_message->data,determine_location_request->binary_data_lpp_message->len);
    if(cJSON_AddStringToObject(item, "binaryDataLppMessage", encoded_str_binary_data_lpp_message) == NULL) {
    goto fail; //Binary
    }
    free (encoded_str_binary_data_lpp_message);
    }


    // determine_location_request->binary_data_lpp_message_ext1
    if(determine_location_request->binary_data_lpp_message_ext1) {
    char* encoded_str_binary_data_lpp_message_ext1 = base64encode(determine_location_request->binary_data_lpp_message_ext1->data,determine_location_request->binary_data_lpp_message_ext1->len);
    if(cJSON_AddStringToObject(item, "binaryDataLppMessageExt1", encoded_str_binary_data_lpp_message_ext1) == NULL) {
    goto fail; //Binary
    }
    free (encoded_str_binary_data_lpp_message_ext1);
    }


    // determine_location_request->binary_data_lpp_message_ext2
    if(determine_location_request->binary_data_lpp_message_ext2) {
    char* encoded_str_binary_data_lpp_message_ext2 = base64encode(determine_location_request->binary_data_lpp_message_ext2->data,determine_location_request->binary_data_lpp_message_ext2->len);
    if(cJSON_AddStringToObject(item, "binaryDataLppMessageExt2", encoded_str_binary_data_lpp_message_ext2) == NULL) {
    goto fail; //Binary
    }
    free (encoded_str_binary_data_lpp_message_ext2);
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

determine_location_request_t *determine_location_request_parseFromJSON(cJSON *determine_location_requestJSON){

    determine_location_request_t *determine_location_request_local_var = NULL;

    // define the local variable for determine_location_request->json_data
    input_data_t *json_data_local_nonprim = NULL;

    // determine_location_request->json_data
    cJSON *json_data = cJSON_GetObjectItemCaseSensitive(determine_location_requestJSON, "jsonData");
    if (cJSON_IsNull(json_data)) {
        json_data = NULL;
    }
    if (json_data) { 
    json_data_local_nonprim = input_data_parseFromJSON(json_data); //nonprimitive
    }

    // determine_location_request->binary_data_lpp_message
    cJSON *binary_data_lpp_message = cJSON_GetObjectItemCaseSensitive(determine_location_requestJSON, "binaryDataLppMessage");
    if (cJSON_IsNull(binary_data_lpp_message)) {
        binary_data_lpp_message = NULL;
    }
    binary_t* decoded_str_binary_data_lpp_message = malloc(sizeof(struct binary_t));
    if (binary_data_lpp_message) { 
    if(!cJSON_IsString(binary_data_lpp_message))
    {
    goto end; //Binary
    }
    decoded_str_binary_data_lpp_message->data = base64decode(binary_data_lpp_message->valuestring, strlen(binary_data_lpp_message->valuestring), &decoded_str_binary_data_lpp_message->len);
    if (!decoded_str_binary_data_lpp_message->data) {
        goto end;
    }
    }

    // determine_location_request->binary_data_lpp_message_ext1
    cJSON *binary_data_lpp_message_ext1 = cJSON_GetObjectItemCaseSensitive(determine_location_requestJSON, "binaryDataLppMessageExt1");
    if (cJSON_IsNull(binary_data_lpp_message_ext1)) {
        binary_data_lpp_message_ext1 = NULL;
    }
    binary_t* decoded_str_binary_data_lpp_message_ext1 = malloc(sizeof(struct binary_t));
    if (binary_data_lpp_message_ext1) { 
    if(!cJSON_IsString(binary_data_lpp_message_ext1))
    {
    goto end; //Binary
    }
    decoded_str_binary_data_lpp_message_ext1->data = base64decode(binary_data_lpp_message_ext1->valuestring, strlen(binary_data_lpp_message_ext1->valuestring), &decoded_str_binary_data_lpp_message_ext1->len);
    if (!decoded_str_binary_data_lpp_message_ext1->data) {
        goto end;
    }
    }

    // determine_location_request->binary_data_lpp_message_ext2
    cJSON *binary_data_lpp_message_ext2 = cJSON_GetObjectItemCaseSensitive(determine_location_requestJSON, "binaryDataLppMessageExt2");
    if (cJSON_IsNull(binary_data_lpp_message_ext2)) {
        binary_data_lpp_message_ext2 = NULL;
    }
    binary_t* decoded_str_binary_data_lpp_message_ext2 = malloc(sizeof(struct binary_t));
    if (binary_data_lpp_message_ext2) { 
    if(!cJSON_IsString(binary_data_lpp_message_ext2))
    {
    goto end; //Binary
    }
    decoded_str_binary_data_lpp_message_ext2->data = base64decode(binary_data_lpp_message_ext2->valuestring, strlen(binary_data_lpp_message_ext2->valuestring), &decoded_str_binary_data_lpp_message_ext2->len);
    if (!decoded_str_binary_data_lpp_message_ext2->data) {
        goto end;
    }
    }



    determine_location_request_local_var = determine_location_request_create_internal (
        json_data ? json_data_local_nonprim : NULL,
        binary_data_lpp_message ? decoded_str_binary_data_lpp_message : NULL,
        binary_data_lpp_message_ext1 ? decoded_str_binary_data_lpp_message_ext1 : NULL,
        binary_data_lpp_message_ext2 ? decoded_str_binary_data_lpp_message_ext2 : NULL
        );

    if (!determine_location_request_local_var) {
        goto end;
    }

    return determine_location_request_local_var;
end:
    if (json_data_local_nonprim) {
        input_data_free(json_data_local_nonprim);
        json_data_local_nonprim = NULL;
    }
    return NULL;

}
