/*
 * Copyright (C) 2019 by Sukchan Lee <acetcom@gmail.com>
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

#include "conv.h"

void ogs_asn_uint8_to_OCTET_STRING(
        uint8_t uint8, OCTET_STRING_t *octet_string)
{
    log_assert(octet_string);

    octet_string->size = 1;
    octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

    octet_string->buf[0] = uint8;
}

void ogs_asn_uint16_to_OCTET_STRING(
        uint16_t uint16, OCTET_STRING_t *octet_string)
{
    log_assert(octet_string);

    octet_string->size = 2;
    octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

    octet_string->buf[0] = uint16 >> 8;
    octet_string->buf[1] = uint16;
}

void ogs_asn_uint24_to_OCTET_STRING(
        ogs_uint24_t uint24, OCTET_STRING_t *octet_string)
{
    log_assert(octet_string);

    octet_string->size = 3;
    octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

    octet_string->buf[0] = uint24.v >> 16;
    octet_string->buf[1] = uint24.v >> 8;
    octet_string->buf[2] = uint24.v;
}

void ogs_asn_uint32_to_OCTET_STRING(
        uint32_t uint32, OCTET_STRING_t *octet_string)
{
    log_assert(octet_string);

    octet_string->size = 4;
    octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

    octet_string->buf[0] = uint32 >> 24;
    octet_string->buf[1] = uint32 >> 16;
    octet_string->buf[2] = uint32 >> 8;
    octet_string->buf[3] = uint32;
}

void ogs_asn_OCTET_STRING_to_uint8(
        OCTET_STRING_t *octet_string, uint8_t *uint8)
{
    log_assert(octet_string);
    log_assert(uint8);

    *uint8 = octet_string->buf[0];
}
void ogs_asn_OCTET_STRING_to_uint16(
        OCTET_STRING_t *octet_string, uint16_t *uint16)
{
    log_assert(octet_string);
    log_assert(uint16);

    *uint16 = (octet_string->buf[0] << 8) + octet_string->buf[1];
}
void ogs_asn_OCTET_STRING_to_uint24(
        OCTET_STRING_t *octet_string, ogs_uint24_t *uint24)
{
    log_assert(octet_string);
    log_assert(uint24);

    memcpy(uint24, octet_string->buf, sizeof(ogs_uint24_t));
    *uint24 = ogs_be24toh(*uint24);
}
void ogs_asn_OCTET_STRING_to_uint32(
        OCTET_STRING_t *octet_string, uint32_t *uint32)
{
    log_assert(octet_string);
    log_assert(uint32);

    *uint32 = (octet_string->buf[0] << 24) + (octet_string->buf[1] << 16) +
                (octet_string->buf[2] << 8) + octet_string->buf[3];
}

void ogs_asn_buffer_to_OCTET_STRING(
        void *buf, int size, OCTET_STRING_t *octet_string)
{
    octet_string->size = size;
    octet_string->buf = CALLOC(octet_string->size, sizeof(uint8_t));

    memcpy(octet_string->buf, buf, size);
}

void ogs_asn_buffer_to_BIT_STRING(
        void *buf, int size, int unused, BIT_STRING_t *bit_string)
{
    bit_string->size = size;
    bit_string->buf = CALLOC(bit_string->size, sizeof(uint8_t));
    bit_string->bits_unused = unused;

    memcpy(bit_string->buf, buf, size);
}

void ogs_asn_uint32_to_BIT_STRING(
        uint32_t uint32, uint8_t bitsize, BIT_STRING_t *bit_string)
{
    char tmp[32];
    uint64_t uint64;
    log_assert(bit_string);

    uint64 = uint32;
    ogs_uint64_to_buffer(
            uint64 << ((32 - bitsize) % 8), (bitsize + 7) / 8, tmp);
    ogs_asn_buffer_to_BIT_STRING(
            tmp, (bitsize + 7) / 8, (32 - bitsize) % 8, bit_string);
}
