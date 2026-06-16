/*
 * time_windows_nrppa.h
 *
 * Time windows when network assisted positioning is used.
 */

#ifndef _time_windows_nrppa_H_
#define _time_windows_nrppa_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct time_windows_nrppa_t time_windows_nrppa_t;




typedef struct time_windows_nrppa_t {
    char *measurement_list; //ByteArray
    char *srs_list; //ByteArray

    int _library_owned; // Is the library responsible for freeing this object?
} time_windows_nrppa_t;

__attribute__((deprecated)) time_windows_nrppa_t *time_windows_nrppa_create(
    char *measurement_list,
    char *srs_list
);

void time_windows_nrppa_free(time_windows_nrppa_t *time_windows_nrppa);

time_windows_nrppa_t *time_windows_nrppa_parseFromJSON(cJSON *time_windows_nrppaJSON);

cJSON *time_windows_nrppa_convertToJSON(time_windows_nrppa_t *time_windows_nrppa);

#endif /* _time_windows_nrppa_H_ */

