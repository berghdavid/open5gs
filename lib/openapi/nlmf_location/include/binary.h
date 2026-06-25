#ifndef INCLUDE_BINARY_H
#define INCLUDE_BINARY_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct binary_t {
    char* data;
    int len;
} binary_t;

binary_t *instantiate_binary_t(char *data, int len);

char *base64encode(const void *b64_encode_this,
    int encode_this_many_bytes);

char *base64decode(const void *b64_decode_this,
    int decode_this_many_bytes, int *decoded_bytes);

#ifdef __cplusplus
}
#endif

#endif // INCLUDE_BINARY_H
