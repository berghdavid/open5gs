#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_loc_rep_addr_af.h"



static up_loc_rep_addr_af_t *up_loc_rep_addr_af_create_internal(
    list_t *ipv4_addrs,
    list_t *ipv6_addrs,
    char *fqdn
    ) {
    up_loc_rep_addr_af_t *up_loc_rep_addr_af_local_var = malloc(sizeof(up_loc_rep_addr_af_t));
    if (!up_loc_rep_addr_af_local_var) {
        return NULL;
    }
    memset(up_loc_rep_addr_af_local_var, 0, sizeof(up_loc_rep_addr_af_t));
    up_loc_rep_addr_af_local_var->_library_owned = 1;
    up_loc_rep_addr_af_local_var->ipv4_addrs = ipv4_addrs;
    up_loc_rep_addr_af_local_var->ipv6_addrs = ipv6_addrs;
    up_loc_rep_addr_af_local_var->fqdn = fqdn;
    return up_loc_rep_addr_af_local_var;
}

__attribute__((deprecated)) up_loc_rep_addr_af_t *up_loc_rep_addr_af_create(
    list_t *ipv4_addrs,
    list_t *ipv6_addrs,
    char *fqdn
    ) {
    up_loc_rep_addr_af_t *result = up_loc_rep_addr_af_create_internal (
        ipv4_addrs,
        ipv6_addrs,
        fqdn
        );
    if (!result) {
    }
    return result;
}

void up_loc_rep_addr_af_free(up_loc_rep_addr_af_t *up_loc_rep_addr_af) {
    if(NULL == up_loc_rep_addr_af){
        return ;
    }
    if(up_loc_rep_addr_af->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "up_loc_rep_addr_af_free");
        return ;
    }
    listEntry_t *listEntry;
    if (up_loc_rep_addr_af->ipv4_addrs) {
        list_ForEach(listEntry, up_loc_rep_addr_af->ipv4_addrs) {
            free(listEntry->data);
        }
        list_freeList(up_loc_rep_addr_af->ipv4_addrs);
        up_loc_rep_addr_af->ipv4_addrs = NULL;
    }
    if (up_loc_rep_addr_af->ipv6_addrs) {
        list_ForEach(listEntry, up_loc_rep_addr_af->ipv6_addrs) {
            ipv6_addr_free(listEntry->data);
        }
        list_freeList(up_loc_rep_addr_af->ipv6_addrs);
        up_loc_rep_addr_af->ipv6_addrs = NULL;
    }
    if (up_loc_rep_addr_af->fqdn) {
        free(up_loc_rep_addr_af->fqdn);
        up_loc_rep_addr_af->fqdn = NULL;
    }
    free(up_loc_rep_addr_af);
}

cJSON *up_loc_rep_addr_af_convertToJSON(up_loc_rep_addr_af_t *up_loc_rep_addr_af) {
    cJSON *item = cJSON_CreateObject();

    // up_loc_rep_addr_af->ipv4_addrs
    if(up_loc_rep_addr_af->ipv4_addrs) {
    cJSON *ipv4_addrs = cJSON_AddArrayToObject(item, "ipv4Addrs");
    if(ipv4_addrs == NULL) {
        goto fail; //primitive container
    }

    listEntry_t *ipv4_addrsListEntry;
    list_ForEach(ipv4_addrsListEntry, up_loc_rep_addr_af->ipv4_addrs) {
    if(cJSON_AddStringToObject(ipv4_addrs, "", ipv4_addrsListEntry->data) == NULL)
    {
        goto fail;
    }
    }
    }


    // up_loc_rep_addr_af->ipv6_addrs
    if(up_loc_rep_addr_af->ipv6_addrs) {
    cJSON *ipv6_addrs = cJSON_AddArrayToObject(item, "ipv6Addrs");
    if(ipv6_addrs == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *ipv6_addrsListEntry;
    if (up_loc_rep_addr_af->ipv6_addrs) {
    list_ForEach(ipv6_addrsListEntry, up_loc_rep_addr_af->ipv6_addrs) {
    cJSON *itemLocal = ipv6_addr_convertToJSON(ipv6_addrsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(ipv6_addrs, itemLocal);
    }
    }
    }


    // up_loc_rep_addr_af->fqdn
    if(up_loc_rep_addr_af->fqdn) {
    if(cJSON_AddStringToObject(item, "fqdn", up_loc_rep_addr_af->fqdn) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

up_loc_rep_addr_af_t *up_loc_rep_addr_af_parseFromJSON(cJSON *up_loc_rep_addr_afJSON){

    up_loc_rep_addr_af_t *up_loc_rep_addr_af_local_var = NULL;

    // define the local list for up_loc_rep_addr_af->ipv4_addrs
    list_t *ipv4_addrsList = NULL;

    // define the local list for up_loc_rep_addr_af->ipv6_addrs
    list_t *ipv6_addrsList = NULL;

    char *fqdn_local_str = NULL;

    // up_loc_rep_addr_af->ipv4_addrs
    cJSON *ipv4_addrs = cJSON_GetObjectItemCaseSensitive(up_loc_rep_addr_afJSON, "ipv4Addrs");
    if (cJSON_IsNull(ipv4_addrs)) {
        ipv4_addrs = NULL;
    }
    if (ipv4_addrs) { 
    cJSON *ipv4_addrs_local = NULL;
    if(!cJSON_IsArray(ipv4_addrs)) {
        goto end;//primitive container
    }
    ipv4_addrsList = list_createList();

    cJSON_ArrayForEach(ipv4_addrs_local, ipv4_addrs)
    {
        if(!cJSON_IsString(ipv4_addrs_local))
        {
            goto end;
        }
        list_addElement(ipv4_addrsList , strdup(ipv4_addrs_local->valuestring));
    }
    }

    // up_loc_rep_addr_af->ipv6_addrs
    cJSON *ipv6_addrs = cJSON_GetObjectItemCaseSensitive(up_loc_rep_addr_afJSON, "ipv6Addrs");
    if (cJSON_IsNull(ipv6_addrs)) {
        ipv6_addrs = NULL;
    }
    if (ipv6_addrs) { 
    cJSON *ipv6_addrs_local_nonprimitive = NULL;
    if(!cJSON_IsArray(ipv6_addrs)){
        goto end; //nonprimitive container
    }

    ipv6_addrsList = list_createList();

    cJSON_ArrayForEach(ipv6_addrs_local_nonprimitive,ipv6_addrs )
    {
        if(!cJSON_IsObject(ipv6_addrs_local_nonprimitive)){
            goto end;
        }
        ipv6_addr_t *ipv6_addrsItem = ipv6_addr_parseFromJSON(ipv6_addrs_local_nonprimitive);

        list_addElement(ipv6_addrsList, ipv6_addrsItem);
    }
    }

    // up_loc_rep_addr_af->fqdn
    cJSON *fqdn = cJSON_GetObjectItemCaseSensitive(up_loc_rep_addr_afJSON, "fqdn");
    if (cJSON_IsNull(fqdn)) {
        fqdn = NULL;
    }
    if (fqdn) { 
    if(!cJSON_IsString(fqdn) && !cJSON_IsNull(fqdn))
    {
    goto end; //String
    }
    }


    if (fqdn && !cJSON_IsNull(fqdn)) fqdn_local_str = strdup(fqdn->valuestring);

    up_loc_rep_addr_af_local_var = up_loc_rep_addr_af_create_internal (
        ipv4_addrs ? ipv4_addrsList : NULL,
        ipv6_addrs ? ipv6_addrsList : NULL,
        fqdn_local_str
        );

    if (!up_loc_rep_addr_af_local_var) {
        goto end;
    }

    return up_loc_rep_addr_af_local_var;
end:
    if (ipv4_addrsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ipv4_addrsList) {
            free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ipv4_addrsList);
        ipv4_addrsList = NULL;
    }
    if (ipv6_addrsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, ipv6_addrsList) {
            ipv6_addr_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(ipv6_addrsList);
        ipv6_addrsList = NULL;
    }
    if (fqdn_local_str) {
        free(fqdn_local_str);
        fqdn_local_str = NULL;
    }
    return NULL;

}
