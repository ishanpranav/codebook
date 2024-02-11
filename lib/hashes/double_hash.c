// Licensed under the MIT License.

#include <assert.h>
#include "../hash.h"

size_t double_hash(Object item, size_t size)
{
    assert(size == sizeof(double));
    
    return *((double*)item);
}
