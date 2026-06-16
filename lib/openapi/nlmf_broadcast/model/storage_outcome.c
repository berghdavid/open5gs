#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "storage_outcome.h"


char* storage_outcome_storage_outcome_ToString(lmf_broadcast_storage_outcome__e storage_outcome) {
    char *storage_outcomeArray[] =  { "NULL", "STORAGE_SUCCESSFUL", "STORAGE_FAILED" };
    return storage_outcomeArray[storage_outcome];
}

lmf_broadcast_storage_outcome__e storage_outcome_storage_outcome_FromString(char* storage_outcome) {
    int stringToReturn = 0;
    char *storage_outcomeArray[] =  { "NULL", "STORAGE_SUCCESSFUL", "STORAGE_FAILED" };
    size_t sizeofArray = sizeof(storage_outcomeArray) / sizeof(storage_outcomeArray[0]);
    while(stringToReturn < sizeofArray) {
        if(strcmp(storage_outcome, storage_outcomeArray[stringToReturn]) == 0) {
            return stringToReturn;
        }
        stringToReturn++;
    }
    return 0;
}

cJSON *storage_outcome_convertToJSON(lmf_broadcast_storage_outcome__e storage_outcome) {
    cJSON *item = cJSON_CreateObject();
    if(cJSON_AddStringToObject(item, "storage_outcome", storage_outcome_storage_outcome_ToString(storage_outcome)) == NULL) {
        goto fail;
    }
    return item;
fail:
    cJSON_Delete(item);
    return NULL;
}

lmf_broadcast_storage_outcome__e storage_outcome_parseFromJSON(cJSON *storage_outcomeJSON) {
    if(!cJSON_IsString(storage_outcomeJSON) || (storage_outcomeJSON->valuestring == NULL)) {
        return 0;
    }
    return storage_outcome_storage_outcome_FromString(storage_outcomeJSON->valuestring);
}
