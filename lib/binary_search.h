#include <stddef.h>
#include "array.h"
#include "comparer.h"
#include "object.h"

Object binary_search_first_after(
    Object item, 
    Array items, 
    size_t length, 
    size_t itemSize, 
    Comparer comparer);
    