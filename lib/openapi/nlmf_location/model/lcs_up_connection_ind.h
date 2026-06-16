/*
 * lcs_up_connection_ind.h
 *
 * LCS UP Connection Indication.
 */

#ifndef _lcs_up_connection_ind_H_
#define _lcs_up_connection_ind_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct lcs_up_connection_ind_t lcs_up_connection_ind_t;




typedef struct lcs_up_connection_ind_t {

    int _library_owned; // Is the library responsible for freeing this object?
} lcs_up_connection_ind_t;

__attribute__((deprecated)) lcs_up_connection_ind_t *lcs_up_connection_ind_create(
);

void lcs_up_connection_ind_free(lcs_up_connection_ind_t *lcs_up_connection_ind);

lcs_up_connection_ind_t *lcs_up_connection_ind_parseFromJSON(cJSON *lcs_up_connection_indJSON);

cJSON *lcs_up_connection_ind_convertToJSON(lcs_up_connection_ind_t *lcs_up_connection_ind);

#endif /* _lcs_up_connection_ind_H_ */

