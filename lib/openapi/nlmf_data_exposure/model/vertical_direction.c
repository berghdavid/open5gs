#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "vertical_direction.h"


char* vertical_direction_vertical_direction_ToString(nlmf_dataexposure_vertical_direction__e vertical_direction) {
    char *vertical_directionArray[] =  { "NULL", "UPWARD", "DOWNWARD" };
    return vertical_directionArray[vertical_direction];
}

nlmf_dataexposure_vertical_direction__e vertical_direction_vertical_direction_FromString(char* vertical_direction) {
    int stringToReturn = 0;
    char *vertical_directionArray[] =  { "NULL", "UPWARD", "DOWNWARD" };
    size_t sizeofArray = sizeof(vertical_directionArray) / sizeof(vertical_directionArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(vertical_direction, vertical_directionArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *vertical_direction_convertToJSON(nlmf_dataexposure_vertical_direction__e vertical_direction) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "vertical_direction", vertical_direction_vertical_direction_ToString(vertical_direction)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

nlmf_dataexposure_vertical_direction__e vertical_direction_parseFromJSON(cJSON *vertical_directionJSON) {
    if(!cJSON_IsString(vertical_directionJSON) || (vertical_directionJSON->valuestring == NULL)) {
        return 0;
    }
    return vertical_direction_vertical_direction_FromString(vertical_directionJSON->valuestring);
}
