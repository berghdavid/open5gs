/*
 * ipv6_addr.h
 *
 * String identifying an IPv6 address formatted according to clause 4 of RFC5952. The mixed IPv4 IPv6 notation according to clause 5 of RFC5952 shall not be used. 
 */

#ifndef _ipv6_addr_H_
#define _ipv6_addr_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ipv6_addr_t ipv6_addr_t;




typedef struct ipv6_addr_t {

    int _library_owned; // Is the library responsible for freeing this object?
} ipv6_addr_t;

__attribute__((deprecated)) ipv6_addr_t *ipv6_addr_create(
);

void ipv6_addr_free(ipv6_addr_t *ipv6_addr);

ipv6_addr_t *ipv6_addr_parseFromJSON(cJSON *ipv6_addrJSON);

cJSON *ipv6_addr_convertToJSON(ipv6_addr_t *ipv6_addr);

#endif /* _ipv6_addr_H_ */

