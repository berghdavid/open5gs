/*
 * add_event_notify_datas.h
 *
 * Additional Event Notify Data.
 */

#ifndef _add_event_notify_datas_H_
#define _add_event_notify_datas_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct add_event_notify_datas_t add_event_notify_datas_t;

#include "event_notify_data.h"



typedef struct add_event_notify_datas_t {
    list_t *add_event_notify_datas; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} add_event_notify_datas_t;

__attribute__((deprecated)) add_event_notify_datas_t *add_event_notify_datas_create(
    list_t *add_event_notify_datas
);

void add_event_notify_datas_free(add_event_notify_datas_t *add_event_notify_datas);

add_event_notify_datas_t *add_event_notify_datas_parseFromJSON(cJSON *add_event_notify_datasJSON);

cJSON *add_event_notify_datas_convertToJSON(add_event_notify_datas_t *add_event_notify_datas);

#endif /* _add_event_notify_datas_H_ */

