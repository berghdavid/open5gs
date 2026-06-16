#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "tnap_id.h"



static tnap_id_t *tnap_id_create_internal(
    char *ss_id,
    char *bss_id,
    char *civic_address
    ) {
    tnap_id_t *tnap_id_local_var = malloc(sizeof(tnap_id_t));
    if (!tnap_id_local_var) {
        return NULL;
    }
    memset(tnap_id_local_var, 0, sizeof(tnap_id_t));
    tnap_id_local_var->_library_owned = 1;
    tnap_id_local_var->ss_id = ss_id;
    tnap_id_local_var->bss_id = bss_id;
    tnap_id_local_var->civic_address = civic_address;
    return tnap_id_local_var;
}

__attribute__((deprecated)) tnap_id_t *tnap_id_create(
    char *ss_id,
    char *bss_id,
    char *civic_address
    ) {
    tnap_id_t *result = tnap_id_create_internal (
        ss_id,
        bss_id,
        civic_address
        );
    if (!result) {
    }
    return result;
}

void tnap_id_free(tnap_id_t *tnap_id) {
    if(NULL == tnap_id){
        return ;
    }
    if(tnap_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "tnap_id_free");
        return ;
    }
    listEntry_t *listEntry;
    if (tnap_id->ss_id) {
        free(tnap_id->ss_id);
        tnap_id->ss_id = NULL;
    }
    if (tnap_id->bss_id) {
        free(tnap_id->bss_id);
        tnap_id->bss_id = NULL;
    }
    if (tnap_id->civic_address) {
        free(tnap_id->civic_address);
        tnap_id->civic_address = NULL;
    }
    free(tnap_id);
}

cJSON *tnap_id_convertToJSON(tnap_id_t *tnap_id) {
    cJSON *item = cJSON_CreateObject();

    // tnap_id->ss_id
    if(tnap_id->ss_id) {
    if(cJSON_AddStringToObject(item, "ssId", tnap_id->ss_id) == NULL) {
    goto fail; //String
    }
    }


    // tnap_id->bss_id
    if(tnap_id->bss_id) {
    if(cJSON_AddStringToObject(item, "bssId", tnap_id->bss_id) == NULL) {
    goto fail; //String
    }
    }


    // tnap_id->civic_address
    if(tnap_id->civic_address) {
    if(cJSON_AddStringToObject(item, "civicAddress", tnap_id->civic_address) == NULL) {
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

tnap_id_t *tnap_id_parseFromJSON(cJSON *tnap_idJSON){

    tnap_id_t *tnap_id_local_var = NULL;

    char *ss_id_local_str = NULL;

    char *bss_id_local_str = NULL;

    char *civic_address_local_str = NULL;

    // tnap_id->ss_id
    cJSON *ss_id = cJSON_GetObjectItemCaseSensitive(tnap_idJSON, "ssId");
    if (cJSON_IsNull(ss_id)) {
        ss_id = NULL;
    }
    if (ss_id) { 
    if(!cJSON_IsString(ss_id) && !cJSON_IsNull(ss_id))
    {
    goto end; //String
    }
    }

    // tnap_id->bss_id
    cJSON *bss_id = cJSON_GetObjectItemCaseSensitive(tnap_idJSON, "bssId");
    if (cJSON_IsNull(bss_id)) {
        bss_id = NULL;
    }
    if (bss_id) { 
    if(!cJSON_IsString(bss_id) && !cJSON_IsNull(bss_id))
    {
    goto end; //String
    }
    }

    // tnap_id->civic_address
    cJSON *civic_address = cJSON_GetObjectItemCaseSensitive(tnap_idJSON, "civicAddress");
    if (cJSON_IsNull(civic_address)) {
        civic_address = NULL;
    }
    if (civic_address) { 
    if(!cJSON_IsString(civic_address))
    {
    goto end; //ByteArray
    }
    }


    if (ss_id && !cJSON_IsNull(ss_id)) ss_id_local_str = strdup(ss_id->valuestring);
    if (bss_id && !cJSON_IsNull(bss_id)) bss_id_local_str = strdup(bss_id->valuestring);
    if (civic_address) civic_address_local_str = strdup(civic_address->valuestring);

    tnap_id_local_var = tnap_id_create_internal (
        ss_id_local_str,
        bss_id_local_str,
        civic_address_local_str
        );

    if (!tnap_id_local_var) {
        goto end;
    }

    return tnap_id_local_var;
end:
    if (ss_id_local_str) {
        free(ss_id_local_str);
        ss_id_local_str = NULL;
    }
    if (bss_id_local_str) {
        free(bss_id_local_str);
        bss_id_local_str = NULL;
    }
    if (civic_address_local_str) {
        free(civic_address_local_str);
        civic_address_local_str = NULL;
    }
    return NULL;

}
