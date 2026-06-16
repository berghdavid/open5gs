#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "twap_id.h"



static twap_id_t *twap_id_create_internal(
    char *ss_id,
    char *bss_id,
    char *civic_address
    ) {
    twap_id_t *twap_id_local_var = malloc(sizeof(twap_id_t));
    if (!twap_id_local_var) {
        return NULL;
    }
    memset(twap_id_local_var, 0, sizeof(twap_id_t));
    twap_id_local_var->_library_owned = 1;
    twap_id_local_var->ss_id = ss_id;
    twap_id_local_var->bss_id = bss_id;
    twap_id_local_var->civic_address = civic_address;
    return twap_id_local_var;
}

__attribute__((deprecated)) twap_id_t *twap_id_create(
    char *ss_id,
    char *bss_id,
    char *civic_address
    ) {
    twap_id_t *result = twap_id_create_internal (
        ss_id,
        bss_id,
        civic_address
        );
    if (!result) {
    }
    return result;
}

void twap_id_free(twap_id_t *twap_id) {
    if(NULL == twap_id){
        return ;
    }
    if(twap_id->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "twap_id_free");
        return ;
    }
    listEntry_t *listEntry;
    if (twap_id->ss_id) {
        free(twap_id->ss_id);
        twap_id->ss_id = NULL;
    }
    if (twap_id->bss_id) {
        free(twap_id->bss_id);
        twap_id->bss_id = NULL;
    }
    if (twap_id->civic_address) {
        free(twap_id->civic_address);
        twap_id->civic_address = NULL;
    }
    free(twap_id);
}

cJSON *twap_id_convertToJSON(twap_id_t *twap_id) {
    cJSON *item = cJSON_CreateObject();

    // twap_id->ss_id
    if (!twap_id->ss_id) {
        goto fail;
    }
    if(cJSON_AddStringToObject(item, "ssId", twap_id->ss_id) == NULL) {
    goto fail; //String
    }


    // twap_id->bss_id
    if(twap_id->bss_id) {
    if(cJSON_AddStringToObject(item, "bssId", twap_id->bss_id) == NULL) {
    goto fail; //String
    }
    }


    // twap_id->civic_address
    if(twap_id->civic_address) {
    if(cJSON_AddStringToObject(item, "civicAddress", twap_id->civic_address) == NULL) {
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

twap_id_t *twap_id_parseFromJSON(cJSON *twap_idJSON){

    twap_id_t *twap_id_local_var = NULL;

    char *ss_id_local_str = NULL;

    char *bss_id_local_str = NULL;

    char *civic_address_local_str = NULL;

    // twap_id->ss_id
    cJSON *ss_id = cJSON_GetObjectItemCaseSensitive(twap_idJSON, "ssId");
    if (cJSON_IsNull(ss_id)) {
        ss_id = NULL;
    }
    if (!ss_id) {
        goto end;
    }

    
    if(!cJSON_IsString(ss_id))
    {
    goto end; //String
    }

    // twap_id->bss_id
    cJSON *bss_id = cJSON_GetObjectItemCaseSensitive(twap_idJSON, "bssId");
    if (cJSON_IsNull(bss_id)) {
        bss_id = NULL;
    }
    if (bss_id) { 
    if(!cJSON_IsString(bss_id) && !cJSON_IsNull(bss_id))
    {
    goto end; //String
    }
    }

    // twap_id->civic_address
    cJSON *civic_address = cJSON_GetObjectItemCaseSensitive(twap_idJSON, "civicAddress");
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

    twap_id_local_var = twap_id_create_internal (
        ss_id_local_str,
        bss_id_local_str,
        civic_address_local_str
        );

    if (!twap_id_local_var) {
        goto end;
    }

    return twap_id_local_var;
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
