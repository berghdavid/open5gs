
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ipv6_addr.h"

OpenAPI_ipv6_addr_t *OpenAPI_ipv6_addr_create(
)
{
    OpenAPI_ipv6_addr_t *ipv6_addr_local_var = ogs_malloc(sizeof(OpenAPI_ipv6_addr_t));
    ogs_assert(ipv6_addr_local_var);


    return ipv6_addr_local_var;
}

void OpenAPI_ipv6_addr_free(OpenAPI_ipv6_addr_t *ipv6_addr)
{
    if (NULL == ipv6_addr) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(ipv6_addr);
}

cJSON *OpenAPI_ipv6_addr_convertToJSON(OpenAPI_ipv6_addr_t *ipv6_addr)
{
    cJSON *item = NULL;

    if (ipv6_addr == NULL) {
        ogs_error("OpenAPI_ipv6_addr_convertToJSON() failed [Ipv6Addr]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_ipv6_addr_t *OpenAPI_ipv6_addr_parseFromJSON(cJSON *ipv6_addrJSON)
{
    OpenAPI_ipv6_addr_t *ipv6_addr_local_var = NULL;
    ipv6_addr_local_var = OpenAPI_ipv6_addr_create (
    );

    return ipv6_addr_local_var;
end:
    return NULL;
}

OpenAPI_ipv6_addr_t *OpenAPI_ipv6_addr_copy(OpenAPI_ipv6_addr_t *dst, OpenAPI_ipv6_addr_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_ipv6_addr_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_ipv6_addr_convertToJSON() failed");
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

    OpenAPI_ipv6_addr_free(dst);
    dst = OpenAPI_ipv6_addr_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

