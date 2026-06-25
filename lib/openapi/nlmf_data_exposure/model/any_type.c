#include <stdlib.h>
#include "any_type.h"

bool OpenAPI_IsInvalid(const any_type_t * const item)
{
    return item && cJSON_IsInvalid(item->json);
}
bool OpenAPI_IsFalse(const any_type_t * const item)
{
    return item && cJSON_IsFalse(item->json);
}
bool OpenAPI_IsTrue(const any_type_t * const item)
{
    return item && cJSON_IsTrue(item->json);
}
bool OpenAPI_IsBool(const any_type_t * const item)
{
    return item && cJSON_IsBool(item->json);
}
bool OpenAPI_IsNull(const any_type_t * const item)
{
    return item && cJSON_IsNull(item->json);
}
bool OpenAPI_IsNumber(const any_type_t * const item)
{
    return item && cJSON_IsNumber(item->json);
}
bool OpenAPI_IsString(const any_type_t * const item)
{
    return item && cJSON_IsString(item->json);
}
bool OpenAPI_IsArray(const any_type_t * const item)
{
    return item && cJSON_IsArray(item->json);
}
bool OpenAPI_IsObject(const any_type_t * const item)
{
    return item && cJSON_IsObject(item->json);
}
bool OpenAPI_IsRaw(const any_type_t * const item)
{
    return item && cJSON_IsRaw(item->json);
}

static any_type_t *any_create(cJSON *json) {
    any_type_t *any_type = NULL;

    if (!json) {
        return NULL;
    }

    any_type = calloc(1, sizeof(*any_type));
    if (!any_type) {
        cJSON_Delete(json);
    }
    any_type->json = json;

    return any_type;
}

any_type_t *OpenAPI_any_type_create(cJSON *json) {
    return any_create(cJSON_Duplicate(json, true));
}

any_type_t *OpenAPI_any_type_parseFromJSON(cJSON *json) {
    return OpenAPI_any_type_create(json);
}

cJSON *OpenAPI_any_type_convertToJSON(any_type_t *any_type) {
    cJSON *item = NULL;

    if (any_type == NULL) {
        return NULL;
    }

    item = cJSON_Duplicate(any_type->json, true);
    if (item == NULL) {
        return NULL;
    }

    return item;
}

any_type_t *OpenAPI_any_type_create_true(void)
{
    return OpenAPI_any_type_create_bool(true);
}

any_type_t *OpenAPI_any_type_create_false(void)
{
    return OpenAPI_any_type_create_bool(false);
}

any_type_t *OpenAPI_any_type_create_bool(bool boolean)
{
    return any_create(boolean ? cJSON_CreateTrue() : cJSON_CreateFalse());
}

any_type_t *OpenAPI_any_type_create_number(double num)
{
    return any_create(cJSON_CreateNumber(num));
}


any_type_t *OpenAPI_any_type_create_string(const char *string)
{
    return any_create(cJSON_CreateString(string));
}

void OpenAPI_any_type_free(any_type_t *any_type)
{
    if (any_type) {
        cJSON_Delete(any_type->json);
        free(any_type);
    }
}
