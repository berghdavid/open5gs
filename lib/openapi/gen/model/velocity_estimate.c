
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "velocity_estimate.h"

OpenAPI_velocity_estimate_t *OpenAPI_velocity_estimate_create(
    float h_speed,
    int bearing,
    float v_speed,
    OpenAPI_vertical_direction_e v_direction,
    float h_uncertainty,
    float v_uncertainty,
    OpenAPI_radial_velocity_t *r_velocity,
    OpenAPI_angular_velocity_t *a_transverse_velocity,
    OpenAPI_angular_velocity_t *e_transverse_velocity
)
{
    OpenAPI_velocity_estimate_t *velocity_estimate_local_var = ogs_malloc(sizeof(OpenAPI_velocity_estimate_t));
    ogs_assert(velocity_estimate_local_var);

    velocity_estimate_local_var->h_speed = h_speed;
    velocity_estimate_local_var->bearing = bearing;
    velocity_estimate_local_var->v_speed = v_speed;
    velocity_estimate_local_var->v_direction = v_direction;
    velocity_estimate_local_var->h_uncertainty = h_uncertainty;
    velocity_estimate_local_var->v_uncertainty = v_uncertainty;
    velocity_estimate_local_var->r_velocity = r_velocity;
    velocity_estimate_local_var->a_transverse_velocity = a_transverse_velocity;
    velocity_estimate_local_var->e_transverse_velocity = e_transverse_velocity;

    return velocity_estimate_local_var;
}

void OpenAPI_velocity_estimate_free(OpenAPI_velocity_estimate_t *velocity_estimate)
{
    if (NULL == velocity_estimate) {
        return;
    }
    OpenAPI_lnode_t *node;
    OpenAPI_radial_velocity_free(velocity_estimate->r_velocity);
    OpenAPI_angular_velocity_free(velocity_estimate->a_transverse_velocity);
    OpenAPI_angular_velocity_free(velocity_estimate->e_transverse_velocity);
    ogs_free(velocity_estimate);
}

cJSON *OpenAPI_velocity_estimate_convertToJSON(OpenAPI_velocity_estimate_t *velocity_estimate)
{
    cJSON *item = NULL;

    if (velocity_estimate == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [VelocityEstimate]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (cJSON_AddNumberToObject(item, "hSpeed", velocity_estimate->h_speed) == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [h_speed]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "bearing", velocity_estimate->bearing) == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [bearing]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "vSpeed", velocity_estimate->v_speed) == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [v_speed]");
        goto end;
    }

    if (cJSON_AddStringToObject(item, "vDirection", OpenAPI_vertical_direction_ToString(velocity_estimate->v_direction)) == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [v_direction]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "hUncertainty", velocity_estimate->h_uncertainty) == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [h_uncertainty]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "vUncertainty", velocity_estimate->v_uncertainty) == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [v_uncertainty]");
        goto end;
    }

    if (velocity_estimate->r_velocity) {
    cJSON *r_velocity_local_JSON = OpenAPI_radial_velocity_convertToJSON(velocity_estimate->r_velocity);
    if (r_velocity_local_JSON == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [r_velocity]");
        goto end;
    }
    cJSON_AddItemToObject(item, "rVelocity", r_velocity_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [r_velocity]");
        goto end;
    }
    }

    if (velocity_estimate->a_transverse_velocity) {
    cJSON *a_transverse_velocity_local_JSON = OpenAPI_angular_velocity_convertToJSON(velocity_estimate->a_transverse_velocity);
    if (a_transverse_velocity_local_JSON == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [a_transverse_velocity]");
        goto end;
    }
    cJSON_AddItemToObject(item, "aTransverseVelocity", a_transverse_velocity_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [a_transverse_velocity]");
        goto end;
    }
    }

    if (velocity_estimate->e_transverse_velocity) {
    cJSON *e_transverse_velocity_local_JSON = OpenAPI_angular_velocity_convertToJSON(velocity_estimate->e_transverse_velocity);
    if (e_transverse_velocity_local_JSON == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [e_transverse_velocity]");
        goto end;
    }
    cJSON_AddItemToObject(item, "eTransverseVelocity", e_transverse_velocity_local_JSON);
    if (item->child == NULL) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed [e_transverse_velocity]");
        goto end;
    }
    }

end:
    return item;
}

OpenAPI_velocity_estimate_t *OpenAPI_velocity_estimate_parseFromJSON(cJSON *velocity_estimateJSON)
{
    OpenAPI_velocity_estimate_t *velocity_estimate_local_var = NULL;
    cJSON *h_speed = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "hSpeed");
    if (!h_speed) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [h_speed]");
        goto end;
    }

    if (!cJSON_IsNumber(h_speed)) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [h_speed]");
        goto end;
    }

    cJSON *bearing = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "bearing");
    if (!bearing) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [bearing]");
        goto end;
    }

    if (!cJSON_IsNumber(bearing)) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [bearing]");
        goto end;
    }

    cJSON *v_speed = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "vSpeed");
    if (!v_speed) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [v_speed]");
        goto end;
    }

    if (!cJSON_IsNumber(v_speed)) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [v_speed]");
        goto end;
    }

    cJSON *v_direction = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "vDirection");
    if (!v_direction) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [v_direction]");
        goto end;
    }

    OpenAPI_vertical_direction_e v_directionVariable;
    if (!cJSON_IsString(v_direction)) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [v_direction]");
        goto end;
    }
    v_directionVariable = OpenAPI_vertical_direction_FromString(v_direction->valuestring);

    cJSON *h_uncertainty = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "hUncertainty");
    if (!h_uncertainty) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [h_uncertainty]");
        goto end;
    }

    if (!cJSON_IsNumber(h_uncertainty)) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [h_uncertainty]");
        goto end;
    }

    cJSON *v_uncertainty = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "vUncertainty");
    if (!v_uncertainty) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [v_uncertainty]");
        goto end;
    }

    if (!cJSON_IsNumber(v_uncertainty)) {
        ogs_error("OpenAPI_velocity_estimate_parseFromJSON() failed [v_uncertainty]");
        goto end;
    }

    cJSON *r_velocity = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "rVelocity");

    OpenAPI_radial_velocity_t *r_velocity_local_nonprim = NULL;
    if (r_velocity) {
    r_velocity_local_nonprim = OpenAPI_radial_velocity_parseFromJSON(r_velocity);
    }

    cJSON *a_transverse_velocity = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "aTransverseVelocity");

    OpenAPI_angular_velocity_t *a_transverse_velocity_local_nonprim = NULL;
    if (a_transverse_velocity) {
    a_transverse_velocity_local_nonprim = OpenAPI_angular_velocity_parseFromJSON(a_transverse_velocity);
    }

    cJSON *e_transverse_velocity = cJSON_GetObjectItemCaseSensitive(velocity_estimateJSON, "eTransverseVelocity");

    OpenAPI_angular_velocity_t *e_transverse_velocity_local_nonprim = NULL;
    if (e_transverse_velocity) {
    e_transverse_velocity_local_nonprim = OpenAPI_angular_velocity_parseFromJSON(e_transverse_velocity);
    }

    velocity_estimate_local_var = OpenAPI_velocity_estimate_create (
        
        h_speed->valuedouble,
        
        bearing->valuedouble,
        
        v_speed->valuedouble,
        v_directionVariable,
        
        h_uncertainty->valuedouble,
        
        v_uncertainty->valuedouble,
        r_velocity ? r_velocity_local_nonprim : NULL,
        a_transverse_velocity ? a_transverse_velocity_local_nonprim : NULL,
        e_transverse_velocity ? e_transverse_velocity_local_nonprim : NULL
    );

    return velocity_estimate_local_var;
end:
    return NULL;
}

OpenAPI_velocity_estimate_t *OpenAPI_velocity_estimate_copy(OpenAPI_velocity_estimate_t *dst, OpenAPI_velocity_estimate_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    ogs_assert(src);
    item = OpenAPI_velocity_estimate_convertToJSON(src);
    if (!item) {
        ogs_error("OpenAPI_velocity_estimate_convertToJSON() failed");
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

    OpenAPI_velocity_estimate_free(dst);
    dst = OpenAPI_velocity_estimate_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

