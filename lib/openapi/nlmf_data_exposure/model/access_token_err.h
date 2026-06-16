/*
 * access_token_err.h
 *
 * Error returned in the access token response message
 */

#ifndef _access_token_err_H_
#define _access_token_err_H_

#include <string.h>
#include "../external/cJSON.h"
#include "../include/list.h"
#include "../include/keyValuePair.h"
#include "../include/binary.h"

typedef struct access_token_err_t access_token_err_t;


// Enum ERROR for access_token_err

typedef enum  { nlmf_dataexposure_access_token_err_ERROR_NULL = 0, nlmf_dataexposure_access_token_err_ERROR_invalid_request, nlmf_dataexposure_access_token_err_ERROR_invalid_client, nlmf_dataexposure_access_token_err_ERROR_invalid_grant, nlmf_dataexposure_access_token_err_ERROR_unauthorized_client, nlmf_dataexposure_access_token_err_ERROR_unsupported_grant_type, nlmf_dataexposure_access_token_err_ERROR_invalid_scope } nlmf_dataexposure_access_token_err_ERROR_e;

char* access_token_err_error_ToString(nlmf_dataexposure_access_token_err_ERROR_e error);

nlmf_dataexposure_access_token_err_ERROR_e access_token_err_error_FromString(char* error);



typedef struct access_token_err_t {
    nlmf_dataexposure_access_token_err_ERROR_e error; //enum
    char *error_description; // string
    char *error_uri; // string

    int _library_owned; // Is the library responsible for freeing this object?
} access_token_err_t;

__attribute__((deprecated)) access_token_err_t *access_token_err_create(
    nlmf_dataexposure_access_token_err_ERROR_e error,
    char *error_description,
    char *error_uri
);

void access_token_err_free(access_token_err_t *access_token_err);

access_token_err_t *access_token_err_parseFromJSON(cJSON *access_token_errJSON);

cJSON *access_token_err_convertToJSON(access_token_err_t *access_token_err);

#endif /* _access_token_err_H_ */

