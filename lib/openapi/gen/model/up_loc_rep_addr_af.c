
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "up_loc_rep_addr_af.h"

OpenAPI_up_loc_rep_addr_af_t *OpenAPI_up_loc_rep_addr_af_create(
    OpenAPI_list_t *ipv4_addrs,
    OpenAPI_list_t *ipv6_addrs,
    char *fqdn
)
{
    OpenAPI_up_loc_rep_addr_af_t *up_loc_rep_addr_af_local_var = ogs_malloc(sizeof(OpenAPI_up_loc_rep_addr_af_t));
    ogs_assert(up_loc_rep_addr_af_local_var);

    up_loc_rep_addr_af_local_var->ipv4_addrs = ipv4_addrs;
    up_loc_rep_addr_af_local_var->ipv6_addrs = ipv6_addrs;
    up_loc_rep_addr_af_local_var->fqdn = fqdn;

    return up_loc_rep_addr_af_local_var;
}

void OpenAPI_up_loc_rep_addr_af_free(OpenAPI_up_loc_rep_addr_af_t *up_loc_rep_addr_af)
{
    if (NULL == up_loc_rep_addr_af) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_list_for_each(up_loc_rep_addr_af->ipv4_addrs, node) {
        ogs_free(node->data);
    }
    OpenAPI_list_free(up_loc_rep_addr_af->ipv4_addrs);
    OpenAPI_list_for_each(up_loc_rep_addr_af->ipv6_addrs, node) {
        OpenAPI_ipv6_addr_free(node->data);
    }
    OpenAPI_list_free(up_loc_rep_addr_af->ipv6_addrs);
    ogs_free(up_loc_rep_addr_af->fqdn);
    ogs_free(up_loc_rep_addr_af);
}

cJSON *OpenAPI_up_loc_rep_addr_af_convertToJSON(OpenAPI_up_loc_rep_addr_af_t *up_loc_rep_addr_af)
{
    cJSON *item = NULL;

    if (up_loc_rep_addr_af == NULL) {
        ogs_error("OpenAPI_up_loc_rep_addr_af_convertToJSON() failed [UpLocRepAddrAf]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (up_loc_rep_addr_af->ipv4_addrs) {
    cJSON *ipv4_addrs = cJSON_AddArrayToObject(item, "ipv4Addrs");
    if (ipv4_addrs == NULL) {
        ogs_error("OpenAPI_up_loc_rep_addr_af_convertToJSON() failed [ipv4_addrs]");
        goto end;
    }

    OpenAPI_lnode_t *ipv4_addrs_node;
    OpenAPI_list_for_each(up_loc_rep_addr_af->ipv4_addrs, ipv4_addrs_node)  {
    if (cJSON_AddStringToObject(ipv4_addrs, "", (char*)ipv4_addrs_node->data) == NULL) {
        ogs_error("OpenAPI_up_loc_rep_addr_af_convertToJSON() failed [ipv4_addrs]");
        goto end;
    }
                    }
    }

    if (up_loc_rep_addr_af->ipv6_addrs) {
    cJSON *ipv6_addrsList = cJSON_AddArrayToObject(item, "ipv6Addrs");
    if (ipv6_addrsList == NULL) {
        ogs_error("OpenAPI_up_loc_rep_addr_af_convertToJSON() failed [ipv6_addrs]");
        goto end;
    }

    OpenAPI_lnode_t *ipv6_addrs_node;
    if (up_loc_rep_addr_af->ipv6_addrs) {
        OpenAPI_list_for_each(up_loc_rep_addr_af->ipv6_addrs, ipv6_addrs_node) {
            cJSON *itemLocal = OpenAPI_ipv6_addr_convertToJSON(ipv6_addrs_node->data);
            if (itemLocal == NULL) {
                ogs_error("OpenAPI_up_loc_rep_addr_af_convertToJSON() failed [ipv6_addrs]");
                goto end;
            }
            cJSON_AddItemToArray(ipv6_addrsList, itemLocal);
        }
    }
    }

    if (up_loc_rep_addr_af->fqdn) {
    if (cJSON_AddStringToObject(item, "fqdn", up_loc_rep_addr_af->fqdn) == NULL) {
        ogs_error("OpenAPI_up_loc_rep_addr_af_convertToJSON() failed [fqdn]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_up_loc_rep_addr_af_t *OpenAPI_up_loc_rep_addr_af_parseFromJSON(cJSON *up_loc_rep_addr_afJSON)
{
    OpenAPI_up_loc_rep_addr_af_t *up_loc_rep_addr_af_local_var = NULL;
    cJSON *ipv4_addrs = cJSON_GetObjectItemCaseSensitive(up_loc_rep_addr_afJSON, "ipv4Addrs");

    OpenAPI_list_t *ipv4_addrsList;
    if (ipv4_addrs) {
    cJSON *ipv4_addrs_local;
    if (!cJSON_IsArray(ipv4_addrs)) {
        ogs_error("OpenAPI_up_loc_rep_addr_af_parseFromJSON() failed [ipv4_addrs]");
        goto end;
    }
    ipv4_addrsList = OpenAPI_list_create();

    cJSON_ArrayForEach(ipv4_addrs_local, ipv4_addrs) {
    if (!cJSON_IsString(ipv4_addrs_local)) {
        ogs_error("OpenAPI_up_loc_rep_addr_af_parseFromJSON() failed [ipv4_addrs]");
        goto end;
    }
    OpenAPI_list_add(ipv4_addrsList, ogs_strdup(ipv4_addrs_local->valuestring));
    }
    }

    cJSON *ipv6_addrs = cJSON_GetObjectItemCaseSensitive(up_loc_rep_addr_afJSON, "ipv6Addrs");

    OpenAPI_list_t *ipv6_addrsList;
    if (ipv6_addrs) {
    cJSON *ipv6_addrs_local_nonprimitive;
    if (!cJSON_IsArray(ipv6_addrs)){
        ogs_error("OpenAPI_up_loc_rep_addr_af_parseFromJSON() failed [ipv6_addrs]");
        goto end;
    }

    ipv6_addrsList = OpenAPI_list_create();

    cJSON_ArrayForEach(ipv6_addrs_local_nonprimitive, ipv6_addrs ) {
        if (!cJSON_IsObject(ipv6_addrs_local_nonprimitive)) {
            ogs_error("OpenAPI_up_loc_rep_addr_af_parseFromJSON() failed [ipv6_addrs]");
            goto end;
        }
        OpenAPI_ipv6_addr_t *ipv6_addrsItem = OpenAPI_ipv6_addr_parseFromJSON(ipv6_addrs_local_nonprimitive);

        if (!ipv6_addrsItem) {
            ogs_error("No ipv6_addrsItem");
            OpenAPI_list_free(ipv6_addrsList);
            goto end;
        }

        OpenAPI_list_add(ipv6_addrsList, ipv6_addrsItem);
    }
    }

    cJSON *fqdn = cJSON_GetObjectItemCaseSensitive(up_loc_rep_addr_afJSON, "fqdn");

    if (fqdn) {
    if (!cJSON_IsString(fqdn)) {
        ogs_error("OpenAPI_up_loc_rep_addr_af_parseFromJSON() failed [fqdn]");
        goto end;
    }
    }

    up_loc_rep_addr_af_local_var = OpenAPI_up_loc_rep_addr_af_create (
        ipv4_addrs ? ipv4_addrsList : NULL,
        ipv6_addrs ? ipv6_addrsList : NULL,
        fqdn ? ogs_strdup(fqdn->valuestring) : NULL
    );

    return up_loc_rep_addr_af_local_var;
end:
    return NULL;
}

OpenAPI_up_loc_rep_addr_af_t *OpenAPI_up_loc_rep_addr_af_copy(OpenAPI_up_loc_rep_addr_af_t *dst, OpenAPI_up_loc_rep_addr_af_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_up_loc_rep_addr_af_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_up_loc_rep_addr_af_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        ogs_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        ogs_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_up_loc_rep_addr_af_free(dst);
    dst = OpenAPI_up_loc_rep_addr_af_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

