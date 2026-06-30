
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "point_altitude_all_of.h"

OpenAPI_point_altitude_all_of_t *OpenAPI_point_altitude_all_of_create(
    OpenAPI_geographical_coordinates_t *point,
    double altitude
)
{
    OpenAPI_point_altitude_all_of_t *point_altitude_all_of_local_var = ogs_malloc(sizeof(OpenAPI_point_altitude_all_of_t));
    log_assert(point_altitude_all_of_local_var);

    point_altitude_all_of_local_var->point = point;
    point_altitude_all_of_local_var->altitude = altitude;

    return point_altitude_all_of_local_var;
}

void OpenAPI_point_altitude_all_of_free(OpenAPI_point_altitude_all_of_t *point_altitude_all_of)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == point_altitude_all_of) {
        return;
    }
    if (point_altitude_all_of->point) {
        OpenAPI_geographical_coordinates_free(point_altitude_all_of->point);
        point_altitude_all_of->point = NULL;
    }
    ogs_free(point_altitude_all_of);
}

cJSON *OpenAPI_point_altitude_all_of_convertToJSON(OpenAPI_point_altitude_all_of_t *point_altitude_all_of)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (point_altitude_all_of == NULL) {
        log_error("OpenAPI_point_altitude_all_of_convertToJSON() failed [PointAltitude_allOf]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!point_altitude_all_of->point) {
        log_error("OpenAPI_point_altitude_all_of_convertToJSON() failed [point]");
        return NULL;
    }
    cJSON *point_local_JSON = OpenAPI_geographical_coordinates_convertToJSON(point_altitude_all_of->point);
    if (point_local_JSON == NULL) {
        log_error("OpenAPI_point_altitude_all_of_convertToJSON() failed [point]");
        goto end;
    }
    cJSON_AddItemToObject(item, "point", point_local_JSON);
    if (item->child == NULL) {
        log_error("OpenAPI_point_altitude_all_of_convertToJSON() failed [point]");
        goto end;
    }

    if (cJSON_AddNumberToObject(item, "altitude", point_altitude_all_of->altitude) == NULL) {
        log_error("OpenAPI_point_altitude_all_of_convertToJSON() failed [altitude]");
        goto end;
    }

end:
    return item;
}

OpenAPI_point_altitude_all_of_t *OpenAPI_point_altitude_all_of_parseFromJSON(cJSON *point_altitude_all_ofJSON)
{
    OpenAPI_point_altitude_all_of_t *point_altitude_all_of_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *point = NULL;
    OpenAPI_geographical_coordinates_t *point_local_nonprim = NULL;
    cJSON *altitude = NULL;
    point = cJSON_GetObjectItemCaseSensitive(point_altitude_all_ofJSON, "point");
    if (!point) {
        log_error("OpenAPI_point_altitude_all_of_parseFromJSON() failed [point]");
        goto end;
    }
    point_local_nonprim = OpenAPI_geographical_coordinates_parseFromJSON(point);
    if (!point_local_nonprim) {
        log_error("OpenAPI_geographical_coordinates_parseFromJSON failed [point]");
        goto end;
    }

    altitude = cJSON_GetObjectItemCaseSensitive(point_altitude_all_ofJSON, "altitude");
    if (!altitude) {
        log_error("OpenAPI_point_altitude_all_of_parseFromJSON() failed [altitude]");
        goto end;
    }
    if (!cJSON_IsNumber(altitude)) {
        log_error("OpenAPI_point_altitude_all_of_parseFromJSON() failed [altitude]");
        goto end;
    }

    point_altitude_all_of_local_var = OpenAPI_point_altitude_all_of_create (
        point_local_nonprim,
        
        altitude->valuedouble
    );

    return point_altitude_all_of_local_var;
end:
    if (point_local_nonprim) {
        OpenAPI_geographical_coordinates_free(point_local_nonprim);
        point_local_nonprim = NULL;
    }
    return NULL;
}

OpenAPI_point_altitude_all_of_t *OpenAPI_point_altitude_all_of_copy(OpenAPI_point_altitude_all_of_t *dst, OpenAPI_point_altitude_all_of_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_point_altitude_all_of_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_point_altitude_all_of_convertToJSON() failed");
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

    OpenAPI_point_altitude_all_of_free(dst);
    dst = OpenAPI_point_altitude_all_of_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

