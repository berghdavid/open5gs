
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data_source_type.h"

OpenAPI_data_source_type_t *OpenAPI_data_source_type_create(
)
{
    OpenAPI_data_source_type_t *data_source_type_local_var = ogs_malloc(sizeof(OpenAPI_data_source_type_t));
    ogs_assert(data_source_type_local_var);


    return data_source_type_local_var;
}

void OpenAPI_data_source_type_free(OpenAPI_data_source_type_t *data_source_type)
{
    if (NULL == data_source_type) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(data_source_type);
}

cJSON *OpenAPI_data_source_type_convertToJSON(OpenAPI_data_source_type_t *data_source_type)
{
    cJSON *item = NULL;

    if (data_source_type == NULL) {
        ogs_error("OpenAPI_data_source_type_convertToJSON() failed [DataSourceType]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_data_source_type_t *OpenAPI_data_source_type_parseFromJSON(cJSON *data_source_typeJSON)
{
    OpenAPI_data_source_type_t *data_source_type_local_var = NULL;
    data_source_type_local_var = OpenAPI_data_source_type_create (
    );

    return data_source_type_local_var;
end:
    return NULL;
}

OpenAPI_data_source_type_t *OpenAPI_data_source_type_copy(OpenAPI_data_source_type_t *dst, OpenAPI_data_source_type_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_data_source_type_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_data_source_type_convertToJSON() failed");
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

    OpenAPI_data_source_type_free(dst);
    dst = OpenAPI_data_source_type_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

