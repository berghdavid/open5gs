
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "relative_velocity_with_uncertainty.h"

OpenAPI_relative_velocity_with_uncertainty_t *OpenAPI_relative_velocity_with_uncertainty_create(
    OpenAPI_radial_velocity_t *r_velocity,
    OpenAPI_angular_velocity_t *a_transverse_velocity,
    OpenAPI_angular_velocity_t *e_transverse_velocity
)
{
    OpenAPI_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty_local_var = ogs_malloc(sizeof(OpenAPI_relative_velocity_with_uncertainty_t));
    ogs_assert(relative_velocity_with_uncertainty_local_var);

    relative_velocity_with_uncertainty_local_var->r_velocity = r_velocity;
    relative_velocity_with_uncertainty_local_var->a_transverse_velocity = a_transverse_velocity;
    relative_velocity_with_uncertainty_local_var->e_transverse_velocity = e_transverse_velocity;

    return relative_velocity_with_uncertainty_local_var;
}

void OpenAPI_relative_velocity_with_uncertainty_free(OpenAPI_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty)
{
    if (NULL == relative_velocity_with_uncertainty) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_radial_velocity_free(relative_velocity_with_uncertainty->r_velocity);
    OpenAPI_angular_velocity_free(relative_velocity_with_uncertainty->a_transverse_velocity);
    OpenAPI_angular_velocity_free(relative_velocity_with_uncertainty->e_transverse_velocity);
    ogs_free(relative_velocity_with_uncertainty);
}

cJSON *OpenAPI_relative_velocity_with_uncertainty_convertToJSON(OpenAPI_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty)
{
    cJSON *item = NULL;

    if (relative_velocity_with_uncertainty == NULL) {
        ogs_error("OpenAPI_relative_velocity_with_uncertainty_convertToJSON() failed [RelativeVelocityWithUncertainty]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (relative_velocity_with_uncertainty->r_velocity) {
    cJSON *r_velocity_local_JSON = OpenAPI_radial_velocity_convertToJSON(relative_velocity_with_uncertainty->r_velocity);
    if (r_velocity_local_JSON == NULL) {
        ogs_error("OpenAPI_relative_velocity_with_uncertainty_convertToJSON() failed [r_velocity]");
        goto end;
    }
    cJSON_AddItemToObject(item, "rVelocity", r_velocity_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_relative_velocity_with_uncertainty_convertToJSON() failed [r_velocity]");
        goto end;
    }
    }

    if (relative_velocity_with_uncertainty->a_transverse_velocity) {
    cJSON *a_transverse_velocity_local_JSON = OpenAPI_angular_velocity_convertToJSON(relative_velocity_with_uncertainty->a_transverse_velocity);
    if (a_transverse_velocity_local_JSON == NULL) {
        ogs_error("OpenAPI_relative_velocity_with_uncertainty_convertToJSON() failed [a_transverse_velocity]");
        goto end;
    }
    cJSON_AddItemToObject(item, "aTransverseVelocity", a_transverse_velocity_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_relative_velocity_with_uncertainty_convertToJSON() failed [a_transverse_velocity]");
        goto end;
    }
    }

    if (relative_velocity_with_uncertainty->e_transverse_velocity) {
    cJSON *e_transverse_velocity_local_JSON = OpenAPI_angular_velocity_convertToJSON(relative_velocity_with_uncertainty->e_transverse_velocity);
    if (e_transverse_velocity_local_JSON == NULL) {
        ogs_error("OpenAPI_relative_velocity_with_uncertainty_convertToJSON() failed [e_transverse_velocity]");
        goto end;
    }
    cJSON_AddItemToObject(item, "eTransverseVelocity", e_transverse_velocity_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_relative_velocity_with_uncertainty_convertToJSON() failed [e_transverse_velocity]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_relative_velocity_with_uncertainty_t *OpenAPI_relative_velocity_with_uncertainty_parseFromJSON(cJSON *relative_velocity_with_uncertaintyJSON)
{
    OpenAPI_relative_velocity_with_uncertainty_t *relative_velocity_with_uncertainty_local_var = NULL;
    cJSON *r_velocity = cJSON_GetObjectItemCaseSensitive(relative_velocity_with_uncertaintyJSON, "rVelocity");

    OpenAPI_radial_velocity_t *r_velocity_local_nonprim = NULL;
    if (r_velocity) {
    r_velocity_local_nonprim = OpenAPI_radial_velocity_parseFromJSON(r_velocity);
    }

    cJSON *a_transverse_velocity = cJSON_GetObjectItemCaseSensitive(relative_velocity_with_uncertaintyJSON, "aTransverseVelocity");

    OpenAPI_angular_velocity_t *a_transverse_velocity_local_nonprim = NULL;
    if (a_transverse_velocity) {
    a_transverse_velocity_local_nonprim = OpenAPI_angular_velocity_parseFromJSON(a_transverse_velocity);
    }

    cJSON *e_transverse_velocity = cJSON_GetObjectItemCaseSensitive(relative_velocity_with_uncertaintyJSON, "eTransverseVelocity");

    OpenAPI_angular_velocity_t *e_transverse_velocity_local_nonprim = NULL;
    if (e_transverse_velocity) {
    e_transverse_velocity_local_nonprim = OpenAPI_angular_velocity_parseFromJSON(e_transverse_velocity);
    }

    relative_velocity_with_uncertainty_local_var = OpenAPI_relative_velocity_with_uncertainty_create (
        r_velocity ? r_velocity_local_nonprim : NULL,
        a_transverse_velocity ? a_transverse_velocity_local_nonprim : NULL,
        e_transverse_velocity ? e_transverse_velocity_local_nonprim : NULL
    );

    return relative_velocity_with_uncertainty_local_var;
end:
    return NULL;
}

OpenAPI_relative_velocity_with_uncertainty_t *OpenAPI_relative_velocity_with_uncertainty_copy(OpenAPI_relative_velocity_with_uncertainty_t *dst, OpenAPI_relative_velocity_with_uncertainty_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_relative_velocity_with_uncertainty_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_relative_velocity_with_uncertainty_convertToJSON() failed");
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

    OpenAPI_relative_velocity_with_uncertainty_free(dst);
    dst = OpenAPI_relative_velocity_with_uncertainty_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

