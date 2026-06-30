
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "links.h"

cJSON *ogs_sbi_links_convertToJSON(ogs_sbi_links_t *links)
{
    cJSON *root = NULL;
    cJSON *object = NULL;

    cJSON *linksJSON = NULL;
    cJSON *itemsJSON = NULL;
    cJSON *selfJSON = NULL;

    OpenAPI_lnode_t *node;

    log_assert(links);

    /* _links.items */
    itemsJSON = cJSON_CreateArray();
    log_assert(itemsJSON);

    OpenAPI_list_for_each(links->items, node) {
        if (!node->data) continue;

        object = cJSON_CreateObject();
        log_assert(object);

        cJSON_AddItemToObject(object, "href", cJSON_CreateString(node->data));
        cJSON_AddItemToArray(itemsJSON, object);
    }

    /* _links.self */
    selfJSON = cJSON_CreateObject();
    log_assert(selfJSON);

    log_assert(links->self);
    object = cJSON_CreateString(links->self);
    log_assert(object);

    cJSON_AddItemToObject(selfJSON, "href", object);

    /* _links */
    linksJSON = cJSON_CreateObject();
    log_assert(linksJSON);

    cJSON_AddItemToObject(linksJSON, "item", itemsJSON);
    cJSON_AddItemToObject(linksJSON, "self", selfJSON);
    cJSON_AddNumberToObject(linksJSON, "totalItemCount", cJSON_GetArraySize(itemsJSON));

    /* root */
    root = cJSON_CreateObject();
    log_assert(root);

    cJSON_AddItemToObject(root, "_links", linksJSON);

    return root;
}

ogs_sbi_links_t *ogs_sbi_links_parseFromJSON(cJSON *json)
{
    ogs_sbi_links_t *links;
    cJSON *_links = NULL;
    cJSON *_items = NULL, *_item = NULL;
    cJSON *_self = NULL;

    log_assert(json);

    _links = cJSON_GetObjectItemCaseSensitive(json, "_links");
    if (!_links) {
        log_error("No _links");
        return NULL;
    }

    _items = cJSON_GetObjectItemCaseSensitive(_links, "item");
    if (!_items) {
        log_error("No item");
        return NULL;
    }


    links = ogs_malloc(sizeof(ogs_sbi_links_t));
    log_assert(links);

    memset(links, 0, sizeof(*links));
    links->items = OpenAPI_list_create();
    log_assert(links->items);


    cJSON_ArrayForEach(_item, _items) {
        cJSON *href;
        char *link;

        href = cJSON_GetObjectItemCaseSensitive(_item, "href");
        if (href) {
            link = cJSON_GetStringValue(href);
            OpenAPI_list_add(links->items, ogs_strdup(link));
        }
    }


    _self = cJSON_GetObjectItemCaseSensitive(_links, "self");
    if (_self) {
        cJSON *self_href;

        self_href = cJSON_GetObjectItemCaseSensitive(_self, "href");
        if (self_href)
            links->self = ogs_strdup(cJSON_GetStringValue(self_href));
    }

    return links;
}
