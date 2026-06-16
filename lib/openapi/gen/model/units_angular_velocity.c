
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "units_angular_velocity.h"

OpenAPI_units_angular_velocity_t *OpenAPI_units_angular_velocity_create(
)
{
    OpenAPI_units_angular_velocity_t *units_angular_velocity_local_var = ogs_malloc(sizeof(OpenAPI_units_angular_velocity_t));
    ogs_assert(units_angular_velocity_local_var);


    return units_angular_velocity_local_var;
}

void OpenAPI_units_angular_velocity_free(OpenAPI_units_angular_velocity_t *units_angular_velocity)
{
    if (NULL == units_angular_velocity) {
        return;
    }
    OpenAPI_lnode_t *node;
    ogs_free(units_angular_velocity);
}

cJSON *OpenAPI_units_angular_velocity_convertToJSON(OpenAPI_units_angular_velocity_t *units_angular_velocity)
{
    cJSON *item = NULL;

    if (units_angular_velocity == NULL) {
        ogs_error("OpenAPI_units_angular_velocity_convertToJSON() failed [UnitsAngularVelocity]");
        return NULL;
    }

    item = cJSON_CreateObject();
end:
    return item;
}

OpenAPI_units_angular_velocity_t *OpenAPI_units_angular_velocity_parseFromJSON(cJSON *units_angular_velocityJSON)
{
    OpenAPI_units_angular_velocity_t *units_angular_velocity_local_var = NULL;
    units_angular_velocity_local_var = OpenAPI_units_angular_velocity_create (
    );

    return units_angular_velocity_local_var;
end:
    return NULL;
}

OpenAPI_units_angular_velocity_t *OpenAPI_units_angular_velocity_copy(OpenAPI_units_angular_velocity_t *dst, OpenAPI_units_angular_velocity_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_units_angular_velocity_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_units_angular_velocity_convertToJSON() failed");
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

    OpenAPI_units_angular_velocity_free(dst);
    dst = OpenAPI_units_angular_velocity_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

