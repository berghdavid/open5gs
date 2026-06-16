/*
 * data_availability.h
 *
 * Indicates availability of ciphering key data at an LMF.
 */

#ifndef _data_availability_H_
#define _data_availability_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct data_availability_t data_availability_t;


// Enum  for data_availability

typedef enum { lmf_broadcast_data_availability__NULL = 0, lmf_broadcast_data_availability__CIPHERING_KEY_DATA_AVAILABLE, lmf_broadcast_data_availability__CIPHERING_KEY_DATA_NOT_AVAILABLE } lmf_broadcast_data_availability__e;

char* data_availability_data_availability_ToString(lmf_broadcast_data_availability__e data_availability);

lmf_broadcast_data_availability__e data_availability_data_availability_FromString(char* data_availability);

cJSON *data_availability_convertToJSON(lmf_broadcast_data_availability__e data_availability);

lmf_broadcast_data_availability__e data_availability_parseFromJSON(cJSON *data_availabilityJSON);

#endif /* _data_availability_H_ */

