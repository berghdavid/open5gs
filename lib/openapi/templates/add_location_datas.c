#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "add_location_datas.h"



static add_location_datas_t *add_location_datas_create_internal(
    list_t *add_location_datas
    ) {
    add_location_datas_t *add_location_datas_local_var = malloc(sizeof(add_location_datas_t));
    if (!add_location_datas_local_var) {
        return NULL;
    }
    memset(add_location_datas_local_var, 0, sizeof(add_location_datas_t));
    add_location_datas_local_var->_library_owned = 1;
    add_location_datas_local_var->add_location_datas = add_location_datas;
    return add_location_datas_local_var;
}

__attribute__((deprecated)) add_location_datas_t *add_location_datas_create(
    list_t *add_location_datas
    ) {
    add_location_datas_t *result = add_location_datas_create_internal (
        add_location_datas
        );
    if (!result) {
    }
    return result;
}

void add_location_datas_free(add_location_datas_t *add_location_datas) {
    if(NULL == add_location_datas){
        return ;
    }
    if(add_location_datas->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "add_location_datas_free");
        return ;
    }
    listEntry_t *listEntry;
    if (add_location_datas->add_location_datas) {
        list_ForEach(listEntry, add_location_datas->add_location_datas) {
            location_data_free(listEntry->data);
        }
        list_freeList(add_location_datas->add_location_datas);
        add_location_datas->add_location_datas = NULL;
    }
    free(add_location_datas);
}

cJSON *add_location_datas_convertToJSON(add_location_datas_t *add_location_datas) {
    cJSON *item = cJSON_CreateObject();

    // add_location_datas->add_location_datas
    if(add_location_datas->add_location_datas) {
        cJSON *add_location_datas_cjson = cJSON_AddArrayToObject(item, "addLocationDatas");
        if(add_location_datas_cjson == NULL) {
            goto fail; //nonprimitive container
        }

        listEntry_t *add_location_datasListEntry;
        if (add_location_datas->add_location_datas) {
            list_ForEach(add_location_datasListEntry, add_location_datas->add_location_datas) {
                cJSON *itemLocal = location_data_convertToJSON(add_location_datasListEntry->data);
                if(itemLocal == NULL) {
                    goto fail;
                }
                cJSON_AddItemToArray(add_location_datas_cjson, itemLocal);
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

add_location_datas_t *add_location_datas_parseFromJSON(cJSON *add_location_datasJSON){

    add_location_datas_t *add_location_datas_local_var = NULL;

    // define the local list for add_location_datas->add_location_datas
    list_t *add_location_datasList = NULL;

    // add_location_datas->add_location_datas
    cJSON *add_location_datas = cJSON_GetObjectItemCaseSensitive(add_location_datasJSON, "addLocationDatas");
    if (cJSON_IsNull(add_location_datas)) {
        add_location_datas = NULL;
    }
    if (add_location_datas) { 
    cJSON *add_location_datas_local_nonprimitive = NULL;
    if(!cJSON_IsArray(add_location_datas)){
        goto end; //nonprimitive container
    }

    add_location_datasList = list_createList();

    cJSON_ArrayForEach(add_location_datas_local_nonprimitive,add_location_datas )
    {
        if(!cJSON_IsObject(add_location_datas_local_nonprimitive)){
            goto end;
        }
        location_data_t *add_location_datasItem = location_data_parseFromJSON(add_location_datas_local_nonprimitive);

        list_addElement(add_location_datasList, add_location_datasItem);
    }
    }



    add_location_datas_local_var = add_location_datas_create_internal (
        add_location_datas ? add_location_datasList : NULL
        );

    if (!add_location_datas_local_var) {
        goto end;
    }

    return add_location_datas_local_var;
end:
    if (add_location_datasList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, add_location_datasList) {
            location_data_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(add_location_datasList);
        add_location_datasList = NULL;
    }
    return NULL;

}
