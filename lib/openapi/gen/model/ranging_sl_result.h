/*
 * ranging_sl_result.h
 *
 * Specifies the type of result requested for ranging and sidelink positioning.
 */

#ifndef _OpenAPI_ranging_sl_result_H_
#define _OpenAPI_ranging_sl_result_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct OpenAPI_ranging_sl_result_s OpenAPI_ranging_sl_result_t;
typedef struct OpenAPI_ranging_sl_result_s {
} OpenAPI_ranging_sl_result_t;

OpenAPI_ranging_sl_result_t *OpenAPI_ranging_sl_result_create(
);
void OpenAPI_ranging_sl_result_free(OpenAPI_ranging_sl_result_t *ranging_sl_result);
OpenAPI_ranging_sl_result_t *OpenAPI_ranging_sl_result_parseFromJSON(cJSON *ranging_sl_resultJSON);
cJSON *OpenAPI_ranging_sl_result_convertToJSON(OpenAPI_ranging_sl_result_t *ranging_sl_result);
OpenAPI_ranging_sl_result_t *OpenAPI_ranging_sl_result_copy(OpenAPI_ranging_sl_result_t *dst, OpenAPI_ranging_sl_result_t *src);

#ifdef __cplusplus
}
#endif

#endif /* _OpenAPI_ranging_sl_result_H_ */

