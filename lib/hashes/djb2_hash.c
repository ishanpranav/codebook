// Licensed under the MIT License.

#include "../hash.h"

size_t djb2_hash(Object item, size_t size)
{
    size_t result = 5381;
    char* begin = item;
    char* end = begin + size;

    for (char* p = begin; p < end; p++)
    {
        result = ((result << 5) + result) + *p;
    }
    
    return result;
}
