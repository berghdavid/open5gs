#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv6_addr.h"



static ipv6_addr_t *ipv6_addr_create_internal(
    ) {
    ipv6_addr_t *ipv6_addr_local_var = malloc(sizeof(ipv6_addr_t));
    if (!ipv6_addr_local_var) {
        return NULL;
    }
    memset(ipv6_addr_local_var, 0, sizeof(ipv6_addr_t));
    ipv6_addr_local_var->_library_owned = 1;
    return ipv6_addr_local_var;
}

__attribute__((deprecated)) ipv6_addr_t *ipv6_addr_create(
    ) {
    ipv6_addr_t *result = ipv6_addr_create_internal (
        );
    if (!result) {
    }
    return result;
}

void ipv6_addr_free(ipv6_addr_t *ipv6_addr) {
    if(NULL == ipv6_addr){
        return ;
    }
    if(ipv6_addr->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "ipv6_addr_free");
        return ;
    }
    listEntry_t *listEntry;
    free(ipv6_addr);
}

cJSON *ipv6_addr_convertToJSON(ipv6_addr_t *ipv6_addr) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

ipv6_addr_t *ipv6_addr_parseFromJSON(cJSON *ipv6_addrJSON){

    ipv6_addr_t *ipv6_addr_local_var = NULL;



    ipv6_addr_local_var = ipv6_addr_create_internal (
        );

    if (!ipv6_addr_local_var) {
        goto end;
    }

    return ipv6_addr_local_var;
end:
    return NULL;

}
