// Licensed under the MIT License.

#include "object.h"
#include <stdbool.h>
#include <stddef.h>

struct CombinationIterator
{
    size_t* subset;
    size_t i;
    size_t k;
    size_t n;
    bool end;
};

typedef struct CombinationIterator* CombinationIterator;

void combination_begin(
    CombinationIterator iterator,
    size_t subset[],
    size_t n,
    size_t k);

void combination_next(CombinationIterator iterator);
