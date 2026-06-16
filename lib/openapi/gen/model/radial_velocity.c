
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "radial_velocity.h"

OpenAPI_radial_velocity_t *OpenAPI_radial_velocity_create(
    OpenAPI_units_linear_velocity_t *units_radial_velocity,
    int radial_velocity,
    int r_velocity_uncertainty
)
{
    OpenAPI_radial_velocity_t *radial_velocity_local_var = ogs_malloc(sizeof(OpenAPI_radial_velocity_t));
    ogs_assert(radial_velocity_local_var);

    radial_velocity_local_var->units_radial_velocity = units_radial_velocity;
    radial_velocity_local_var->radial_velocity = radial_velocity;
    radial_velocity_local_var->r_velocity_uncertainty = r_velocity_uncertainty;

    return radial_velocity_local_var;
}

void OpenAPI_radial_velocity_free(OpenAPI_radial_velocity_t *radial_velocity)
{
    if (NULL == radial_velocity) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_units_linear_velocity_free(radial_velocity->units_radial_velocity);
    ogs_free(radial_velocity);
}

cJSON *OpenAPI_radial_velocity_convertToJSON(OpenAPI_radial_velocity_t *radial_velocity)
{
    cJSON *item = NULL;

    if (radial_velocity == NULL) {
        ogs_error("OpenAPI_radial_velocity_convertToJSON() failed [RadialVelocity]");
        return NULL;
    }

    item = cJSON_CreateObject();
    cJSON *units_radial_velocity_local_JSON = OpenAPI_units_linear_velocity_convertToJSON(radial_velocity->units_radial_velocity);
    if (units_radial_velocity_local_JSON == NULL) {
        ogs_error("OpenAPI_radial_velocity_convertToJSON() failed [units_radial_velocity]");
        goto end;
    }
    cJSON_AddItemToObject(item, "unitsRadialVelocity", units_radial_velocity_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_radial_velocity_convertToJSON() failed [units_radial_velocity]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "radialVelocity", radial_velocity->radial_velocity) == NULL) {
        ogs_error("OpenAPI_radial_velocity_convertToJSON() failed [radial_velocity]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "rVelocityUncertainty", radial_velocity->r_velocity_uncertainty) == NULL) {
        ogs_error("OpenAPI_radial_velocity_convertToJSON() failed [r_velocity_uncertainty]");
        goto end;
    }

end:
    return item;
}

OpenAPI_radial_velocity_t *OpenAPI_radial_velocity_parseFromJSON(cJSON *radial_velocityJSON)
{
    OpenAPI_radial_velocity_t *radial_velocity_local_var = NULL;
    cJSON *units_radial_velocity = cJSON_GetObjectItemCaseSensitive(radial_velocityJSON, "unitsRadialVelocity");
    if (!units_radial_velocity) {
        ogs_error("OpenAPI_radial_velocity_parseFromJSON() failed [units_radial_velocity]");
        goto end;
    }

    OpenAPI_units_linear_velocity_t *units_radial_velocity_local_nonprim = NULL;
    units_radial_velocity_local_nonprim = OpenAPI_units_linear_velocity_parseFromJSON(units_radial_velocity);

    cJSON *radial_velocity = cJSON_GetObjectItemCaseSensitive(radial_velocityJSON, "radialVelocity");
    if (!radial_velocity) {
        ogs_error("OpenAPI_radial_velocity_parseFromJSON() failed [radial_velocity]");
        goto end;
    }

    if (!cJSON_IsNumber(radial_velocity)) {
        ogs_error("OpenAPI_radial_velocity_parseFromJSON() failed [radial_velocity]");
        goto end;
    }

    cJSON *r_velocity_uncertainty = cJSON_GetObjectItemCaseSensitive(radial_velocityJSON, "rVelocityUncertainty");
    if (!r_velocity_uncertainty) {
        ogs_error("OpenAPI_radial_velocity_parseFromJSON() failed [r_velocity_uncertainty]");
        goto end;
    }

    if (!cJSON_IsNumber(r_velocity_uncertainty)) {
        ogs_error("OpenAPI_radial_velocity_parseFromJSON() failed [r_velocity_uncertainty]");
        goto end;
    }

    radial_velocity_local_var = OpenAPI_radial_velocity_create (
        units_radial_velocity_local_nonprim,
        
        radial_velocity->valuedouble,
        
        r_velocity_uncertainty->valuedouble
    );

    return radial_velocity_local_var;
end:
    return NULL;
}

OpenAPI_radial_velocity_t *OpenAPI_radial_velocity_copy(OpenAPI_radial_velocity_t *dst, OpenAPI_radial_velocity_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_radial_velocity_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_radial_velocity_convertToJSON() failed");
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

    OpenAPI_radial_velocity_free(dst);
    dst = OpenAPI_radial_velocity_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

