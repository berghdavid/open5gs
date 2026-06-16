/*
 * trp_parameter.h
 *
 * The identifiers of TRPs if the network assisted positioning is used
 */

#ifndef _trp_parameter_H_
#define _trp_parameter_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct trp_parameter_t trp_parameter_t;

#include "global_ran_node_id.h"



typedef struct trp_parameter_t {
    list_t *trp_ids; //primitive container
    struct global_ran_node_id_t *global_gnb_id; //model

    int _library_owned; // Is the library responsible for freeing this object?
} trp_parameter_t;

__attribute__((deprecated)) trp_parameter_t *trp_parameter_create(
    list_t *trp_ids,
    global_ran_node_id_t *global_gnb_id
);

void trp_parameter_free(trp_parameter_t *trp_parameter);

trp_parameter_t *trp_parameter_parseFromJSON(cJSON *trp_parameterJSON);

cJSON *trp_parameter_convertToJSON(trp_parameter_t *trp_parameter);

#endif /* _trp_parameter_H_ */

