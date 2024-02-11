// Licensed under the MIT License.

#include <assert.h>
#include "../hash.h"

size_t long_hash(Object item, size_t size)
{
    assert(size == sizeof(long));
    
    return *(long*)item;
}
