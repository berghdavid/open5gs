/*
 * ciphering_data_set.h
 *
 * Represents a Ciphering Data Set.
 */

#ifndef _OpenAPI_ciphering_data_set_H_
#define _OpenAPI_ciphering_data_set_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_ciphering_data_set_s OpenAPI_ciphering_data_set_t;
typedef struct OpenAPI_ciphering_data_set_s {
    int ciphering_set_id;
    char ciphering_key;
    char c0;
    char lte_pos_sib_types;
    char nr_pos_sib_types;
    char *validity_start_time;
    int validity_duration;
    char tai_list;
} OpenAPI_ciphering_data_set_t;

OpenAPI_ciphering_data_set_t *OpenAPI_ciphering_data_set_create(
    int ciphering_set_id,
    char ciphering_key,
    char c0,
    char lte_pos_sib_types,
    char nr_pos_sib_types,
    char *validity_start_time,
    int validity_duration,
    char tai_list
);
void OpenAPI_ciphering_data_set_free(OpenAPI_ciphering_data_set_t *ciphering_data_set);
OpenAPI_ciphering_data_set_t *OpenAPI_ciphering_data_set_parseFromJSON(cJSON *ciphering_data_setJSON);
cJSON *OpenAPI_ciphering_data_set_convertToJSON(OpenAPI_ciphering_data_set_t *ciphering_data_set);
OpenAPI_ciphering_data_set_t *OpenAPI_ciphering_data_set_copy(OpenAPI_ciphering_data_set_t *dst, OpenAPI_ciphering_data_set_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_ciphering_data_set_H_ */

