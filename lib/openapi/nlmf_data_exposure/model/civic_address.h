/*
 * civic_address.h
 *
 * Indicates a Civic address.
 */

#ifndef _civic_address_H_
#define _civic_address_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct civic_address_t civic_address_t;




typedef struct civic_address_t {
    char *country; // string
    char *a1; // string
    char *a2; // string
    char *a3; // string
    char *a4; // string
    char *a5; // string
    char *a6; // string
    char *prd; // string
    char *pod; // string
    char *sts; // string
    char *hno; // string
    char *hns; // string
    char *lmk; // string
    char *loc; // string
    char *nam; // string
    char *pc; // string
    char *bld; // string
    char *unit; // string
    char *flr; // string
    char *room; // string
    char *plc; // string
    char *pcn; // string
    char *pobox; // string
    char *addcode; // string
    char *seat; // string
    char *rd; // string
    char *rdsec; // string
    char *rdbr; // string
    char *rdsubbr; // string
    char *prm; // string
    char *pom; // string
    char *usage_rules; // string
    char *method; // string
    char *provided_by; // string

    int _library_owned; // Is the library responsible for freeing this object?
} civic_address_t;

__attribute__((deprecated)) civic_address_t *civic_address_create(
    char *country,
    char *a1,
    char *a2,
    char *a3,
    char *a4,
    char *a5,
    char *a6,
    char *prd,
    char *pod,
    char *sts,
    char *hno,
    char *hns,
    char *lmk,
    char *loc,
    char *nam,
    char *pc,
    char *bld,
    char *unit,
    char *flr,
    char *room,
    char *plc,
    char *pcn,
    char *pobox,
    char *addcode,
    char *seat,
    char *rd,
    char *rdsec,
    char *rdbr,
    char *rdsubbr,
    char *prm,
    char *pom,
    char *usage_rules,
    char *method,
    char *provided_by
);

void civic_address_free(civic_address_t *civic_address);

civic_address_t *civic_address_parseFromJSON(cJSON *civic_addressJSON);

cJSON *civic_address_convertToJSON(civic_address_t *civic_address);

#endif /* _civic_address_H_ */

