/*
 * lcs_broadcast_assistance_types_data.h
 *
 * LCS Broadcast Assistance Data Types
 */

#ifndef _lcs_broadcast_assistance_types_data_H_
#define _lcs_broadcast_assistance_types_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lcs_broadcast_assistance_types_data_t lcs_broadcast_assistance_types_data_t;




typedef struct lcs_broadcast_assistance_types_data_t {
    char *location_assistance_type; //ByteArray

    int _library_owned; // Is the library responsible for freeing this object?
} lcs_broadcast_assistance_types_data_t;

__attribute__((deprecated)) lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data_create(
    char *location_assistance_type
);

void lcs_broadcast_assistance_types_data_free(lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data);

lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data_parseFromJSON(cJSON *lcs_broadcast_assistance_types_dataJSON);

cJSON *lcs_broadcast_assistance_types_data_convertToJSON(lcs_broadcast_assistance_types_data_t *lcs_broadcast_assistance_types_data);

#endif /* _lcs_broadcast_assistance_types_data_H_ */

