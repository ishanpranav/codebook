// Licensed under the MIT License.

#include "../hash.h"

size_t pjw_hash(Object item, size_t size)
{
    return pjw_hash32(item, size);
}

uint32_t pjw_hash32(Object item, size_t size)
{
    uint32_t result = 0;
    uint32_t high;
    unsigned char* begin = item;
    unsigned char* end = begin + size;

    for (unsigned char* p = begin; p < end; p++)
    {
        result = (result << 4) + *p++;

        if ((high = result & 0xF0000000))
        {
            result ^= high >> 24;
        }

        result &= ~high;
    }

    return result;
}
