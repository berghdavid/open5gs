/*
 * global_ran_node_id.h
 *
 * One of the six attributes n3IwfId, gNbIdm, ngeNbId, wagfId, tngfId, eNbId shall be present. 
 */

#ifndef _global_ran_node_id_H_
#define _global_ran_node_id_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct global_ran_node_id_t global_ran_node_id_t;

#include "gnb_id.h"
#include "plmn_id.h"



typedef struct global_ran_node_id_t {
    struct plmn_id_t *plmn_id; //model
    char *n3_iwf_id; // string
    struct gnb_id_t *g_nb_id; //model
    char *nge_nb_id; // string
    char *wagf_id; // string
    char *tngf_id; // string
    char *nid; // string
    char *e_nb_id; // string

    int _library_owned; // Is the library responsible for freeing this object?
} global_ran_node_id_t;

__attribute__((deprecated)) global_ran_node_id_t *global_ran_node_id_create(
    plmn_id_t *plmn_id,
    char *n3_iwf_id,
    gnb_id_t *g_nb_id,
    char *nge_nb_id,
    char *wagf_id,
    char *tngf_id,
    char *nid,
    char *e_nb_id
);

void global_ran_node_id_free(global_ran_node_id_t *global_ran_node_id);

global_ran_node_id_t *global_ran_node_id_parseFromJSON(cJSON *global_ran_node_idJSON);

cJSON *global_ran_node_id_convertToJSON(global_ran_node_id_t *global_ran_node_id);

#endif /* _global_ran_node_id_H_ */

