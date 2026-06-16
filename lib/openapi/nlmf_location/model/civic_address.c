#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "civic_address.h"



static civic_address_t *civic_address_create_internal(
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
    ) {
    civic_address_t *civic_address_local_var = malloc(sizeof(civic_address_t));
    if (!civic_address_local_var) {
        return NULL;
    }
    memset(civic_address_local_var, 0, sizeof(civic_address_t));
    civic_address_local_var->_library_owned = 1;
    civic_address_local_var->country = country;
    civic_address_local_var->a1 = a1;
    civic_address_local_var->a2 = a2;
    civic_address_local_var->a3 = a3;
    civic_address_local_var->a4 = a4;
    civic_address_local_var->a5 = a5;
    civic_address_local_var->a6 = a6;
    civic_address_local_var->prd = prd;
    civic_address_local_var->pod = pod;
    civic_address_local_var->sts = sts;
    civic_address_local_var->hno = hno;
    civic_address_local_var->hns = hns;
    civic_address_local_var->lmk = lmk;
    civic_address_local_var->loc = loc;
    civic_address_local_var->nam = nam;
    civic_address_local_var->pc = pc;
    civic_address_local_var->bld = bld;
    civic_address_local_var->unit = unit;
    civic_address_local_var->flr = flr;
    civic_address_local_var->room = room;
    civic_address_local_var->plc = plc;
    civic_address_local_var->pcn = pcn;
    civic_address_local_var->pobox = pobox;
    civic_address_local_var->addcode = addcode;
    civic_address_local_var->seat = seat;
    civic_address_local_var->rd = rd;
    civic_address_local_var->rdsec = rdsec;
    civic_address_local_var->rdbr = rdbr;
    civic_address_local_var->rdsubbr = rdsubbr;
    civic_address_local_var->prm = prm;
    civic_address_local_var->pom = pom;
    civic_address_local_var->usage_rules = usage_rules;
    civic_address_local_var->method = method;
    civic_address_local_var->provided_by = provided_by;
    return civic_address_local_var;
}

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
    ) {
    civic_address_t *result = civic_address_create_internal (
        country,
        a1,
        a2,
        a3,
        a4,
        a5,
        a6,
        prd,
        pod,
        sts,
        hno,
        hns,
        lmk,
        loc,
        nam,
        pc,
        bld,
        unit,
        flr,
        room,
        plc,
        pcn,
        pobox,
        addcode,
        seat,
        rd,
        rdsec,
        rdbr,
        rdsubbr,
        prm,
        pom,
        usage_rules,
        method,
        provided_by
        );
    if (!result) {
    }
    return result;
}

void civic_address_free(civic_address_t *civic_address) {
    if(NULL == civic_address){
        return ;
    }
    if(civic_address->_library_owned != 1){
        fprintf(stderr, "WARNING: %s() does NOT free objects allocated by the user\n", "civic_address_free");
        return ;
    }
    listEntry_t *listEntry;
    if (civic_address->country) {
        free(civic_address->country);
        civic_address->country = NULL;
    }
    if (civic_address->a1) {
        free(civic_address->a1);
        civic_address->a1 = NULL;
    }
    if (civic_address->a2) {
        free(civic_address->a2);
        civic_address->a2 = NULL;
    }
    if (civic_address->a3) {
        free(civic_address->a3);
        civic_address->a3 = NULL;
    }
    if (civic_address->a4) {
        free(civic_address->a4);
        civic_address->a4 = NULL;
    }
    if (civic_address->a5) {
        free(civic_address->a5);
        civic_address->a5 = NULL;
    }
    if (civic_address->a6) {
        free(civic_address->a6);
        civic_address->a6 = NULL;
    }
    if (civic_address->prd) {
        free(civic_address->prd);
        civic_address->prd = NULL;
    }
    if (civic_address->pod) {
        free(civic_address->pod);
        civic_address->pod = NULL;
    }
    if (civic_address->sts) {
        free(civic_address->sts);
        civic_address->sts = NULL;
    }
    if (civic_address->hno) {
        free(civic_address->hno);
        civic_address->hno = NULL;
    }
    if (civic_address->hns) {
        free(civic_address->hns);
        civic_address->hns = NULL;
    }
    if (civic_address->lmk) {
        free(civic_address->lmk);
        civic_address->lmk = NULL;
    }
    if (civic_address->loc) {
        free(civic_address->loc);
        civic_address->loc = NULL;
    }
    if (civic_address->nam) {
        free(civic_address->nam);
        civic_address->nam = NULL;
    }
    if (civic_address->pc) {
        free(civic_address->pc);
        civic_address->pc = NULL;
    }
    if (civic_address->bld) {
        free(civic_address->bld);
        civic_address->bld = NULL;
    }
    if (civic_address->unit) {
        free(civic_address->unit);
        civic_address->unit = NULL;
    }
    if (civic_address->flr) {
        free(civic_address->flr);
        civic_address->flr = NULL;
    }
    if (civic_address->room) {
        free(civic_address->room);
        civic_address->room = NULL;
    }
    if (civic_address->plc) {
        free(civic_address->plc);
        civic_address->plc = NULL;
    }
    if (civic_address->pcn) {
        free(civic_address->pcn);
        civic_address->pcn = NULL;
    }
    if (civic_address->pobox) {
        free(civic_address->pobox);
        civic_address->pobox = NULL;
    }
    if (civic_address->addcode) {
        free(civic_address->addcode);
        civic_address->addcode = NULL;
    }
    if (civic_address->seat) {
        free(civic_address->seat);
        civic_address->seat = NULL;
    }
    if (civic_address->rd) {
        free(civic_address->rd);
        civic_address->rd = NULL;
    }
    if (civic_address->rdsec) {
        free(civic_address->rdsec);
        civic_address->rdsec = NULL;
    }
    if (civic_address->rdbr) {
        free(civic_address->rdbr);
        civic_address->rdbr = NULL;
    }
    if (civic_address->rdsubbr) {
        free(civic_address->rdsubbr);
        civic_address->rdsubbr = NULL;
    }
    if (civic_address->prm) {
        free(civic_address->prm);
        civic_address->prm = NULL;
    }
    if (civic_address->pom) {
        free(civic_address->pom);
        civic_address->pom = NULL;
    }
    if (civic_address->usage_rules) {
        free(civic_address->usage_rules);
        civic_address->usage_rules = NULL;
    }
    if (civic_address->method) {
        free(civic_address->method);
        civic_address->method = NULL;
    }
    if (civic_address->provided_by) {
        free(civic_address->provided_by);
        civic_address->provided_by = NULL;
    }
    free(civic_address);
}

cJSON *civic_address_convertToJSON(civic_address_t *civic_address) {
    cJSON *item = cJSON_CreateObject();

    // civic_address->country
    if(civic_address->country) {
    if(cJSON_AddStringToObject(item, "country", civic_address->country) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->a1
    if(civic_address->a1) {
    if(cJSON_AddStringToObject(item, "A1", civic_address->a1) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->a2
    if(civic_address->a2) {
    if(cJSON_AddStringToObject(item, "A2", civic_address->a2) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->a3
    if(civic_address->a3) {
    if(cJSON_AddStringToObject(item, "A3", civic_address->a3) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->a4
    if(civic_address->a4) {
    if(cJSON_AddStringToObject(item, "A4", civic_address->a4) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->a5
    if(civic_address->a5) {
    if(cJSON_AddStringToObject(item, "A5", civic_address->a5) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->a6
    if(civic_address->a6) {
    if(cJSON_AddStringToObject(item, "A6", civic_address->a6) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->prd
    if(civic_address->prd) {
    if(cJSON_AddStringToObject(item, "PRD", civic_address->prd) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->pod
    if(civic_address->pod) {
    if(cJSON_AddStringToObject(item, "POD", civic_address->pod) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->sts
    if(civic_address->sts) {
    if(cJSON_AddStringToObject(item, "STS", civic_address->sts) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->hno
    if(civic_address->hno) {
    if(cJSON_AddStringToObject(item, "HNO", civic_address->hno) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->hns
    if(civic_address->hns) {
    if(cJSON_AddStringToObject(item, "HNS", civic_address->hns) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->lmk
    if(civic_address->lmk) {
    if(cJSON_AddStringToObject(item, "LMK", civic_address->lmk) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->loc
    if(civic_address->loc) {
    if(cJSON_AddStringToObject(item, "LOC", civic_address->loc) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->nam
    if(civic_address->nam) {
    if(cJSON_AddStringToObject(item, "NAM", civic_address->nam) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->pc
    if(civic_address->pc) {
    if(cJSON_AddStringToObject(item, "PC", civic_address->pc) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->bld
    if(civic_address->bld) {
    if(cJSON_AddStringToObject(item, "BLD", civic_address->bld) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->unit
    if(civic_address->unit) {
    if(cJSON_AddStringToObject(item, "UNIT", civic_address->unit) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->flr
    if(civic_address->flr) {
    if(cJSON_AddStringToObject(item, "FLR", civic_address->flr) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->room
    if(civic_address->room) {
    if(cJSON_AddStringToObject(item, "ROOM", civic_address->room) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->plc
    if(civic_address->plc) {
    if(cJSON_AddStringToObject(item, "PLC", civic_address->plc) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->pcn
    if(civic_address->pcn) {
    if(cJSON_AddStringToObject(item, "PCN", civic_address->pcn) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->pobox
    if(civic_address->pobox) {
    if(cJSON_AddStringToObject(item, "POBOX", civic_address->pobox) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->addcode
    if(civic_address->addcode) {
    if(cJSON_AddStringToObject(item, "ADDCODE", civic_address->addcode) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->seat
    if(civic_address->seat) {
    if(cJSON_AddStringToObject(item, "SEAT", civic_address->seat) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->rd
    if(civic_address->rd) {
    if(cJSON_AddStringToObject(item, "RD", civic_address->rd) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->rdsec
    if(civic_address->rdsec) {
    if(cJSON_AddStringToObject(item, "RDSEC", civic_address->rdsec) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->rdbr
    if(civic_address->rdbr) {
    if(cJSON_AddStringToObject(item, "RDBR", civic_address->rdbr) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->rdsubbr
    if(civic_address->rdsubbr) {
    if(cJSON_AddStringToObject(item, "RDSUBBR", civic_address->rdsubbr) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->prm
    if(civic_address->prm) {
    if(cJSON_AddStringToObject(item, "PRM", civic_address->prm) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->pom
    if(civic_address->pom) {
    if(cJSON_AddStringToObject(item, "POM", civic_address->pom) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->usage_rules
    if(civic_address->usage_rules) {
    if(cJSON_AddStringToObject(item, "usageRules", civic_address->usage_rules) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->method
    if(civic_address->method) {
    if(cJSON_AddStringToObject(item, "method", civic_address->method) == NULL) {
    goto fail; //String
    }
    }


    // civic_address->provided_by
    if(civic_address->provided_by) {
    if(cJSON_AddStringToObject(item, "providedBy", civic_address->provided_by) == NULL) {
    goto fail; //String
    }
    }

    return item;
fail:
    if (item) {
        cJSON_Delete(item);
    }
    return NULL;
}

civic_address_t *civic_address_parseFromJSON(cJSON *civic_addressJSON){

    civic_address_t *civic_address_local_var = NULL;

    char *country_local_str = NULL;

    char *a1_local_str = NULL;

    char *a2_local_str = NULL;

    char *a3_local_str = NULL;

    char *a4_local_str = NULL;

    char *a5_local_str = NULL;

    char *a6_local_str = NULL;

    char *prd_local_str = NULL;

    char *pod_local_str = NULL;

    char *sts_local_str = NULL;

    char *hno_local_str = NULL;

    char *hns_local_str = NULL;

    char *lmk_local_str = NULL;

    char *loc_local_str = NULL;

    char *nam_local_str = NULL;

    char *pc_local_str = NULL;

    char *bld_local_str = NULL;

    char *unit_local_str = NULL;

    char *flr_local_str = NULL;

    char *room_local_str = NULL;

    char *plc_local_str = NULL;

    char *pcn_local_str = NULL;

    char *pobox_local_str = NULL;

    char *addcode_local_str = NULL;

    char *seat_local_str = NULL;

    char *rd_local_str = NULL;

    char *rdsec_local_str = NULL;

    char *rdbr_local_str = NULL;

    char *rdsubbr_local_str = NULL;

    char *prm_local_str = NULL;

    char *pom_local_str = NULL;

    char *usage_rules_local_str = NULL;

    char *method_local_str = NULL;

    char *provided_by_local_str = NULL;

    // civic_address->country
    cJSON *country = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "country");
    if (cJSON_IsNull(country)) {
        country = NULL;
    }
    if (country) { 
    if(!cJSON_IsString(country) && !cJSON_IsNull(country))
    {
    goto end; //String
    }
    }

    // civic_address->a1
    cJSON *a1 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A1");
    if (cJSON_IsNull(a1)) {
        a1 = NULL;
    }
    if (a1) { 
    if(!cJSON_IsString(a1) && !cJSON_IsNull(a1))
    {
    goto end; //String
    }
    }

    // civic_address->a2
    cJSON *a2 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A2");
    if (cJSON_IsNull(a2)) {
        a2 = NULL;
    }
    if (a2) { 
    if(!cJSON_IsString(a2) && !cJSON_IsNull(a2))
    {
    goto end; //String
    }
    }

    // civic_address->a3
    cJSON *a3 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A3");
    if (cJSON_IsNull(a3)) {
        a3 = NULL;
    }
    if (a3) { 
    if(!cJSON_IsString(a3) && !cJSON_IsNull(a3))
    {
    goto end; //String
    }
    }

    // civic_address->a4
    cJSON *a4 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A4");
    if (cJSON_IsNull(a4)) {
        a4 = NULL;
    }
    if (a4) { 
    if(!cJSON_IsString(a4) && !cJSON_IsNull(a4))
    {
    goto end; //String
    }
    }

    // civic_address->a5
    cJSON *a5 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A5");
    if (cJSON_IsNull(a5)) {
        a5 = NULL;
    }
    if (a5) { 
    if(!cJSON_IsString(a5) && !cJSON_IsNull(a5))
    {
    goto end; //String
    }
    }

    // civic_address->a6
    cJSON *a6 = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "A6");
    if (cJSON_IsNull(a6)) {
        a6 = NULL;
    }
    if (a6) { 
    if(!cJSON_IsString(a6) && !cJSON_IsNull(a6))
    {
    goto end; //String
    }
    }

    // civic_address->prd
    cJSON *prd = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PRD");
    if (cJSON_IsNull(prd)) {
        prd = NULL;
    }
    if (prd) { 
    if(!cJSON_IsString(prd) && !cJSON_IsNull(prd))
    {
    goto end; //String
    }
    }

    // civic_address->pod
    cJSON *pod = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "POD");
    if (cJSON_IsNull(pod)) {
        pod = NULL;
    }
    if (pod) { 
    if(!cJSON_IsString(pod) && !cJSON_IsNull(pod))
    {
    goto end; //String
    }
    }

    // civic_address->sts
    cJSON *sts = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "STS");
    if (cJSON_IsNull(sts)) {
        sts = NULL;
    }
    if (sts) { 
    if(!cJSON_IsString(sts) && !cJSON_IsNull(sts))
    {
    goto end; //String
    }
    }

    // civic_address->hno
    cJSON *hno = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "HNO");
    if (cJSON_IsNull(hno)) {
        hno = NULL;
    }
    if (hno) { 
    if(!cJSON_IsString(hno) && !cJSON_IsNull(hno))
    {
    goto end; //String
    }
    }

    // civic_address->hns
    cJSON *hns = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "HNS");
    if (cJSON_IsNull(hns)) {
        hns = NULL;
    }
    if (hns) { 
    if(!cJSON_IsString(hns) && !cJSON_IsNull(hns))
    {
    goto end; //String
    }
    }

    // civic_address->lmk
    cJSON *lmk = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "LMK");
    if (cJSON_IsNull(lmk)) {
        lmk = NULL;
    }
    if (lmk) { 
    if(!cJSON_IsString(lmk) && !cJSON_IsNull(lmk))
    {
    goto end; //String
    }
    }

    // civic_address->loc
    cJSON *loc = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "LOC");
    if (cJSON_IsNull(loc)) {
        loc = NULL;
    }
    if (loc) { 
    if(!cJSON_IsString(loc) && !cJSON_IsNull(loc))
    {
    goto end; //String
    }
    }

    // civic_address->nam
    cJSON *nam = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "NAM");
    if (cJSON_IsNull(nam)) {
        nam = NULL;
    }
    if (nam) { 
    if(!cJSON_IsString(nam) && !cJSON_IsNull(nam))
    {
    goto end; //String
    }
    }

    // civic_address->pc
    cJSON *pc = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PC");
    if (cJSON_IsNull(pc)) {
        pc = NULL;
    }
    if (pc) { 
    if(!cJSON_IsString(pc) && !cJSON_IsNull(pc))
    {
    goto end; //String
    }
    }

    // civic_address->bld
    cJSON *bld = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "BLD");
    if (cJSON_IsNull(bld)) {
        bld = NULL;
    }
    if (bld) { 
    if(!cJSON_IsString(bld) && !cJSON_IsNull(bld))
    {
    goto end; //String
    }
    }

    // civic_address->unit
    cJSON *unit = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "UNIT");
    if (cJSON_IsNull(unit)) {
        unit = NULL;
    }
    if (unit) { 
    if(!cJSON_IsString(unit) && !cJSON_IsNull(unit))
    {
    goto end; //String
    }
    }

    // civic_address->flr
    cJSON *flr = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "FLR");
    if (cJSON_IsNull(flr)) {
        flr = NULL;
    }
    if (flr) { 
    if(!cJSON_IsString(flr) && !cJSON_IsNull(flr))
    {
    goto end; //String
    }
    }

    // civic_address->room
    cJSON *room = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "ROOM");
    if (cJSON_IsNull(room)) {
        room = NULL;
    }
    if (room) { 
    if(!cJSON_IsString(room) && !cJSON_IsNull(room))
    {
    goto end; //String
    }
    }

    // civic_address->plc
    cJSON *plc = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PLC");
    if (cJSON_IsNull(plc)) {
        plc = NULL;
    }
    if (plc) { 
    if(!cJSON_IsString(plc) && !cJSON_IsNull(plc))
    {
    goto end; //String
    }
    }

    // civic_address->pcn
    cJSON *pcn = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PCN");
    if (cJSON_IsNull(pcn)) {
        pcn = NULL;
    }
    if (pcn) { 
    if(!cJSON_IsString(pcn) && !cJSON_IsNull(pcn))
    {
    goto end; //String
    }
    }

    // civic_address->pobox
    cJSON *pobox = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "POBOX");
    if (cJSON_IsNull(pobox)) {
        pobox = NULL;
    }
    if (pobox) { 
    if(!cJSON_IsString(pobox) && !cJSON_IsNull(pobox))
    {
    goto end; //String
    }
    }

    // civic_address->addcode
    cJSON *addcode = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "ADDCODE");
    if (cJSON_IsNull(addcode)) {
        addcode = NULL;
    }
    if (addcode) { 
    if(!cJSON_IsString(addcode) && !cJSON_IsNull(addcode))
    {
    goto end; //String
    }
    }

    // civic_address->seat
    cJSON *seat = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "SEAT");
    if (cJSON_IsNull(seat)) {
        seat = NULL;
    }
    if (seat) { 
    if(!cJSON_IsString(seat) && !cJSON_IsNull(seat))
    {
    goto end; //String
    }
    }

    // civic_address->rd
    cJSON *rd = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "RD");
    if (cJSON_IsNull(rd)) {
        rd = NULL;
    }
    if (rd) { 
    if(!cJSON_IsString(rd) && !cJSON_IsNull(rd))
    {
    goto end; //String
    }
    }

    // civic_address->rdsec
    cJSON *rdsec = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "RDSEC");
    if (cJSON_IsNull(rdsec)) {
        rdsec = NULL;
    }
    if (rdsec) { 
    if(!cJSON_IsString(rdsec) && !cJSON_IsNull(rdsec))
    {
    goto end; //String
    }
    }

    // civic_address->rdbr
    cJSON *rdbr = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "RDBR");
    if (cJSON_IsNull(rdbr)) {
        rdbr = NULL;
    }
    if (rdbr) { 
    if(!cJSON_IsString(rdbr) && !cJSON_IsNull(rdbr))
    {
    goto end; //String
    }
    }

    // civic_address->rdsubbr
    cJSON *rdsubbr = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "RDSUBBR");
    if (cJSON_IsNull(rdsubbr)) {
        rdsubbr = NULL;
    }
    if (rdsubbr) { 
    if(!cJSON_IsString(rdsubbr) && !cJSON_IsNull(rdsubbr))
    {
    goto end; //String
    }
    }

    // civic_address->prm
    cJSON *prm = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "PRM");
    if (cJSON_IsNull(prm)) {
        prm = NULL;
    }
    if (prm) { 
    if(!cJSON_IsString(prm) && !cJSON_IsNull(prm))
    {
    goto end; //String
    }
    }

    // civic_address->pom
    cJSON *pom = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "POM");
    if (cJSON_IsNull(pom)) {
        pom = NULL;
    }
    if (pom) { 
    if(!cJSON_IsString(pom) && !cJSON_IsNull(pom))
    {
    goto end; //String
    }
    }

    // civic_address->usage_rules
    cJSON *usage_rules = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "usageRules");
    if (cJSON_IsNull(usage_rules)) {
        usage_rules = NULL;
    }
    if (usage_rules) { 
    if(!cJSON_IsString(usage_rules) && !cJSON_IsNull(usage_rules))
    {
    goto end; //String
    }
    }

    // civic_address->method
    cJSON *method = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "method");
    if (cJSON_IsNull(method)) {
        method = NULL;
    }
    if (method) { 
    if(!cJSON_IsString(method) && !cJSON_IsNull(method))
    {
    goto end; //String
    }
    }

    // civic_address->provided_by
    cJSON *provided_by = cJSON_GetObjectItemCaseSensitive(civic_addressJSON, "providedBy");
    if (cJSON_IsNull(provided_by)) {
        provided_by = NULL;
    }
    if (provided_by) { 
    if(!cJSON_IsString(provided_by) && !cJSON_IsNull(provided_by))
    {
    goto end; //String
    }
    }


    if (country && !cJSON_IsNull(country)) country_local_str = strdup(country->valuestring);
    if (a1 && !cJSON_IsNull(a1)) a1_local_str = strdup(a1->valuestring);
    if (a2 && !cJSON_IsNull(a2)) a2_local_str = strdup(a2->valuestring);
    if (a3 && !cJSON_IsNull(a3)) a3_local_str = strdup(a3->valuestring);
    if (a4 && !cJSON_IsNull(a4)) a4_local_str = strdup(a4->valuestring);
    if (a5 && !cJSON_IsNull(a5)) a5_local_str = strdup(a5->valuestring);
    if (a6 && !cJSON_IsNull(a6)) a6_local_str = strdup(a6->valuestring);
    if (prd && !cJSON_IsNull(prd)) prd_local_str = strdup(prd->valuestring);
    if (pod && !cJSON_IsNull(pod)) pod_local_str = strdup(pod->valuestring);
    if (sts && !cJSON_IsNull(sts)) sts_local_str = strdup(sts->valuestring);
    if (hno && !cJSON_IsNull(hno)) hno_local_str = strdup(hno->valuestring);
    if (hns && !cJSON_IsNull(hns)) hns_local_str = strdup(hns->valuestring);
    if (lmk && !cJSON_IsNull(lmk)) lmk_local_str = strdup(lmk->valuestring);
    if (loc && !cJSON_IsNull(loc)) loc_local_str = strdup(loc->valuestring);
    if (nam && !cJSON_IsNull(nam)) nam_local_str = strdup(nam->valuestring);
    if (pc && !cJSON_IsNull(pc)) pc_local_str = strdup(pc->valuestring);
    if (bld && !cJSON_IsNull(bld)) bld_local_str = strdup(bld->valuestring);
    if (unit && !cJSON_IsNull(unit)) unit_local_str = strdup(unit->valuestring);
    if (flr && !cJSON_IsNull(flr)) flr_local_str = strdup(flr->valuestring);
    if (room && !cJSON_IsNull(room)) room_local_str = strdup(room->valuestring);
    if (plc && !cJSON_IsNull(plc)) plc_local_str = strdup(plc->valuestring);
    if (pcn && !cJSON_IsNull(pcn)) pcn_local_str = strdup(pcn->valuestring);
    if (pobox && !cJSON_IsNull(pobox)) pobox_local_str = strdup(pobox->valuestring);
    if (addcode && !cJSON_IsNull(addcode)) addcode_local_str = strdup(addcode->valuestring);
    if (seat && !cJSON_IsNull(seat)) seat_local_str = strdup(seat->valuestring);
    if (rd && !cJSON_IsNull(rd)) rd_local_str = strdup(rd->valuestring);
    if (rdsec && !cJSON_IsNull(rdsec)) rdsec_local_str = strdup(rdsec->valuestring);
    if (rdbr && !cJSON_IsNull(rdbr)) rdbr_local_str = strdup(rdbr->valuestring);
    if (rdsubbr && !cJSON_IsNull(rdsubbr)) rdsubbr_local_str = strdup(rdsubbr->valuestring);
    if (prm && !cJSON_IsNull(prm)) prm_local_str = strdup(prm->valuestring);
    if (pom && !cJSON_IsNull(pom)) pom_local_str = strdup(pom->valuestring);
    if (usage_rules && !cJSON_IsNull(usage_rules)) usage_rules_local_str = strdup(usage_rules->valuestring);
    if (method && !cJSON_IsNull(method)) method_local_str = strdup(method->valuestring);
    if (provided_by && !cJSON_IsNull(provided_by)) provided_by_local_str = strdup(provided_by->valuestring);

    civic_address_local_var = civic_address_create_internal (
        country_local_str,
        a1_local_str,
        a2_local_str,
        a3_local_str,
        a4_local_str,
        a5_local_str,
        a6_local_str,
        prd_local_str,
        pod_local_str,
        sts_local_str,
        hno_local_str,
        hns_local_str,
        lmk_local_str,
        loc_local_str,
        nam_local_str,
        pc_local_str,
        bld_local_str,
        unit_local_str,
        flr_local_str,
        room_local_str,
        plc_local_str,
        pcn_local_str,
        pobox_local_str,
        addcode_local_str,
        seat_local_str,
        rd_local_str,
        rdsec_local_str,
        rdbr_local_str,
        rdsubbr_local_str,
        prm_local_str,
        pom_local_str,
        usage_rules_local_str,
        method_local_str,
        provided_by_local_str
        );

    if (!civic_address_local_var) {
        goto end;
    }

    return civic_address_local_var;
end:
    if (country_local_str) {
        free(country_local_str);
        country_local_str = NULL;
    }
    if (a1_local_str) {
        free(a1_local_str);
        a1_local_str = NULL;
    }
    if (a2_local_str) {
        free(a2_local_str);
        a2_local_str = NULL;
    }
    if (a3_local_str) {
        free(a3_local_str);
        a3_local_str = NULL;
    }
    if (a4_local_str) {
        free(a4_local_str);
        a4_local_str = NULL;
    }
    if (a5_local_str) {
        free(a5_local_str);
        a5_local_str = NULL;
    }
    if (a6_local_str) {
        free(a6_local_str);
        a6_local_str = NULL;
    }
    if (prd_local_str) {
        free(prd_local_str);
        prd_local_str = NULL;
    }
    if (pod_local_str) {
        free(pod_local_str);
        pod_local_str = NULL;
    }
    if (sts_local_str) {
        free(sts_local_str);
        sts_local_str = NULL;
    }
    if (hno_local_str) {
        free(hno_local_str);
        hno_local_str = NULL;
    }
    if (hns_local_str) {
        free(hns_local_str);
        hns_local_str = NULL;
    }
    if (lmk_local_str) {
        free(lmk_local_str);
        lmk_local_str = NULL;
    }
    if (loc_local_str) {
        free(loc_local_str);
        loc_local_str = NULL;
    }
    if (nam_local_str) {
        free(nam_local_str);
        nam_local_str = NULL;
    }
    if (pc_local_str) {
        free(pc_local_str);
        pc_local_str = NULL;
    }
    if (bld_local_str) {
        free(bld_local_str);
        bld_local_str = NULL;
    }
    if (unit_local_str) {
        free(unit_local_str);
        unit_local_str = NULL;
    }
    if (flr_local_str) {
        free(flr_local_str);
        flr_local_str = NULL;
    }
    if (room_local_str) {
        free(room_local_str);
        room_local_str = NULL;
    }
    if (plc_local_str) {
        free(plc_local_str);
        plc_local_str = NULL;
    }
    if (pcn_local_str) {
        free(pcn_local_str);
        pcn_local_str = NULL;
    }
    if (pobox_local_str) {
        free(pobox_local_str);
        pobox_local_str = NULL;
    }
    if (addcode_local_str) {
        free(addcode_local_str);
        addcode_local_str = NULL;
    }
    if (seat_local_str) {
        free(seat_local_str);
        seat_local_str = NULL;
    }
    if (rd_local_str) {
        free(rd_local_str);
        rd_local_str = NULL;
    }
    if (rdsec_local_str) {
        free(rdsec_local_str);
        rdsec_local_str = NULL;
    }
    if (rdbr_local_str) {
        free(rdbr_local_str);
        rdbr_local_str = NULL;
    }
    if (rdsubbr_local_str) {
        free(rdsubbr_local_str);
        rdsubbr_local_str = NULL;
    }
    if (prm_local_str) {
        free(prm_local_str);
        prm_local_str = NULL;
    }
    if (pom_local_str) {
        free(pom_local_str);
        pom_local_str = NULL;
    }
    if (usage_rules_local_str) {
        free(usage_rules_local_str);
        usage_rules_local_str = NULL;
    }
    if (method_local_str) {
        free(method_local_str);
        method_local_str = NULL;
    }
    if (provided_by_local_str) {
        free(provided_by_local_str);
        provided_by_local_str = NULL;
    }
    return NULL;

}
