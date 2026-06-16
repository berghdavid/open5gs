#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ml_model_inter_ind.h"



static ml_model_inter_ind_t *ml_model_inter_ind_create_internal(
    nwdaf_event_t *analytics_id,
    list_t *vendor_list
    ) {
    ml_model_inter_ind_t *ml_model_inter_ind_local_var = malloc(sizeof(ml_model_inter_ind_t));
    if (!ml_model_inter_ind_local_var) {
        return NULL;
    }
    memset(ml_model_inter_ind_local_var, 0, sizeof(ml_model_inter_ind_t));
    ml_model_inter_ind_local_var->_library_owned = 1;
    ml_model_inter_ind_local_var->analytics_id = analytics_id;
    ml_model_inter_ind_local_var->vendor_list = vendor_list;
    return ml_model_inter_ind_local_var;
}

__attribute__((deprecated)) ml_model_inter_ind_t *ml_model_inter_ind_create(
    nwdaf_event_t *analytics_id,
    list_t *vendor_list
    ) {
    ml_model_inter_ind_t *result = ml_model_inter_ind_create_internal (
        analytics_id,
        vendor_list
        );
    if (!result) {
    }
    return result;
}

void ml_model_inter_ind_free(ml_model_inter_ind_t *ml_model_inter_ind) {
    if(NULL == ml_model_inter_ind){
        return ;
    }
    if(ml_model_inter_ind->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ml_model_inter_ind_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ml_model_inter_ind->analytics_id) {
        nwdaf_event_free(ml_model_inter_ind->analytics_id);
        ml_model_inter_ind->analytics_id = NULL;
    }
    if (ml_model_inter_ind->vendor_list) {
        list_ForEach(listEntry, ml_model_inter_ind->vendor_list) {
            free(listEntry->data);
        }
        list_freeList(ml_model_inter_ind->vendor_list);
        ml_model_inter_ind->vendor_list = NULL;
    }
    free(ml_model_inter_ind);
}

cJSON *ml_model_inter_ind_convertToJSON(ml_model_inter_ind_t *ml_model_inter_ind) {
    cJSON *item = cJSON_CreateObject();

    // ml_model_inter_ind->analytics_id
    if (!ml_model_inter_ind->analytics_id) {
        goto fail;
    }
    cJSON *analytics_id_local_JSON = nwdaf_event_convertToJSON(ml_model_inter_ind->analytics_id);
    if(analytics_id_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "analyticsId", analytics_id_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }


    // ml_model_inter_ind->vendor_list
    if (!ml_model_inter_ind->vendor_list) {
        goto fail;
    }
    cJSON *vendor_list = cJSON_AddArrayToObject(item, "vendorList");
    if(vendor_list == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *vendor_listListEntry;
    list_ForEach(vendor_listListEntry, ml_model_inter_ind->vendor_list) {
    if(cJSON_AddStringToObject(vendor_list, "", vendor_listListEntry->data) == NULL)
    {
        goto fail;
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ml_model_inter_ind_t *ml_model_inter_ind_parseFromJSON(cJSON *ml_model_inter_indJSON){

    ml_model_inter_ind_t *ml_model_inter_ind_local_var = NULL;

    // define the local variable for ml_model_inter_ind->analytics_id
    nwdaf_event_t *analytics_id_local_nonprim = NULL;

    // define the local list for ml_model_inter_ind->vendor_list
    list_t *vendor_listList = NULL;

    // ml_model_inter_ind->analytics_id
    cJSON *analytics_id = cJSON_GetObjectItemCaseSensitive(ml_model_inter_indJSON, "analyticsId");
    if (cJSON_IsNull(analytics_id)) {
        analytics_id = NULL;
    }
    if (!analytics_id) {
        goto end;
    }

    
    analytics_id_local_nonprim = nwdaf_event_parseFromJSON(analytics_id); //nonprimitive

    // ml_model_inter_ind->vendor_list
    cJSON *vendor_list = cJSON_GetObjectItemCaseSensitive(ml_model_inter_indJSON, "vendorList");
    if (cJSON_IsNull(vendor_list)) {
        vendor_list = NULL;
    }
    if (!vendor_list) {
        goto end;
    }

    
    cJSON *vendor_list_local = NULL;
    if(!cJSON_IsArray(vendor_list)) {
        goto end;//primitive container
    }
    vendor_listList = list_createList();

    cJSON_ArrayForEach(vendor_list_local, vendor_list)
    {
        if(!cJSON_IsString(vendor_list_local))
        {
            goto end;
        }
        list_addElement(vendor_listList , strdup(vendor_list_local->valuestring));
    }



    ml_model_inter_ind_local_var = ml_model_inter_ind_create_internal (
        analytics_id_local_nonprim,
        vendor_listList
        );

    if (!ml_model_inter_ind_local_var) {
        goto end;
    }

    return ml_model_inter_ind_local_var;
end:
    if (analytics_id_local_nonprim) {
        nwdaf_event_free(analytics_id_local_nonprim);
        analytics_id_local_nonprim = NULL;
    }
    if (vendor_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, vendor_listList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(vendor_listList);
        vendor_listList = NULL;
    }
    return NULL;

}
