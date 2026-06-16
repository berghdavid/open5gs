#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ciphering_data_set.h"



static ciphering_data_set_t *ciphering_data_set_create_internal(
    int *ciphering_set_id,
    char *ciphering_key,
    char *c0,
    char *lte_pos_sib_types,
    char *nr_pos_sib_types,
    char *validity_start_time,
    int *validity_duration,
    char *tai_list
    ) {
    ciphering_data_set_t *ciphering_data_set_local_var = malloc(sizeof(ciphering_data_set_t));
    if (!ciphering_data_set_local_var) {
        return NULL;
    }
    memset(ciphering_data_set_local_var, 0, sizeof(ciphering_data_set_t));
    ciphering_data_set_local_var->_library_owned = 1;
    ciphering_data_set_local_var->ciphering_set_id = ciphering_set_id;
    ciphering_data_set_local_var->ciphering_key = ciphering_key;
    ciphering_data_set_local_var->c0 = c0;
    ciphering_data_set_local_var->lte_pos_sib_types = lte_pos_sib_types;
    ciphering_data_set_local_var->nr_pos_sib_types = nr_pos_sib_types;
    ciphering_data_set_local_var->validity_start_time = validity_start_time;
    ciphering_data_set_local_var->validity_duration = validity_duration;
    ciphering_data_set_local_var->tai_list = tai_list;
    return ciphering_data_set_local_var;
}

__attribute__((deprecated)) ciphering_data_set_t *ciphering_data_set_create(
    int *ciphering_set_id,
    char *ciphering_key,
    char *c0,
    char *lte_pos_sib_types,
    char *nr_pos_sib_types,
    char *validity_start_time,
    int *validity_duration,
    char *tai_list
    ) {
    int *ciphering_set_id_copy = NULL;
    if (ciphering_set_id) {
        ciphering_set_id_copy = malloc(sizeof(int));
        if (ciphering_set_id_copy) *ciphering_set_id_copy = *ciphering_set_id;
    }
    int *validity_duration_copy = NULL;
    if (validity_duration) {
        validity_duration_copy = malloc(sizeof(int));
        if (validity_duration_copy) *validity_duration_copy = *validity_duration;
    }
    ciphering_data_set_t *result = ciphering_data_set_create_internal (
        ciphering_set_id_copy,
        ciphering_key,
        c0,
        lte_pos_sib_types,
        nr_pos_sib_types,
        validity_start_time,
        validity_duration_copy,
        tai_list
        );
    if (!result) {
        free(ciphering_set_id_copy);
        free(validity_duration_copy);
    }
    return result;
}

void ciphering_data_set_free(ciphering_data_set_t *ciphering_data_set) {
    if(NULL == ciphering_data_set){
        return ;
    }
    if(ciphering_data_set->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ciphering_data_set_free");
        return ;
    }
    listEntry_t *listEntry;
    if (ciphering_data_set->ciphering_set_id) {
        free(ciphering_data_set->ciphering_set_id);
        ciphering_data_set->ciphering_set_id = NULL;
    }
    if (ciphering_data_set->ciphering_key) {
        free(ciphering_data_set->ciphering_key);
        ciphering_data_set->ciphering_key = NULL;
    }
    if (ciphering_data_set->c0) {
        free(ciphering_data_set->c0);
        ciphering_data_set->c0 = NULL;
    }
    if (ciphering_data_set->lte_pos_sib_types) {
        free(ciphering_data_set->lte_pos_sib_types);
        ciphering_data_set->lte_pos_sib_types = NULL;
    }
    if (ciphering_data_set->nr_pos_sib_types) {
        free(ciphering_data_set->nr_pos_sib_types);
        ciphering_data_set->nr_pos_sib_types = NULL;
    }
    if (ciphering_data_set->validity_start_time) {
        free(ciphering_data_set->validity_start_time);
        ciphering_data_set->validity_start_time = NULL;
    }
    if (ciphering_data_set->validity_duration) {
        free(ciphering_data_set->validity_duration);
        ciphering_data_set->validity_duration = NULL;
    }
    if (ciphering_data_set->tai_list) {
        free(ciphering_data_set->tai_list);
        ciphering_data_set->tai_list = NULL;
    }
    free(ciphering_data_set);
}

cJSON *ciphering_data_set_convertToJSON(ciphering_data_set_t *ciphering_data_set) {
    cJSON *item = cJSON_CreateObject();

    // ciphering_data_set->ciphering_set_id
    if (!ciphering_data_set->ciphering_set_id) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "cipheringSetID", *ciphering_data_set->ciphering_set_id) == NULL) {
    goto fail; //Numeric
    }


    // ciphering_data_set->ciphering_key
    if (!ciphering_data_set->ciphering_key) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "cipheringKey", ciphering_data_set->ciphering_key) == NULL) {
    goto fail; //ByteArray
    }


    // ciphering_data_set->c0
    if (!ciphering_data_set->c0) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "c0", ciphering_data_set->c0) == NULL) {
    goto fail; //ByteArray
    }


    // ciphering_data_set->lte_pos_sib_types
    if(ciphering_data_set->lte_pos_sib_types) {
    if(cJSON_AddStringToObject(item, "ltePosSibTypes", ciphering_data_set->lte_pos_sib_types) == NULL) {
    goto fail; //ByteArray
    }
    }


    // ciphering_data_set->nr_pos_sib_types
    if(ciphering_data_set->nr_pos_sib_types) {
    if(cJSON_AddStringToObject(item, "nrPosSibTypes", ciphering_data_set->nr_pos_sib_types) == NULL) {
    goto fail; //ByteArray
    }
    }


    // ciphering_data_set->validity_start_time
    if (!ciphering_data_set->validity_start_time) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "validityStartTime", ciphering_data_set->validity_start_time) == NULL) {
    goto fail; //Date-Time
    }


    // ciphering_data_set->validity_duration
    if (!ciphering_data_set->validity_duration) {
        goto fail;
    }
    if(cJSON_AddNumberToObject(item, "validityDuration", *ciphering_data_set->validity_duration) == NULL) {
    goto fail; //Numeric
    }


    // ciphering_data_set->tai_list
    if(ciphering_data_set->tai_list) {
    if(cJSON_AddStringToObject(item, "taiList", ciphering_data_set->tai_list) == NULL) {
    goto fail; //ByteArray
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ciphering_data_set_t *ciphering_data_set_parseFromJSON(cJSON *ciphering_data_setJSON){

    ciphering_data_set_t *ciphering_data_set_local_var = NULL;

    // define the local variable for ciphering_data_set->ciphering_set_id
    int *ciphering_set_id_local_var = NULL;

    char *ciphering_key_local_str = NULL;

    char *c0_local_str = NULL;

    char *lte_pos_sib_types_local_str = NULL;

    char *nr_pos_sib_types_local_str = NULL;

    char *validity_start_time_local_str = NULL;

    // define the local variable for ciphering_data_set->validity_duration
    int *validity_duration_local_var = NULL;

    char *tai_list_local_str = NULL;

    // ciphering_data_set->ciphering_set_id
    cJSON *ciphering_set_id = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "cipheringSetID");
    if (cJSON_IsNull(ciphering_set_id)) {
        ciphering_set_id = NULL;
    }
    if (!ciphering_set_id) {
        goto end;
    }

    
    if(!cJSON_IsNumber(ciphering_set_id))
    {
    goto end; //Numeric
    }
    ciphering_set_id_local_var = malloc(sizeof(int));
    if(!ciphering_set_id_local_var)
    {
        goto end;
    }
    *ciphering_set_id_local_var = ciphering_set_id->valuedouble;

    // ciphering_data_set->ciphering_key
    cJSON *ciphering_key = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "cipheringKey");
    if (cJSON_IsNull(ciphering_key)) {
        ciphering_key = NULL;
    }
    if (!ciphering_key) {
        goto end;
    }

    
    if(!cJSON_IsString(ciphering_key))
    {
    goto end; //ByteArray
    }

    // ciphering_data_set->c0
    cJSON *c0 = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "c0");
    if (cJSON_IsNull(c0)) {
        c0 = NULL;
    }
    if (!c0) {
        goto end;
    }

    
    if(!cJSON_IsString(c0))
    {
    goto end; //ByteArray
    }

    // ciphering_data_set->lte_pos_sib_types
    cJSON *lte_pos_sib_types = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "ltePosSibTypes");
    if (cJSON_IsNull(lte_pos_sib_types)) {
        lte_pos_sib_types = NULL;
    }
    if (lte_pos_sib_types) { 
    if(!cJSON_IsString(lte_pos_sib_types))
    {
    goto end; //ByteArray
    }
    }

    // ciphering_data_set->nr_pos_sib_types
    cJSON *nr_pos_sib_types = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "nrPosSibTypes");
    if (cJSON_IsNull(nr_pos_sib_types)) {
        nr_pos_sib_types = NULL;
    }
    if (nr_pos_sib_types) { 
    if(!cJSON_IsString(nr_pos_sib_types))
    {
    goto end; //ByteArray
    }
    }

    // ciphering_data_set->validity_start_time
    cJSON *validity_start_time = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "validityStartTime");
    if (cJSON_IsNull(validity_start_time)) {
        validity_start_time = NULL;
    }
    if (!validity_start_time) {
        goto end;
    }

    
    if(!cJSON_IsString(validity_start_time) && !cJSON_IsNull(validity_start_time))
    {
    goto end; //DateTime
    }

    // ciphering_data_set->validity_duration
    cJSON *validity_duration = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "validityDuration");
    if (cJSON_IsNull(validity_duration)) {
        validity_duration = NULL;
    }
    if (!validity_duration) {
        goto end;
    }

    
    if(!cJSON_IsNumber(validity_duration))
    {
    goto end; //Numeric
    }
    validity_duration_local_var = malloc(sizeof(int));
    if(!validity_duration_local_var)
    {
        goto end;
    }
    *validity_duration_local_var = validity_duration->valuedouble;

    // ciphering_data_set->tai_list
    cJSON *tai_list = cJSON_GetObjectItemCaseSensitive(ciphering_data_setJSON, "taiList");
    if (cJSON_IsNull(tai_list)) {
        tai_list = NULL;
    }
    if (tai_list) { 
    if(!cJSON_IsString(tai_list))
    {
    goto end; //ByteArray
    }
    }


    if (ciphering_key) ciphering_key_local_str = strdup(ciphering_key->valuestring);
    if (c0) c0_local_str = strdup(c0->valuestring);
    if (lte_pos_sib_types) lte_pos_sib_types_local_str = strdup(lte_pos_sib_types->valuestring);
    if (nr_pos_sib_types) nr_pos_sib_types_local_str = strdup(nr_pos_sib_types->valuestring);
    if (validity_start_time && !cJSON_IsNull(validity_start_time)) validity_start_time_local_str = strdup(validity_start_time->valuestring);
    if (tai_list) tai_list_local_str = strdup(tai_list->valuestring);

    ciphering_data_set_local_var = ciphering_data_set_create_internal (
        ciphering_set_id_local_var,
        ciphering_key_local_str,
        c0_local_str,
        lte_pos_sib_types_local_str,
        nr_pos_sib_types_local_str,
        validity_start_time_local_str,
        validity_duration_local_var,
        tai_list_local_str
        );

    if (!ciphering_data_set_local_var) {
        goto end;
    }

    return ciphering_data_set_local_var;
end:
    if (ciphering_set_id_local_var) {
        free(ciphering_set_id_local_var);
        ciphering_set_id_local_var = NULL;
    }
    if (ciphering_key_local_str) {
        free(ciphering_key_local_str);
        ciphering_key_local_str = NULL;
    }
    if (c0_local_str) {
        free(c0_local_str);
        c0_local_str = NULL;
    }
    if (lte_pos_sib_types_local_str) {
        free(lte_pos_sib_types_local_str);
        lte_pos_sib_types_local_str = NULL;
    }
    if (nr_pos_sib_types_local_str) {
        free(nr_pos_sib_types_local_str);
        nr_pos_sib_types_local_str = NULL;
    }
    if (validity_start_time_local_str) {
        free(validity_start_time_local_str);
        validity_start_time_local_str = NULL;
    }
    if (validity_duration_local_var) {
        free(validity_duration_local_var);
        validity_duration_local_var = NULL;
    }
    if (tai_list_local_str) {
        free(tai_list_local_str);
        tai_list_local_str = NULL;
    }
    return NULL;

}
