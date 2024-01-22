// Licensed under the MIT License.

#ifndef PRIMALITY_a483ebd408a5489d9e9a6d4ce55403d3
#define PRIMALITY_a483ebd408a5489d9e9a6d4ce55403d3

/** Specifies the primality of a number. */
enum Primality
{
    /** Neither a prime nor a composite. */
    PRIMALITY_NONE = 0,

    /** A composite. */
    PRIMALITY_COMPOSITE,

    /** A probable prime. */
    PRIMALITY_PROBABLE_PRIME,

    /** A prime. */
    PRIMALITY_PRIME,

    /** A number with unknown primality. */
    PRIMALITY_UNKNOWN
};

/** Specifies the primality of a number. */
typedef enum Primality Primality;

#endif
