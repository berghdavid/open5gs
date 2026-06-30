
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "event_report_mode.h"

OpenAPI_event_report_mode_t *OpenAPI_event_report_mode_create(
)
{
    OpenAPI_event_report_mode_t *event_report_mode_local_var = ogs_malloc(sizeof(OpenAPI_event_report_mode_t));
    log_assert(event_report_mode_local_var);


    return event_report_mode_local_var;
}

void OpenAPI_event_report_mode_free(OpenAPI_event_report_mode_t *event_report_mode)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == event_report_mode) {
        return;
    }
    ogs_free(event_report_mode);
}

cJSON *OpenAPI_event_report_mode_convertToJSON(OpenAPI_event_report_mode_t *event_report_mode)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (event_report_mode == NULL) {
        log_error("OpenAPI_event_report_mode_convertToJSON() failed [EventReportMode]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_event_report_mode_t *OpenAPI_event_report_mode_parseFromJSON(cJSON *event_report_modeJSON)
{
    OpenAPI_event_report_mode_t *event_report_mode_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    event_report_mode_local_var = OpenAPI_event_report_mode_create (
    );

    return event_report_mode_local_var;
end:
    return NULL;
}

OpenAPI_event_report_mode_t *OpenAPI_event_report_mode_copy(OpenAPI_event_report_mode_t *dst, OpenAPI_event_report_mode_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_event_report_mode_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_event_report_mode_convertToJSON() failed");
        return NULL;
    }

    content = cJSON_Print(item);
    cJSON_Delete(item);

    if (!content) {
        log_error("cJSON_Print() failed");
        return NULL;
    }

    item = cJSON_Parse(content);
    ogs_free(content);
    if (!item) {
        log_error("cJSON_Parse() failed");
        return NULL;
    }

    OpenAPI_event_report_mode_free(dst);
    dst = OpenAPI_event_report_mode_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

