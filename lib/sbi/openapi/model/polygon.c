
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "polygon.h"

OpenAPI_polygon_t *OpenAPI_polygon_create(
    OpenAPI_supported_gad_shapes_t *shape,
    OpenAPI_list_t *point_list
)
{
    OpenAPI_polygon_t *polygon_local_var = ogs_malloc(sizeof(OpenAPI_polygon_t));
    log_assert(polygon_local_var);

    polygon_local_var->shape = shape;
    polygon_local_var->point_list = point_list;

    return polygon_local_var;
}

void OpenAPI_polygon_free(OpenAPI_polygon_t *polygon)
{
    OpenAPI_lnode_t *node = NULL;

    if (NULL == polygon) {
        return;
    }
    if (polygon->shape) {
        OpenAPI_supported_gad_shapes_free(polygon->shape);
        polygon->shape = NULL;
    }
    if (polygon->point_list) {
        OpenAPI_list_for_each(polygon->point_list, node) {
            OpenAPI_geographical_coordinates_free(node->data);
        }
        OpenAPI_list_free(polygon->point_list);
        polygon->point_list = NULL;
    }
    ogs_free(polygon);
}

cJSON *OpenAPI_polygon_convertToJSON(OpenAPI_polygon_t *polygon)
{
    cJSON *item = NULL;
    OpenAPI_lnode_t *node = NULL;

    if (polygon == NULL) {
        log_error("OpenAPI_polygon_convertToJSON() failed [Polygon]");
        return NULL;
    }

    item = cJSON_CreateObject();
    if (!polygon->shape) {
        log_error("OpenAPI_polygon_convertToJSON() failed [shape]");
        return NULL;
    }
    cJSON *shape_local_JSON = OpenAPI_supported_gad_shapes_convertToJSON(polygon->shape);
    if (shape_local_JSON == NULL) {
        log_error("OpenAPI_polygon_convertToJSON() failed [shape]");
        goto end;
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if (item->child == NULL) {
        log_error("OpenAPI_polygon_convertToJSON() failed [shape]");
        goto end;
    }

    if (!polygon->point_list) {
        log_error("OpenAPI_polygon_convertToJSON() failed [point_list]");
        return NULL;
    }
    cJSON *point_listList = cJSON_AddArrayToObject(item, "pointList");
    if (point_listList == NULL) {
        log_error("OpenAPI_polygon_convertToJSON() failed [point_list]");
        goto end;
    }
    OpenAPI_list_for_each(polygon->point_list, node) {
        cJSON *itemLocal = OpenAPI_geographical_coordinates_convertToJSON(node->data);
        if (itemLocal == NULL) {
            log_error("OpenAPI_polygon_convertToJSON() failed [point_list]");
            goto end;
        }
        cJSON_AddItemToArray(point_listList, itemLocal);
    }

end:
    return item;
}

OpenAPI_polygon_t *OpenAPI_polygon_parseFromJSON(cJSON *polygonJSON)
{
    OpenAPI_polygon_t *polygon_local_var = NULL;
    OpenAPI_lnode_t *node = NULL;
    cJSON *shape = NULL;
    OpenAPI_supported_gad_shapes_t *shape_local_nonprim = NULL;
    cJSON *point_list = NULL;
    OpenAPI_list_t *point_listList = NULL;
    shape = cJSON_GetObjectItemCaseSensitive(polygonJSON, "shape");
    if (!shape) {
        log_error("OpenAPI_polygon_parseFromJSON() failed [shape]");
        goto end;
    }
    shape_local_nonprim = OpenAPI_supported_gad_shapes_parseFromJSON(shape);
    if (!shape_local_nonprim) {
        log_error("OpenAPI_supported_gad_shapes_parseFromJSON failed [shape]");
        goto end;
    }

    point_list = cJSON_GetObjectItemCaseSensitive(polygonJSON, "pointList");
    if (!point_list) {
        log_error("OpenAPI_polygon_parseFromJSON() failed [point_list]");
        goto end;
    }
        cJSON *point_list_local = NULL;
        if (!cJSON_IsArray(point_list)) {
            log_error("OpenAPI_polygon_parseFromJSON() failed [point_list]");
            goto end;
        }

        point_listList = OpenAPI_list_create();

        cJSON_ArrayForEach(point_list_local, point_list) {
            if (!cJSON_IsObject(point_list_local)) {
                log_error("OpenAPI_polygon_parseFromJSON() failed [point_list]");
                goto end;
            }
            OpenAPI_geographical_coordinates_t *point_listItem = OpenAPI_geographical_coordinates_parseFromJSON(point_list_local);
            if (!point_listItem) {
                log_error("No point_listItem");
                goto end;
            }
            OpenAPI_list_add(point_listList, point_listItem);
        }

    polygon_local_var = OpenAPI_polygon_create (
        shape_local_nonprim,
        point_listList
    );

    return polygon_local_var;
end:
    if (shape_local_nonprim) {
        OpenAPI_supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
    }
    if (point_listList) {
        OpenAPI_list_for_each(point_listList, node) {
            OpenAPI_geographical_coordinates_free(node->data);
        }
        OpenAPI_list_free(point_listList);
        point_listList = NULL;
    }
    return NULL;
}

OpenAPI_polygon_t *OpenAPI_polygon_copy(OpenAPI_polygon_t *dst, OpenAPI_polygon_t *src)
{
    cJSON *item = NULL;
    char *content = NULL;

    log_assert(src);
    item = OpenAPI_polygon_convertToJSON(src);
    if (!item) {
        log_error("OpenAPI_polygon_convertToJSON() failed");
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

    OpenAPI_polygon_free(dst);
    dst = OpenAPI_polygon_parseFromJSON(item);
    cJSON_Delete(item);

    return dst;
}

