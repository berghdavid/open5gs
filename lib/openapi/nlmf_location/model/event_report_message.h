/*
 * event_report_message.h
 *
 * Indicates an event report message.
 */

#ifndef _event_report_message_H_
#define _event_report_message_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct event_report_message_t event_report_message_t;

#include "event_class.h"
#include "ref_to_binary_data.h"



typedef struct event_report_message_t {
    struct event_class_t *event_class; //model
    struct ref_to_binary_data_t *event_content; //model

    int _library_owned; // Is the library responsible for freeing this object?
} event_report_message_t;

__attribute__((deprecated)) event_report_message_t *event_report_message_create(
    event_class_t *event_class,
    ref_to_binary_data_t *event_content
);

void event_report_message_free(event_report_message_t *event_report_message);

event_report_message_t *event_report_message_parseFromJSON(cJSON *event_report_messageJSON);

cJSON *event_report_message_convertToJSON(event_report_message_t *event_report_message);

#endif /* _event_report_message_H_ */

