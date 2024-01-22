// Licensed under the MIT License.

#include "../divisor_iterator.h"
#include "divisor_primality_test.h"

Primality divisor_primality_test(long n)
{
    if (n < 2)
    {
        return PRIMALITY_NONE;
    }

    struct DivisorIterator it;

    divisor_begin(&it, n);
    divisor_next(&it);

    if (divisor_end(&it))
    {
        return PRIMALITY_PRIME;
    }

    return PRIMALITY_COMPOSITE;
}
