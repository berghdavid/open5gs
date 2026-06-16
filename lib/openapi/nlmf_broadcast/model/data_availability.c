#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "data_availability.h"


char* data_availability_data_availability_ToString(lmf_broadcast_data_availability__e data_availability) {
    char *data_availabilityArray[] =  { "NULL", "CIPHERING_KEY_DATA_AVAILABLE", "CIPHERING_KEY_DATA_NOT_AVAILABLE" };
    return data_availabilityArray[data_availability];
}

lmf_broadcast_data_availability__e data_availability_data_availability_FromString(char* data_availability) {
    int stringToReturn = 0;
    char *data_availabilityArray[] =  { "NULL", "CIPHERING_KEY_DATA_AVAILABLE", "CIPHERING_KEY_DATA_NOT_AVAILABLE" };
    size_t sizeofArray = sizeof(data_availabilityArray) / sizeof(data_availabilityArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(data_availability, data_availabilityArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *data_availability_convertToJSON(lmf_broadcast_data_availability__e data_availability) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "data_availability", data_availability_data_availability_ToString(data_availability)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

lmf_broadcast_data_availability__e data_availability_parseFromJSON(cJSON *data_availabilityJSON) {
    if(!cJSON_IsString(data_availabilityJSON) || (data_availabilityJSON->valuestring == NULL)) {
        return 0;
    }
    return data_availability_data_availability_FromString(data_availabilityJSON->valuestring);
}
