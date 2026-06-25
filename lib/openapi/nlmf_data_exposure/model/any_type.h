#ifndef ANY_TYPE_H
#define ANY_TYPE_H

#include <stdbool.h>
#include "../external/cJSON.h"

#ifdef __cplusplus
extern "C" {
#endif

#define OpenAPI_Invalid (0)
#define OpenAPI_False  (1 << 0)
#define OpenAPI_True   (1 << 1)
#define OpenAPI_NULL   (1 << 2)
#define OpenAPI_Number (1 << 3)
#define OpenAPI_String (1 << 4)
#define OpenAPI_Array  (1 << 5)
#define OpenAPI_Object (1 << 6)
#define OpenAPI_Raw    (1 << 7) /* raw json */

#define OpenAPI_IsReference 256
#define OpenAPI_StringIsConst 512

typedef struct any_type_s any_type_t;
typedef struct any_type_s {
    cJSON *json;
} any_type_t;
typedef any_type_t any_type_t;

bool OpenAPI_IsInvalid(const any_type_t * const item);
bool OpenAPI_IsFalse(const any_type_t * const item);
bool OpenAPI_IsTrue(const any_type_t * const item);
bool OpenAPI_IsBool(const any_type_t * const item);
bool OpenAPI_IsNull(const any_type_t * const item);
bool OpenAPI_IsNumber(const any_type_t * const item);
bool OpenAPI_IsString(const any_type_t * const item);
bool OpenAPI_IsArray(const any_type_t * const item);
bool OpenAPI_IsObject(const any_type_t * const item);
bool OpenAPI_IsRaw(const any_type_t * const item);

any_type_t *OpenAPI_any_type_create(cJSON *json);
any_type_t *OpenAPI_any_type_parseFromJSON(cJSON *json);
cJSON *OpenAPI_any_type_convertToJSON(any_type_t *any_type);

any_type_t *OpenAPI_any_type_create_true(void);
any_type_t *OpenAPI_any_type_create_false(void);
any_type_t *OpenAPI_any_type_create_bool(bool boolean);
any_type_t *OpenAPI_any_type_create_number(double num);
any_type_t *OpenAPI_any_type_create_string(const char *string);
void OpenAPI_any_type_free(any_type_t *any_type);

#ifdef __cplusplus
}
#endif

#endif /* ANY_TYPE_H */
