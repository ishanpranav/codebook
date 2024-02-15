// Licensed under the MIT License.

#include "object.h"
#include <stdbool.h>
#include <stddef.h>

struct CombinationIterator
{
    int* subset;
    int i;
    int k;
    int n;
    bool end;
};

typedef struct CombinationIterator* CombinationIterator;

void combination_begin(
    CombinationIterator iterator,
    int subset[],
    int n,
    int k);

void combination_next(CombinationIterator iterator);
