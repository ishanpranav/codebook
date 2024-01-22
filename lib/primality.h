// Licensed under the MIT License.

#ifndef PRIMALITY_a483ebd408a5489d9e9a6d4ce55403d3
#define PRIMALITY_a483ebd408a5489d9e9a6d4ce55403d3

enum Primality
{
    PRIMALITY_NONE = 0,
    PRIMALITY_COMPOSITE,
    PRIMALITY_PROBABLE_PRIME,
    PRIMALITY_PRIME,
    PRIMALITY_UNKNOWN
};

typedef enum Primality Primality;

#endif
