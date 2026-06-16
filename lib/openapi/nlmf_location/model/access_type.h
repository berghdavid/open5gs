/*
 * access_type.h
 *
 * Indicates whether the access is  via 3GPP or via non-3GPP.
 */

#ifndef _access_type_H_
#define _access_type_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct access_type_t access_type_t;


// Enum  for access_type

typedef enum { lmf_location_access_type__NULL = 0, lmf_location_access_type___3GPP_ACCESS, lmf_location_access_type__NON_3GPP_ACCESS } lmf_location_access_type__e;

char* access_type_access_type_ToString(lmf_location_access_type__e access_type);

lmf_location_access_type__e access_type_access_type_FromString(char* access_type);

cJSON *access_type_convertToJSON(lmf_location_access_type__e access_type);

lmf_location_access_type__e access_type_parseFromJSON(cJSON *access_typeJSON);

#endif /* _access_type_H_ */

