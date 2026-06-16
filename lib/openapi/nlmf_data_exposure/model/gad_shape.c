#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "gad_shape.h"



static gad_shape_t *gad_shape_create_internal(
    supported_gad_shapes_t *shape
    ) {
    gad_shape_t *gad_shape_local_var = malloc(sizeof(gad_shape_t));
    if (!gad_shape_local_var) {
        return NULL;
    }
    memset(gad_shape_local_var, 0, sizeof(gad_shape_t));
    gad_shape_local_var->_library_owned = 1;
    gad_shape_local_var->shape = shape;
    return gad_shape_local_var;
}

__attribute__((deprecated)) gad_shape_t *gad_shape_create(
    supported_gad_shapes_t *shape
    ) {
    gad_shape_t *result = gad_shape_create_internal (
        shape
        );
    if (!result) {
    }
    return result;
}

void gad_shape_free(gad_shape_t *gad_shape) {
    if(NULL == gad_shape){
        return ;
    }
    if(gad_shape->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "gad_shape_free");
        return ;
    }
    listEntry_t *listEntry;
    if (gad_shape->shape) {
        supported_gad_shapes_free(gad_shape->shape);
        gad_shape->shape = NULL;
    }
    free(gad_shape);
}

cJSON *gad_shape_convertToJSON(gad_shape_t *gad_shape) {
    cJSON *item = cJSON_CreateObject();

    // gad_shape->shape
    if (!gad_shape->shape) {
        goto fail;
    }
    cJSON *shape_local_JSON = supported_gad_shapes_convertToJSON(gad_shape->shape);
    if(shape_local_JSON == NULL) {
    goto fail; //model
    }
    cJSON_AddItemToObject(item, "shape", shape_local_JSON);
    if(item->child == NULL) {
    goto fail;
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

gad_shape_t *gad_shape_parseFromJSON(cJSON *gad_shapeJSON){

    gad_shape_t *gad_shape_local_var = NULL;

    // define the local variable for gad_shape->shape
    supported_gad_shapes_t *shape_local_nonprim = NULL;

    // gad_shape->shape
    cJSON *shape = cJSON_GetObjectItemCaseSensitive(gad_shapeJSON, "shape");
    if (cJSON_IsNull(shape)) {
        shape = NULL;
    }
    if (!shape) {
        goto end;
    }

    
    shape_local_nonprim = supported_gad_shapes_parseFromJSON(shape); //nonprimitive



    gad_shape_local_var = gad_shape_create_internal (
        shape_local_nonprim
        );

    if (!gad_shape_local_var) {
        goto end;
    }

    return gad_shape_local_var;
end:
    if (shape_local_nonprim) {
        supported_gad_shapes_free(shape_local_nonprim);
        shape_local_nonprim = NULL;
    }
    return NULL;

}
