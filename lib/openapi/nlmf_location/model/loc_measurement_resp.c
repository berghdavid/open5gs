#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "loc_measurement_resp.h"



static loc_measurement_resp_t *loc_measurement_resp_create_internal(
    list_t *loc_measurements
    ) {
    loc_measurement_resp_t *loc_measurement_resp_local_var = malloc(sizeof(loc_measurement_resp_t));
    if (!loc_measurement_resp_local_var) {
        return NULL;
    }
    memset(loc_measurement_resp_local_var, 0, sizeof(loc_measurement_resp_t));
    loc_measurement_resp_local_var->_library_owned = 1;
    loc_measurement_resp_local_var->loc_measurements = loc_measurements;
    return loc_measurement_resp_local_var;
}

__attribute__((deprecated)) loc_measurement_resp_t *loc_measurement_resp_create(
    list_t *loc_measurements
    ) {
    loc_measurement_resp_t *result = loc_measurement_resp_create_internal (
        loc_measurements
        );
    if (!result) {
    }
    return result;
}

void loc_measurement_resp_free(loc_measurement_resp_t *loc_measurement_resp) {
    if(NULL == loc_measurement_resp){
        return ;
    }
    if(loc_measurement_resp->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "loc_measurement_resp_free");
        return ;
    }
    listEntry_t *listEntry;
    if (loc_measurement_resp->loc_measurements) {
        list_ForEach(listEntry, loc_measurement_resp->loc_measurements) {
            loc_measurements_free(listEntry->data);
        }
        list_freeList(loc_measurement_resp->loc_measurements);
        loc_measurement_resp->loc_measurements = NULL;
    }
    free(loc_measurement_resp);
}

cJSON *loc_measurement_resp_convertToJSON(loc_measurement_resp_t *loc_measurement_resp) {
    cJSON *item = cJSON_CreateObject();

    // loc_measurement_resp->loc_measurements
    if (!loc_measurement_resp->loc_measurements) {
        goto fail;
    }
    cJSON *loc_measurements = cJSON_AddArrayToObject(item, "locMeasurements");
    if(loc_measurements == NULL) {
    goto fail; //nonprimitive container
    }

    listEntry_t *loc_measurementsListEntry;
    if (loc_measurement_resp->loc_measurements) {
    list_ForEach(loc_measurementsListEntry, loc_measurement_resp->loc_measurements) {
    cJSON *itemLocal = loc_measurements_convertToJSON(loc_measurementsListEntry->data);
    if(itemLocal == NULL) {
    goto fail;
    }
    cJSON_AddItemToArray(loc_measurements, itemLocal);
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

loc_measurement_resp_t *loc_measurement_resp_parseFromJSON(cJSON *loc_measurement_respJSON){

    loc_measurement_resp_t *loc_measurement_resp_local_var = NULL;

    // define the local list for loc_measurement_resp->loc_measurements
    list_t *loc_measurementsList = NULL;

    // loc_measurement_resp->loc_measurements
    cJSON *loc_measurements = cJSON_GetObjectItemCaseSensitive(loc_measurement_respJSON, "locMeasurements");
    if (cJSON_IsNull(loc_measurements)) {
        loc_measurements = NULL;
    }
    if (!loc_measurements) {
        goto end;
    }

    
    cJSON *loc_measurements_local_nonprimitive = NULL;
    if(!cJSON_IsArray(loc_measurements)){
        goto end; //nonprimitive container
    }

    loc_measurementsList = list_createList();

    cJSON_ArrayForEach(loc_measurements_local_nonprimitive,loc_measurements )
    {
        if(!cJSON_IsObject(loc_measurements_local_nonprimitive)){
            goto end;
        }
        loc_measurements_t *loc_measurementsItem = loc_measurements_parseFromJSON(loc_measurements_local_nonprimitive);

        list_addElement(loc_measurementsList, loc_measurementsItem);
    }



    loc_measurement_resp_local_var = loc_measurement_resp_create_internal (
        loc_measurementsList
        );

    if (!loc_measurement_resp_local_var) {
        goto end;
    }

    return loc_measurement_resp_local_var;
end:
    if (loc_measurementsList) {
        listEntry_t *listEntry = NULL;
        list_ForEach(listEntry, loc_measurementsList) {
            loc_measurements_free(listEntry->data);
            listEntry->data = NULL;
        }
        list_freeList(loc_measurementsList);
        loc_measurementsList = NULL;
    }
    return NULL;

}
