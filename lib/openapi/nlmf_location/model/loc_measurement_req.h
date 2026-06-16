/*
 * loc_measurement_req.h
 *
 * Location Measurement Request.
 */

#ifndef _loc_measurement_req_H_
#define _loc_measurement_req_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct loc_measurement_req_t loc_measurement_req_t;

#include "ecgi.h"
#include "geographic_area.h"
#include "ncgi.h"
#include "positioning_method.h"
#include "time_windows_nrppa.h"
#include "trp_parameter.h"



typedef struct loc_measurement_req_t {
    struct ncgi_t *ncgi; //model
    struct ecgi_t *ecgi; //model
    struct geographic_area_t *pre_calcu_loc_estimate; //model
    char *timestamp_of_pre_calcu_loc_estimate; //date time
    list_t *time_windows; //primitive container
    struct time_windows_nrppa_t *time_windows_nrppa; //model
    struct positioning_method_t *method; //model
    list_t *trp_parameters; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} loc_measurement_req_t;

__attribute__((deprecated)) loc_measurement_req_t *loc_measurement_req_create(
    ncgi_t *ncgi,
    ecgi_t *ecgi,
    geographic_area_t *pre_calcu_loc_estimate,
    char *timestamp_of_pre_calcu_loc_estimate,
    list_t *time_windows,
    time_windows_nrppa_t *time_windows_nrppa,
    positioning_method_t *method,
    list_t *trp_parameters
);

void loc_measurement_req_free(loc_measurement_req_t *loc_measurement_req);

loc_measurement_req_t *loc_measurement_req_parseFromJSON(cJSON *loc_measurement_reqJSON);

cJSON *loc_measurement_req_convertToJSON(loc_measurement_req_t *loc_measurement_req);

#endif /* _loc_measurement_req_H_ */

