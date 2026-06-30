
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_uncertainty_ellipse.h"

OpenAPI_point_uncertainty_ellipse_t *OpenAPI_point_uncertainty_ellipse_create(
    OpenAPI_supported_gad_shapes_t *shape,
    OpenAPI_geographical_coordinates_t *point,
    OpenAPI_uncertainty_ellipse_t *uncertainty_ellipse,
    int confidence
)
{
    OpenAPI_point_uncertainty_ellipse_t *point_uncertainty_ellipse_local_var = ogs_malloc(sizeof(OpenAPI_point_uncertainty_ellipse_t));
    log_assert(point_uncertainty_ellipse_local_var);

    point_uncertainty_ellipse_local_var->shape = shape;
    point_uncertainty_ellipse_local_var->point = point;
    point_uncertainty_ellipse_local_var->uncertainty_ellipse = uncertainty_ellipse;
    point_uncertainty_ellipse_local_var->confidence = confidence;

    return point_uncertainty_ellipse_local_var;
}

void OpenAPI_point_uncertainty_ellipse_free(OpenAPI_point_uncertainty_ellipse_t *point_uncertainty_ellipse)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == point_uncertainty_ellipse) {
        return;
    }
    if (point_uncertainty_ellipse->shape) {
        OpenAPI_supported_gad_shapes_free(point_uncertainty_ellipse->shape);
        point_uncertainty_ellipse->shape = NULL;
    }
    if (point_uncertainty_ellipse->point) {
        OpenAPI_geographical_coordinates_free(point_uncertainty_ellipse->point);
        point_uncertainty_ellipse->point = NULL;
    }
    if (point_uncertainty_ellipse->uncertainty_ellipse) {
        OpenAPI_uncertainty_ellipse_free(point_uncertainty_ellipse->uncertainty_ellipse);
        point_uncertainty_ellipse->uncertainty_ellipse = NULL;
    }
    ogs_free(point_uncertainty_ellipse);
}

cJSON *OpenAPI_point_uncertainty_ellipse_convertToJSON(OpenAPI_point_uncertainty_ellipse_t *point_uncertainty_ellipse)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (point_uncertainty_ellipse == NULL) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [PointUncertaintyEllipse]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!point_uncertainty_ellipse->shape) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [shape]");
        return NULL;
    }
    cJSON *shape_local_JSON = OpenAPI_supported_gad_shapes_convertToJSON(point_uncertainty_ellipse->shape);
    if (shape_local_JSON == NULL) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [shape]");
        goto end;
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if (item->child == NULL) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [shape]");
        goto end;
    }

    if (!point_uncertainty_ellipse->point) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [point]");
        return NULL;
    }
    cJSON *point_local_JSON = OpenAPI_geographical_coordinates_convertToJSON(point_uncertainty_ellipse->point);
    if (point_local_JSON == NULL) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [point]");
        goto end;
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if (item->child == NULL) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [point]");
        goto end;
    }

    if (!point_uncertainty_ellipse->uncertainty_ellipse) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [uncertainty_ellipse]");
        return NULL;
    }
    cJSON *uncertainty_ellipse_local_JSON = OpenAPI_uncertainty_ellipse_convertToJSON(point_uncertainty_ellipse->uncertainty_ellipse);
    if (uncertainty_ellipse_local_JSON == NULL) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [uncertainty_ellipse]");
        goto end;
    }
    cJSON_AddItemToObject(item, "uncertaintyEllipse", uncertainty_ellipse_local_JSON);
    if (item->child == NULL) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [uncertainty_ellipse]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "confidence", point_uncertainty_ellipse->confidence) == NULL) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed [confidence]");
        goto end;
    }

end:
    return item;
}

OpenAPI_point_uncertainty_ellipse_t *OpenAPI_point_uncertainty_ellipse_parseFromJSON(cJSON *point_uncertainty_ellipseJSON)
{
    OpenAPI_point_uncertainty_ellipse_t *point_uncertainty_ellipse_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *shape = NULL;
    OpenAPI_supported_gad_shapes_t *shape_local_nonprim = NULL;
    cJSON *point = NULL;
    OpenAPI_geographical_coordinates_t *point_local_nonprim = NULL;
    cJSON *uncertainty_ellipse = NULL;
    OpenAPI_uncertainty_ellipse_t *uncertainty_ellipse_local_nonprim = NULL;
    cJSON *confidence = NULL;
    shape = cJSON_GetObjectItemCaseSensitive(point_uncertainty_ellipseJSON, "shape");
    if (!shape) {
        log_error("OpenAPI_point_uncertainty_ellipse_parseFromJSON() failed [shape]");
        goto end;
    }
    shape_local_nonprim = OpenAPI_supported_gad_shapes_parseFromJSON(shape);
    if (!shape_local_nonprim) {
        log_error("OpenAPI_supported_gad_shapes_parseFromJSON failed [shape]");
        goto end;
    }

    point = cJSON_GetObjectItemCaseSensitive(point_uncertainty_ellipseJSON, "point");
    if (!point) {
        log_error("OpenAPI_point_uncertainty_ellipse_parseFromJSON() failed [point]");
        goto end;
    }
    point_local_nonprim = OpenAPI_geographical_coordinates_parseFromJSON(point);
    if (!point_local_nonprim) {
        log_error("OpenAPI_geographical_coordinates_parseFromJSON failed [point]");
        goto end;
    }

    uncertainty_ellipse = cJSON_GetObjectItemCaseSensitive(point_uncertainty_ellipseJSON, "uncertaintyEllipse");
    if (!uncertainty_ellipse) {
        log_error("OpenAPI_point_uncertainty_ellipse_parseFromJSON() failed [uncertainty_ellipse]");
        goto end;
    }
    uncertainty_ellipse_local_nonprim = OpenAPI_uncertainty_ellipse_parseFromJSON(uncertainty_ellipse);
    if (!uncertainty_ellipse_local_nonprim) {
        log_error("OpenAPI_uncertainty_ellipse_parseFromJSON failed [uncertainty_ellipse]");
        goto end;
    }

    confidence = cJSON_GetObjectItemCaseSensitive(point_uncertainty_ellipseJSON, "confidence");
    if (!confidence) {
        log_error("OpenAPI_point_uncertainty_ellipse_parseFromJSON() failed [confidence]");
        goto end;
    }
    if (!cJSON_IsNumber(confidence)) {
        log_error("OpenAPI_point_uncertainty_ellipse_parseFromJSON() failed [confidence]");
        goto end;
    }

    point_uncertainty_ellipse_local_var = OpenAPI_point_uncertainty_ellipse_create (
        shape_local_nonprim,
        point_local_nonprim,
        uncertainty_ellipse_local_nonprim,
        
        confidence->valuedouble
    );

    return point_uncertainty_ellipse_local_var;
end:
    if (shape_local_nonprim) {
        OpenAPI_supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
    }
    if (point_local_nonprim) {
        OpenAPI_geographical_coordinates_free(point_local_nonprim);
        point_local_nonprim = NULL;
    }
    if (uncertainty_ellipse_local_nonprim) {
        OpenAPI_uncertainty_ellipse_free(uncertainty_ellipse_local_nonprim);
        uncertainty_ellipse_local_nonprim = NULL;
    }
    return NULL;
}

OpenAPI_point_uncertainty_ellipse_t *OpenAPI_point_uncertainty_ellipse_copy(OpenAPI_point_uncertainty_ellipse_t *dst, OpenAPI_point_uncertainty_ellipse_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_point_uncertainty_ellipse_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_point_uncertainty_ellipse_convertToJSON() failed");
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

    OpenAPI_point_uncertainty_ellipse_free(dst);
    dst = OpenAPI_point_uncertainty_ellipse_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

