// Licensed under the MIT License.

#include "elf_hash.h"

size_t elf_hash(Object item, size_t size)
{
    return elf_hash32(item, size);
}

uint32_t elf_hash32(Object item, size_t size)
{
    uint32_t result = 0;
    uint32_t high;
    char* begin = item;
    char* end = begin + size;

    for (char* p = begin; p < end; p++)
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
