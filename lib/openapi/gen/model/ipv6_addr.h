/*
 * ipv6_addr.h
 *
 * String identifying an IPv6 address formatted according to clause 4 of RFC5952. The mixed IPv4 IPv6 notation according to clause 5 of RFC5952 shall not be used. 
 */

#ifndef _OpenAPI_ipv6_addr_H_
#define _OpenAPI_ipv6_addr_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_ipv6_addr_s OpenAPI_ipv6_addr_t;
typedef struct OpenAPI_ipv6_addr_s {
} OpenAPI_ipv6_addr_t;

OpenAPI_ipv6_addr_t *OpenAPI_ipv6_addr_create(
);
void OpenAPI_ipv6_addr_free(OpenAPI_ipv6_addr_t *ipv6_addr);
OpenAPI_ipv6_addr_t *OpenAPI_ipv6_addr_parseFromJSON(cJSON *ipv6_addrJSON);
cJSON *OpenAPI_ipv6_addr_convertToJSON(OpenAPI_ipv6_addr_t *ipv6_addr);
OpenAPI_ipv6_addr_t *OpenAPI_ipv6_addr_copy(OpenAPI_ipv6_addr_t *dst, OpenAPI_ipv6_addr_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_ipv6_addr_H_ */

