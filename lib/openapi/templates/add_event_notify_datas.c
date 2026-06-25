#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "add_event_notify_datas.h"



static add_event_notify_datas_t *add_event_notify_datas_create_internal(
    list_t *add_event_notify_datas
    ) {
    add_event_notify_datas_t *add_event_notify_datas_local_var = malloc(sizeof(add_event_notify_datas_t));
    if (!add_event_notify_datas_local_var) {
        return NULL;
    }
    memset(add_event_notify_datas_local_var, 0, sizeof(add_event_notify_datas_t));
    add_event_notify_datas_local_var->_library_owned = 1;
    add_event_notify_datas_local_var->add_event_notify_datas = add_event_notify_datas;
    return add_event_notify_datas_local_var;
}

__attribute__((deprecated)) add_event_notify_datas_t *add_event_notify_datas_create(
    list_t *add_event_notify_datas
    ) {
    add_event_notify_datas_t *result = add_event_notify_datas_create_internal (
        add_event_notify_datas
        );
    if (!result) {
    }
    return result;
}

void add_event_notify_datas_free(add_event_notify_datas_t *add_event_notify_datas) {
    if(NULL == add_event_notify_datas){
        return ;
    }
    if(add_event_notify_datas->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "add_event_notify_datas_free");
        return ;
    }
    listEntry_t *listEntry;
    if (add_event_notify_datas->add_event_notify_datas) {
        list_ForEach(listEntry, add_event_notify_datas->add_event_notify_datas) {
            event_notify_data_free(listEntry->data);
        }
        list_freeList(add_event_notify_datas->add_event_notify_datas);
        add_event_notify_datas->add_event_notify_datas = NULL;
    }
    free(add_event_notify_datas);
}

cJSON *add_event_notify_datas_convertToJSON(add_event_notify_datas_t *add_event_notify_datas) {
    cJSON *item = cJSON_CreateObject();

    // add_event_notify_datas->add_event_notify_datas
    if(add_event_notify_datas->add_event_notify_datas) {
        cJSON *add_event_notify_datas_cjson = cJSON_AddArrayToObject(item, "addEventNotifyDatas");
        if(add_event_notify_datas_cjson == NULL) {
            goto fail; //nonprimitive container
        }

        listEntry_t *add_event_notify_datasListEntry;
        if (add_event_notify_datas->add_event_notify_datas) {
            list_ForEach(add_event_notify_datasListEntry, add_event_notify_datas->add_event_notify_datas) {
                cJSON *itemLocal = event_notify_data_convertToJSON(add_event_notify_datasListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(add_event_notify_datas_cjson, itemLocal);
            }
        }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

add_event_notify_datas_t *add_event_notify_datas_parseFromJSON(cJSON *add_event_notify_datasJSON){

    add_event_notify_datas_t *add_event_notify_datas_local_var = NULL;

    // define the local list for add_event_notify_datas->add_event_notify_datas
    list_t *add_event_notify_datasList = NULL;

    // add_event_notify_datas->add_event_notify_datas
    cJSON *add_event_notify_datas = cJSON_GetObjectItemCaseSensitive(add_event_notify_datasJSON, "addEventNotifyDatas");
    if (cJSON_IsNull(add_event_notify_datas)) {
        add_event_notify_datas = NULL;
    }
    if (add_event_notify_datas) { 
    cJSON *add_event_notify_datas_local_nonprimitive = NULL;
    if(!cJSON_IsArray(add_event_notify_datas)){
        goto end; //nonprimitive container
    }

    add_event_notify_datasList = list_createList();

    cJSON_ArrayForEach(add_event_notify_datas_local_nonprimitive,add_event_notify_datas )
    {
        if(!cJSON_IsObject(add_event_notify_datas_local_nonprimitive)){
            goto end;
        }
        event_notify_data_t *add_event_notify_datasItem = event_notify_data_parseFromJSON(add_event_notify_datas_local_nonprimitive);

        list_addElement(add_event_notify_datasList, add_event_notify_datasItem);
    }
    }



    add_event_notify_datas_local_var = add_event_notify_datas_create_internal (
        add_event_notify_datas ? add_event_notify_datasList : NULL
        );

    if (!add_event_notify_datas_local_var) {
        goto end;
    }

    return add_event_notify_datas_local_var;
end:
    if (add_event_notify_datasList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, add_event_notify_datasList) {
            event_notify_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(add_event_notify_datasList);
        add_event_notify_datasList = NULL;
    }
    return NULL;

}
