#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "presence_info.h"



static presence_info_t *presence_info_create_internal(
    char *pra_id,
    char *additional_pra_id,
    presence_state_t *presence_state,
    list_t *tracking_area_list,
    list_t *ecgi_list,
    list_t *ncgi_list,
    list_t *global_ran_node_id_list,
    list_t *globale_nb_id_list
    ) {
    presence_info_t *presence_info_local_var = malloc(sizeof(presence_info_t));
    if (!presence_info_local_var) {
        return NULL;
    }
    memset(presence_info_local_var, 0, sizeof(presence_info_t));
    presence_info_local_var->_library_owned = 1;
    presence_info_local_var->pra_id = pra_id;
    presence_info_local_var->additional_pra_id = additional_pra_id;
    presence_info_local_var->presence_state = presence_state;
    presence_info_local_var->tracking_area_list = tracking_area_list;
    presence_info_local_var->ecgi_list = ecgi_list;
    presence_info_local_var->ncgi_list = ncgi_list;
    presence_info_local_var->global_ran_node_id_list = global_ran_node_id_list;
    presence_info_local_var->globale_nb_id_list = globale_nb_id_list;
    return presence_info_local_var;
}

__attribute__((deprecated)) presence_info_t *presence_info_create(
    char *pra_id,
    char *additional_pra_id,
    presence_state_t *presence_state,
    list_t *tracking_area_list,
    list_t *ecgi_list,
    list_t *ncgi_list,
    list_t *global_ran_node_id_list,
    list_t *globale_nb_id_list
    ) {
    presence_info_t *result = presence_info_create_internal (
        pra_id,
        additional_pra_id,
        presence_state,
        tracking_area_list,
        ecgi_list,
        ncgi_list,
        global_ran_node_id_list,
        globale_nb_id_list
        );
    if (!result) {
    }
    return result;
}

void presence_info_free(presence_info_t *presence_info) {
    if(NULL == presence_info){
        return ;
    }
    if(presence_info->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "presence_info_free");
        return ;
    }
    listEntry_t *listEntry;
    if (presence_info->pra_id) {
        free(presence_info->pra_id);
        presence_info->pra_id = NULL;
    }
    if (presence_info->additional_pra_id) {
        free(presence_info->additional_pra_id);
        presence_info->additional_pra_id = NULL;
    }
    if (presence_info->presence_state) {
        presence_state_free(presence_info->presence_state);
        presence_info->presence_state = NULL;
    }
    if (presence_info->tracking_area_list) {
        list_ForEach(listEntry, presence_info->tracking_area_list) {
            tai_free(listEntry->data);
        }
        list_freeList(presence_info->tracking_area_list);
        presence_info->tracking_area_list = NULL;
    }
    if (presence_info->ecgi_list) {
        list_ForEach(listEntry, presence_info->ecgi_list) {
            ecgi_free(listEntry->data);
        }
        list_freeList(presence_info->ecgi_list);
        presence_info->ecgi_list = NULL;
    }
    if (presence_info->ncgi_list) {
        list_ForEach(listEntry, presence_info->ncgi_list) {
            ncgi_free(listEntry->data);
        }
        list_freeList(presence_info->ncgi_list);
        presence_info->ncgi_list = NULL;
    }
    if (presence_info->global_ran_node_id_list) {
        list_ForEach(listEntry, presence_info->global_ran_node_id_list) {
            global_ran_node_id_free(listEntry->data);
        }
        list_freeList(presence_info->global_ran_node_id_list);
        presence_info->global_ran_node_id_list = NULL;
    }
    if (presence_info->globale_nb_id_list) {
        list_ForEach(listEntry, presence_info->globale_nb_id_list) {
            global_ran_node_id_free(listEntry->data);
        }
        list_freeList(presence_info->globale_nb_id_list);
        presence_info->globale_nb_id_list = NULL;
    }
    free(presence_info);
}

cJSON *presence_info_convertToJSON(presence_info_t *presence_info) {
    cJSON *item = cJSON_CreateObject();

    // presence_info->pra_id
    if(presence_info->pra_id) {
    if(cJSON_AddStringToObject(item, "praId", presence_info->pra_id) == NULL) {
    goto fail; //String
    }
    }


    // presence_info->additional_pra_id
    if(presence_info->additional_pra_id) {
    if(cJSON_AddStringToObject(item, "additionalPraId", presence_info->additional_pra_id) == NULL) {
    goto fail; //String
    }
    }


    // presence_info->presence_state
    if(presence_info->presence_state) {
    cJSON *presence_state_local_JSON = presence_state_convertToJSON(presence_info->presence_state);
    if(presence_state_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "presenceState", presence_state_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }
    }


    // presence_info->tracking_area_list
    if(presence_info->tracking_area_list) {
    cJSON *tracking_area_list = cJSON_AddArrayToObject(item, "trackingAreaList");
    if(tracking_area_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *tracking_area_listListEntry;
    if (presence_info->tracking_area_list) {
    list_ForEach(tracking_area_listListEntry, presence_info->tracking_area_list) {
    cJSON *itemLocal = tai_convertToJSON(tracking_area_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(tracking_area_list, itemLocal);
    }
    }
    }


    // presence_info->ecgi_list
    if(presence_info->ecgi_list) {
    cJSON *ecgi_list = cJSON_AddArrayToObject(item, "ecgiList");
    if(ecgi_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ecgi_listListEntry;
    if (presence_info->ecgi_list) {
    list_ForEach(ecgi_listListEntry, presence_info->ecgi_list) {
    cJSON *itemLocal = ecgi_convertToJSON(ecgi_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ecgi_list, itemLocal);
    }
    }
    }


    // presence_info->ncgi_list
    if(presence_info->ncgi_list) {
    cJSON *ncgi_list = cJSON_AddArrayToObject(item, "ncgiList");
    if(ncgi_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ncgi_listListEntry;
    if (presence_info->ncgi_list) {
    list_ForEach(ncgi_listListEntry, presence_info->ncgi_list) {
    cJSON *itemLocal = ncgi_convertToJSON(ncgi_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ncgi_list, itemLocal);
    }
    }
    }


    // presence_info->global_ran_node_id_list
    if(presence_info->global_ran_node_id_list) {
    cJSON *global_ran_node_id_list = cJSON_AddArrayToObject(item, "globalRanNodeIdList");
    if(global_ran_node_id_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *global_ran_node_id_listListEntry;
    if (presence_info->global_ran_node_id_list) {
    list_ForEach(global_ran_node_id_listListEntry, presence_info->global_ran_node_id_list) {
    cJSON *itemLocal = global_ran_node_id_convertToJSON(global_ran_node_id_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(global_ran_node_id_list, itemLocal);
    }
    }
    }


    // presence_info->globale_nb_id_list
    if(presence_info->globale_nb_id_list) {
    cJSON *globale_nb_id_list = cJSON_AddArrayToObject(item, "globaleNbIdList");
    if(globale_nb_id_list == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *globale_nb_id_listListEntry;
    if (presence_info->globale_nb_id_list) {
    list_ForEach(globale_nb_id_listListEntry, presence_info->globale_nb_id_list) {
    cJSON *itemLocal = global_ran_node_id_convertToJSON(globale_nb_id_listListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(globale_nb_id_list, itemLocal);
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

presence_info_t *presence_info_parseFromJSON(cJSON *presence_infoJSON){

    presence_info_t *presence_info_local_var = NULL;

    char *pra_id_local_str = NULL;

    char *additional_pra_id_local_str = NULL;

    // define the local variable for presence_info->presence_state
    presence_state_t *presence_state_local_nonprim = NULL;

    // define the local list for presence_info->tracking_area_list
    list_t *tracking_area_listList = NULL;

    // define the local list for presence_info->ecgi_list
    list_t *ecgi_listList = NULL;

    // define the local list for presence_info->ncgi_list
    list_t *ncgi_listList = NULL;

    // define the local list for presence_info->global_ran_node_id_list
    list_t *global_ran_node_id_listList = NULL;

    // define the local list for presence_info->globale_nb_id_list
    list_t *globale_nb_id_listList = NULL;

    // presence_info->pra_id
    cJSON *pra_id = cJSON_GetObjectItemCaseSensitive(presence_infoJSON, "praId");
    if (cJSON_IsNull(pra_id)) {
        pra_id = NULL;
    }
    if (pra_id) { 
    if(!cJSON_IsString(pra_id) && !cJSON_IsNull(pra_id))
    {
    goto end; //String
    }
    }

    // presence_info->additional_pra_id
    cJSON *additional_pra_id = cJSON_GetObjectItemCaseSensitive(presence_infoJSON, "additionalPraId");
    if (cJSON_IsNull(additional_pra_id)) {
        additional_pra_id = NULL;
    }
    if (additional_pra_id) { 
    if(!cJSON_IsString(additional_pra_id) && !cJSON_IsNull(additional_pra_id))
    {
    goto end; //String
    }
    }

    // presence_info->presence_state
    cJSON *presence_state = cJSON_GetObjectItemCaseSensitive(presence_infoJSON, "presenceState");
    if (cJSON_IsNull(presence_state)) {
        presence_state = NULL;
    }
    if (presence_state) { 
    presence_state_local_nonprim = presence_state_parseFromJSON(presence_state); //nonprimitive
    }

    // presence_info->tracking_area_list
    cJSON *tracking_area_list = cJSON_GetObjectItemCaseSensitive(presence_infoJSON, "trackingAreaList");
    if (cJSON_IsNull(tracking_area_list)) {
        tracking_area_list = NULL;
    }
    if (tracking_area_list) { 
    cJSON *tracking_area_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(tracking_area_list)){
        goto end; //nonprimitive container
    }

    tracking_area_listList = list_createList();

    cJSON_ArrayForEach(tracking_area_list_local_nonprimitive,tracking_area_list )
    {
        if(!cJSON_IsObject(tracking_area_list_local_nonprimitive)){
            goto end;
        }
        tai_t *tracking_area_listItem = tai_parseFromJSON(tracking_area_list_local_nonprimitive);

        list_addElement(tracking_area_listList, tracking_area_listItem);
    }
    }

    // presence_info->ecgi_list
    cJSON *ecgi_list = cJSON_GetObjectItemCaseSensitive(presence_infoJSON, "ecgiList");
    if (cJSON_IsNull(ecgi_list)) {
        ecgi_list = NULL;
    }
    if (ecgi_list) { 
    cJSON *ecgi_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ecgi_list)){
        goto end; //nonprimitive container
    }

    ecgi_listList = list_createList();

    cJSON_ArrayForEach(ecgi_list_local_nonprimitive,ecgi_list )
    {
        if(!cJSON_IsObject(ecgi_list_local_nonprimitive)){
            goto end;
        }
        ecgi_t *ecgi_listItem = ecgi_parseFromJSON(ecgi_list_local_nonprimitive);

        list_addElement(ecgi_listList, ecgi_listItem);
    }
    }

    // presence_info->ncgi_list
    cJSON *ncgi_list = cJSON_GetObjectItemCaseSensitive(presence_infoJSON, "ncgiList");
    if (cJSON_IsNull(ncgi_list)) {
        ncgi_list = NULL;
    }
    if (ncgi_list) { 
    cJSON *ncgi_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ncgi_list)){
        goto end; //nonprimitive container
    }

    ncgi_listList = list_createList();

    cJSON_ArrayForEach(ncgi_list_local_nonprimitive,ncgi_list )
    {
        if(!cJSON_IsObject(ncgi_list_local_nonprimitive)){
            goto end;
        }
        ncgi_t *ncgi_listItem = ncgi_parseFromJSON(ncgi_list_local_nonprimitive);

        list_addElement(ncgi_listList, ncgi_listItem);
    }
    }

    // presence_info->global_ran_node_id_list
    cJSON *global_ran_node_id_list = cJSON_GetObjectItemCaseSensitive(presence_infoJSON, "globalRanNodeIdList");
    if (cJSON_IsNull(global_ran_node_id_list)) {
        global_ran_node_id_list = NULL;
    }
    if (global_ran_node_id_list) { 
    cJSON *global_ran_node_id_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(global_ran_node_id_list)){
        goto end; //nonprimitive container
    }

    global_ran_node_id_listList = list_createList();

    cJSON_ArrayForEach(global_ran_node_id_list_local_nonprimitive,global_ran_node_id_list )
    {
        if(!cJSON_IsObject(global_ran_node_id_list_local_nonprimitive)){
            goto end;
        }
        global_ran_node_id_t *global_ran_node_id_listItem = global_ran_node_id_parseFromJSON(global_ran_node_id_list_local_nonprimitive);

        list_addElement(global_ran_node_id_listList, global_ran_node_id_listItem);
    }
    }

    // presence_info->globale_nb_id_list
    cJSON *globale_nb_id_list = cJSON_GetObjectItemCaseSensitive(presence_infoJSON, "globaleNbIdList");
    if (cJSON_IsNull(globale_nb_id_list)) {
        globale_nb_id_list = NULL;
    }
    if (globale_nb_id_list) { 
    cJSON *globale_nb_id_list_local_nonprimitive = NULL;
    if(!cJSON_IsArray(globale_nb_id_list)){
        goto end; //nonprimitive container
    }

    globale_nb_id_listList = list_createList();

    cJSON_ArrayForEach(globale_nb_id_list_local_nonprimitive,globale_nb_id_list )
    {
        if(!cJSON_IsObject(globale_nb_id_list_local_nonprimitive)){
            goto end;
        }
        global_ran_node_id_t *globale_nb_id_listItem = global_ran_node_id_parseFromJSON(globale_nb_id_list_local_nonprimitive);

        list_addElement(globale_nb_id_listList, globale_nb_id_listItem);
    }
    }


    if (pra_id && !cJSON_IsNull(pra_id)) pra_id_local_str = strdup(pra_id->valuestring);
    if (additional_pra_id && !cJSON_IsNull(additional_pra_id)) additional_pra_id_local_str = strdup(additional_pra_id->valuestring);

    presence_info_local_var = presence_info_create_internal (
        pra_id_local_str,
        additional_pra_id_local_str,
        presence_state ? presence_state_local_nonprim : NULL,
        tracking_area_list ? tracking_area_listList : NULL,
        ecgi_list ? ecgi_listList : NULL,
        ncgi_list ? ncgi_listList : NULL,
        global_ran_node_id_list ? global_ran_node_id_listList : NULL,
        globale_nb_id_list ? globale_nb_id_listList : NULL
        );

    if (!presence_info_local_var) {
        goto end;
    }

    return presence_info_local_var;
end:
    if (pra_id_local_str) {
        free(pra_id_local_str);
        pra_id_local_str = NULL;
    }
    if (additional_pra_id_local_str) {
        free(additional_pra_id_local_str);
        additional_pra_id_local_str = NULL;
    }
    if (presence_state_local_nonprim) {
        presence_state_free(presence_state_local_nonprim);
        presence_state_local_nonprim = NULL;
    }
    if (tracking_area_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, tracking_area_listList) {
            tai_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(tracking_area_listList);
        tracking_area_listList = NULL;
    }
    if (ecgi_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ecgi_listList) {
            ecgi_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ecgi_listList);
        ecgi_listList = NULL;
    }
    if (ncgi_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ncgi_listList) {
            ncgi_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ncgi_listList);
        ncgi_listList = NULL;
    }
    if (global_ran_node_id_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, global_ran_node_id_listList) {
            global_ran_node_id_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(global_ran_node_id_listList);
        global_ran_node_id_listList = NULL;
    }
    if (globale_nb_id_listList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, globale_nb_id_listList) {
            global_ran_node_id_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(globale_nb_id_listList);
        globale_nb_id_listList = NULL;
    }
    return NULL;

}
