
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ranging_sl_result.h"

OpenAPI_ranging_sl_result_t *OpenAPI_ranging_sl_result_create(
)
{
    OpenAPI_ranging_sl_result_t *ranging_sl_result_local_var = ogs_malloc(sizeof(OpenAPI_ranging_sl_result_t));
    ogs_assert(ranging_sl_result_local_var);


    return ranging_sl_result_local_var;
}

void OpenAPI_ranging_sl_result_free(OpenAPI_ranging_sl_result_t *ranging_sl_result)
{
    if (NULL == ranging_sl_result) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(ranging_sl_result);
}

cJSON *OpenAPI_ranging_sl_result_convertToJSON(OpenAPI_ranging_sl_result_t *ranging_sl_result)
{
    cJSON *item = NULL;

    if (ranging_sl_result == NULL) {
        ogs_error("OpenAPI_ranging_sl_result_convertToJSON() failed [RangingSlResult]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_ranging_sl_result_t *OpenAPI_ranging_sl_result_parseFromJSON(cJSON *ranging_sl_resultJSON)
{
    OpenAPI_ranging_sl_result_t *ranging_sl_result_local_var = NULL;
    ranging_sl_result_local_var = OpenAPI_ranging_sl_result_create (
    );

    return ranging_sl_result_local_var;
end:
    return NULL;
}

OpenAPI_ranging_sl_result_t *OpenAPI_ranging_sl_result_copy(OpenAPI_ranging_sl_result_t *dst, OpenAPI_ranging_sl_result_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_ranging_sl_result_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_ranging_sl_result_convertToJSON() failed");
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

    OpenAPI_ranging_sl_result_free(dst);
    dst = OpenAPI_ranging_sl_result_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

