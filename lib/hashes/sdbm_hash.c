// Licensed under the MIT License.

#include "../hash.h"

/**
 * Computes the SDBM hash digest.
 *
 * @param item the object.
 * @param size the size of the `item` argument.
 * @return A hash code for the given item.
*/
size_t sdbm_hash(Object item, size_t size)
{
    size_t result = 0;
    char* begin = item;
    char* end = begin + size;

    for (char* p = begin; p < end; p++)
    {
        result = *p + (result << 6) + (result << 16) - result;
    }

    return result;
}
