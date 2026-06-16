#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "supported_gad_shapes.h"



static supported_gad_shapes_t *supported_gad_shapes_create_internal(
    ) {
    supported_gad_shapes_t *supported_gad_shapes_local_var = malloc(sizeof(supported_gad_shapes_t));
    if (!supported_gad_shapes_local_var) {
        return NULL;
    }
    memset(supported_gad_shapes_local_var, 0, sizeof(supported_gad_shapes_t));
    supported_gad_shapes_local_var->_library_owned = 1;
    return supported_gad_shapes_local_var;
}

__attribute__((deprecated)) supported_gad_shapes_t *supported_gad_shapes_create(
    ) {
    supported_gad_shapes_t *result = supported_gad_shapes_create_internal (
        );
    if (!result) {
    }
    return result;
}

void supported_gad_shapes_free(supported_gad_shapes_t *supported_gad_shapes) {
    if(NULL == supported_gad_shapes){
        return ;
    }
    if(supported_gad_shapes->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "supported_gad_shapes_free");
        return ;
    }
    listEntry_t *listEntry;
    free(supported_gad_shapes);
}

cJSON *supported_gad_shapes_convertToJSON(supported_gad_shapes_t *supported_gad_shapes) {
    cJSON *item = cJSON_CreateObject();
    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

supported_gad_shapes_t *supported_gad_shapes_parseFromJSON(cJSON *supported_gad_shapesJSON){

    supported_gad_shapes_t *supported_gad_shapes_local_var = NULL;



    supported_gad_shapes_local_var = supported_gad_shapes_create_internal (
        );

    if (!supported_gad_shapes_local_var) {
        goto end;
    }

    return supported_gad_shapes_local_var;
end:
    return NULL;

}
