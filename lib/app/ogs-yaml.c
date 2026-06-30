/*
 * Copyright (C) 2019-2023 by Sukchan Lee <acetcom@gmail.com>
 *
 * This file is part of Open5GS.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#include "ogs-app.h"

void ogs_yaml_iter_init(ogs_yaml_iter_t *iter, yaml_document_t *document)
{
    log_assert(iter);
    log_assert(document);

    memset(iter, 0, sizeof(ogs_yaml_iter_t));

    iter->document = document;
    iter->node = yaml_document_get_root_node(document);

    log_assert(iter->node);
    if (iter->node->type == YAML_MAPPING_NODE)
        iter->pair = iter->node->data.mapping.pairs.start - 1;
    else if (iter->node->type == YAML_SEQUENCE_NODE)
        iter->item = iter->node->data.sequence.items.start - 1;
}

int ogs_yaml_iter_next(ogs_yaml_iter_t *iter)
{
    log_assert(iter);
    log_assert(iter->document);
    log_assert(iter->node);

    if (iter->node->type == YAML_MAPPING_NODE)
    {
        if (iter->pair)
        {
            iter->pair++;
            if (iter->pair < iter->node->data.mapping.pairs.top)
                return 1;
        }

    }
    else if (iter->node->type == YAML_SEQUENCE_NODE)
    {
        if (iter->item)
        {
            iter->item++;
            if (iter->item < iter->node->data.sequence.items.top)
                return 1;
        }
    }

    return 0;
}

void ogs_yaml_iter_recurse(ogs_yaml_iter_t *parent, ogs_yaml_iter_t *iter)
{
    log_assert(parent);
    log_assert(parent->document);
    log_assert(parent->node);
    log_assert(iter);

    memset(iter, 0, sizeof(ogs_yaml_iter_t));

    iter->document = parent->document;

    if (parent->node->type == YAML_MAPPING_NODE)
    {
        log_assert(parent->pair);
        iter->node = yaml_document_get_node(
                parent->document, parent->pair->value);
        log_assert(iter->node);
        if (iter->node->type == YAML_MAPPING_NODE)
            iter->pair = iter->node->data.mapping.pairs.start - 1;
        else if (iter->node->type == YAML_SEQUENCE_NODE)
            iter->item = iter->node->data.sequence.items.start - 1;
    }
    else if (parent->node->type == YAML_SEQUENCE_NODE)
    {
        log_assert(parent->item);
        iter->node = yaml_document_get_node(parent->document, *parent->item);
        log_assert(iter->node);
        if (iter->node->type == YAML_MAPPING_NODE)
            iter->pair = iter->node->data.mapping.pairs.start - 1;
        else if (iter->node->type == YAML_SEQUENCE_NODE)
            iter->item = iter->node->data.sequence.items.start - 1;
    }
    else
        log_assert_if_reached();
}

int ogs_yaml_iter_type(ogs_yaml_iter_t *iter)
{
    log_assert(iter);
    log_assert(iter->node);

    return iter->node->type;
}


const char *ogs_yaml_iter_key(ogs_yaml_iter_t *iter)
{
    yaml_node_t *node = NULL;

    log_assert(iter);
    log_assert(iter->document);
    log_assert(iter->node);

    if (iter->node->type == YAML_MAPPING_NODE)
    {
        log_assert(iter->pair);
        node = yaml_document_get_node(iter->document, iter->pair->key);
        log_assert(node);
        log_assert(node->type == YAML_SCALAR_NODE);

        return (const char *)node->data.scalar.value;
    }
    else if (iter->node->type == YAML_SEQUENCE_NODE)
    {
        log_assert(iter->item);
        node = yaml_document_get_node(iter->document, *iter->item);
        log_assert(node);
        log_assert(node->type == YAML_SCALAR_NODE);

        return (const char *)node->data.scalar.value;
    }

    log_assert_if_reached();
    return NULL;
}

const char *ogs_yaml_iter_value(ogs_yaml_iter_t *iter)
{
    log_assert(iter);
    log_assert(iter->document);
    log_assert(iter->node);

    if (iter->node->type == YAML_SCALAR_NODE)
    {
        return (const char *)iter->node->data.scalar.value;
    }
    else if (iter->node->type == YAML_MAPPING_NODE)
    {
        yaml_node_t *node = NULL;

        log_assert(iter->pair);
        node = yaml_document_get_node(iter->document, iter->pair->value);
        log_assert(node);
        log_assert(node->type == YAML_SCALAR_NODE);

        return (const char *)node->data.scalar.value;
    }
    else if (iter->node->type == YAML_SEQUENCE_NODE)
    {
        yaml_node_t *node = NULL;

        log_assert(iter->item);
        node = yaml_document_get_node(iter->document, *iter->item);
        log_assert(node);
        log_assert(node->type == YAML_SCALAR_NODE);

        return (const char *)node->data.scalar.value;
    }

    log_assert_if_reached();
    return NULL;
}

int ogs_yaml_iter_has_value(ogs_yaml_iter_t *iter)
{
    log_assert(iter);
    log_assert(iter->document);
    log_assert(iter->node);

    if (iter->node->type == YAML_SCALAR_NODE) {
        return 1;
    } else if (iter->node->type == YAML_MAPPING_NODE) {
        yaml_node_t *node = NULL;

        log_assert(iter->pair);
        node = yaml_document_get_node(iter->document, iter->pair->value);
        log_assert(node);
        return node->type == YAML_SCALAR_NODE;
    } else if (iter->node->type == YAML_SEQUENCE_NODE) {
        yaml_node_t *node = NULL;

        log_assert(iter->item);
        node = yaml_document_get_node(iter->document, *iter->item);
        log_assert(node);
        return node->type == YAML_SCALAR_NODE;
    }

    log_assert_if_reached();
    return 0;
}

int ogs_yaml_iter_bool(ogs_yaml_iter_t *iter)
{
    const char *v = ogs_yaml_iter_value(iter);
    if (v)
    {
        if (!strcasecmp(v, "true") || !strcasecmp(v, "yes")) return 1;
        if (atoi(v)) return 1;
    }

    return 0;
}
