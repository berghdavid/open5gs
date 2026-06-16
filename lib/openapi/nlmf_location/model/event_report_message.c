#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_report_message.h"



static event_report_message_t *event_report_message_create_internal(
    event_class_t *event_class,
    ref_to_binary_data_t *event_content
    ) {
    event_report_message_t *event_report_message_local_var = malloc(sizeof(event_report_message_t));
    if (!event_report_message_local_var) {
        return NULL;
    }
    memset(event_report_message_local_var, 0, sizeof(event_report_message_t));
    event_report_message_local_var->_library_owned = 1;
    event_report_message_local_var->event_class = event_class;
    event_report_message_local_var->event_content = event_content;
    return event_report_message_local_var;
}

__attribute__((deprecated)) event_report_message_t *event_report_message_create(
    event_class_t *event_class,
    ref_to_binary_data_t *event_content
    ) {
    event_report_message_t *result = event_report_message_create_internal (
        event_class,
        event_content
        );
    if (!result) {
    }
    return result;
}

void event_report_message_free(event_report_message_t *event_report_message) {
    if(NULL == event_report_message){
        return ;
    }
    if(event_report_message->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "event_report_message_free");
        return ;
    }
    listEntry_t *listEntry;
    if (event_report_message->event_class) {
        event_class_free(event_report_message->event_class);
        event_report_message->event_class = NULL;
    }
    if (event_report_message->event_content) {
        ref_to_binary_data_free(event_report_message->event_content);
        event_report_message->event_content = NULL;
    }
    free(event_report_message);
}

cJSON *event_report_message_convertToJSON(event_report_message_t *event_report_message) {
    cJSON *item = cJSON_CreateObject();

    // event_report_message->event_class
    if (!event_report_message->event_class) {
        goto fail;
    }
    cJSON *event_class_local_JSON = event_class_convertToJSON(event_report_message->event_class);
    if(event_class_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "eventClass", event_class_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // event_report_message->event_content
    if (!event_report_message->event_content) {
        goto fail;
    }
    cJSON *event_content_local_JSON = ref_to_binary_data_convertToJSON(event_report_message->event_content);
    if(event_content_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "eventContent", event_content_local_JSON);
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

event_report_message_t *event_report_message_parseFromJSON(cJSON *event_report_messageJSON){

    event_report_message_t *event_report_message_local_var = NULL;

    // define the local variable for event_report_message->event_class
    event_class_t *event_class_local_nonprim = NULL;

    // define the local variable for event_report_message->event_content
    ref_to_binary_data_t *event_content_local_nonprim = NULL;

    // event_report_message->event_class
    cJSON *event_class = cJSON_GetObjectItemCaseSensitive(event_report_messageJSON, "eventClass");
    if (cJSON_IsNull(event_class)) {
        event_class = NULL;
    }
    if (!event_class) {
        goto end;
    }

    
    event_class_local_nonprim = event_class_parseFromJSON(event_class); //nonprimitive

    // event_report_message->event_content
    cJSON *event_content = cJSON_GetObjectItemCaseSensitive(event_report_messageJSON, "eventContent");
    if (cJSON_IsNull(event_content)) {
        event_content = NULL;
    }
    if (!event_content) {
        goto end;
    }

    
    event_content_local_nonprim = ref_to_binary_data_parseFromJSON(event_content); //nonprimitive



    event_report_message_local_var = event_report_message_create_internal (
        event_class_local_nonprim,
        event_content_local_nonprim
        );

    if (!event_report_message_local_var) {
        goto end;
    }

    return event_report_message_local_var;
end:
    if (event_class_local_nonprim) {
        event_class_free(event_class_local_nonprim);
        event_class_local_nonprim = NULL;
    }
    if (event_content_local_nonprim) {
        ref_to_binary_data_free(event_content_local_nonprim);
        event_content_local_nonprim = NULL;
    }
    return NULL;

}
