/*
 * cancel_loc_data.h
 *
 * Information within Cancel Location Request.
 */

#ifndef _cancel_loc_data_H_
#define _cancel_loc_data_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct cancel_loc_data_t cancel_loc_data_t;




typedef struct cancel_loc_data_t {
    char *hgmlc_call_back_uri; // string
    char *ldr_reference; // string
    char *lcs_correlation_id; // string
    char *supported_features; // string

    int _library_owned; // Is the library responsible for freeing this object?
} cancel_loc_data_t;

__attribute__((deprecated)) cancel_loc_data_t *cancel_loc_data_create(
    char *hgmlc_call_back_uri,
    char *ldr_reference,
    char *lcs_correlation_id,
    char *supported_features
);

void cancel_loc_data_free(cancel_loc_data_t *cancel_loc_data);

cancel_loc_data_t *cancel_loc_data_parseFromJSON(cJSON *cancel_loc_dataJSON);

cJSON *cancel_loc_data_convertToJSON(cancel_loc_data_t *cancel_loc_data);

#endif /* _cancel_loc_data_H_ */

