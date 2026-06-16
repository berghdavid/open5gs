/*
 * presence_info.h
 *
 * If the additionalPraId IE is present, this IE shall state the presence information of the UE for the individual PRA identified by the additionalPraId IE;  If the additionalPraId IE is not present, this IE shall state the presence information of the UE for the PRA identified by the praId IE. 
 */

#ifndef _presence_info_H_
#define _presence_info_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct presence_info_t presence_info_t;

#include "ecgi.h"
#include "global_ran_node_id.h"
#include "ncgi.h"
#include "presence_state.h"
#include "tai.h"



typedef struct presence_info_t {
    char *pra_id; // string
    char *additional_pra_id; // string
    struct presence_state_t *presence_state; //model
    list_t *tracking_area_list; //nonprimitive container
    list_t *ecgi_list; //nonprimitive container
    list_t *ncgi_list; //nonprimitive container
    list_t *global_ran_node_id_list; //nonprimitive container
    list_t *globale_nb_id_list; //nonprimitive container

    int _library_owned; // Is the library responsible for freeing this object?
} presence_info_t;

__attribute__((deprecated)) presence_info_t *presence_info_create(
    char *pra_id,
    char *additional_pra_id,
    presence_state_t *presence_state,
    list_t *tracking_area_list,
    list_t *ecgi_list,
    list_t *ncgi_list,
    list_t *global_ran_node_id_list,
    list_t *globale_nb_id_list
);

void presence_info_free(presence_info_t *presence_info);

presence_info_t *presence_info_parseFromJSON(cJSON *presence_infoJSON);

cJSON *presence_info_convertToJSON(presence_info_t *presence_info);

#endif /* _presence_info_H_ */

