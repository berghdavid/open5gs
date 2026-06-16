#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_measurements.h"



static loc_measurements_t *loc_measurements_create_internal(
    char *loc_info
    ) {
    loc_measurements_t *loc_measurements_local_var = malloc(sizeof(loc_measurements_t));
    if (!loc_measurements_local_var) {
        return NULL;
    }
    memset(loc_measurements_local_var, 0, sizeof(loc_measurements_t));
    loc_measurements_local_var->_library_owned = 1;
    loc_measurements_local_var->loc_info = loc_info;
    return loc_measurements_local_var;
}

__attribute__((deprecated)) loc_measurements_t *loc_measurements_create(
    char *loc_info
    ) {
    loc_measurements_t *result = loc_measurements_create_internal (
        loc_info
        );
    if (!result) {
    }
    return result;
}

void loc_measurements_free(loc_measurements_t *loc_measurements) {
    if(NULL == loc_measurements){
        return ;
    }
    if(loc_measurements->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "loc_measurements_free");
        return ;
    }
    listEntry_t *listEntry;
    if (loc_measurements->loc_info) {
        free(loc_measurements->loc_info);
        loc_measurements->loc_info = NULL;
    }
    free(loc_measurements);
}

cJSON *loc_measurements_convertToJSON(loc_measurements_t *loc_measurements) {
    cJSON *item = cJSON_CreateObject();

    // loc_measurements->loc_info
    if(loc_measurements->loc_info) {
    if(cJSON_AddStringToObject(item, "locInfo", loc_measurements->loc_info) == NULL) {
    goto fail; //ByteArray
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

loc_measurements_t *loc_measurements_parseFromJSON(cJSON *loc_measurementsJSON){

    loc_measurements_t *loc_measurements_local_var = NULL;

    char *loc_info_local_str = NULL;

    // loc_measurements->loc_info
    cJSON *loc_info = cJSON_GetObjectItemCaseSensitive(loc_measurementsJSON, "locInfo");
    if (cJSON_IsNull(loc_info)) {
        loc_info = NULL;
    }
    if (loc_info) { 
    if(!cJSON_IsString(loc_info))
    {
    goto end; //ByteArray
    }
    }


    if (loc_info) loc_info_local_str = strdup(loc_info->valuestring);

    loc_measurements_local_var = loc_measurements_create_internal (
        loc_info_local_str
        );

    if (!loc_measurements_local_var) {
        goto end;
    }

    return loc_measurements_local_var;
end:
    if (loc_info_local_str) {
        free(loc_info_local_str);
        loc_info_local_str = NULL;
    }
    return NULL;

}
