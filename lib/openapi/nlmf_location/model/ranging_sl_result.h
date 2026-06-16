/*
 * ranging_sl_result.h
 *
 * Specifies the type of result requested for ranging and sidelink positioning.
 */

#ifndef _ranging_sl_result_H_
#define _ranging_sl_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct ranging_sl_result_t ranging_sl_result_t;




typedef struct ranging_sl_result_t {

    int _library_owned; // Is the library responsible for freeing this object?
} ranging_sl_result_t;

__attribute__((deprecated)) ranging_sl_result_t *ranging_sl_result_create(
);

void ranging_sl_result_free(ranging_sl_result_t *ranging_sl_result);

ranging_sl_result_t *ranging_sl_result_parseFromJSON(cJSON *ranging_sl_resultJSON);

cJSON *ranging_sl_result_convertToJSON(ranging_sl_result_t *ranging_sl_result);

#endif /* _ranging_sl_result_H_ */

