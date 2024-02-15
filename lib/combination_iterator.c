// Licensed under the MIT License.

#include <stdint.h>
#include <string.h>
#include "combination_iterator.h"

void combination_begin(
    CombinationIterator iterator,
    int subset[],
    int n,
    int k)
{
    iterator->subset = subset;
    iterator->i = 0;
    iterator->k = k;
    iterator->n = n;
    iterator->end = false;

    for (size_t i = 0; i < iterator->k; i++)
    {
        iterator->subset[i] = 0;
    }

    combination_next(iterator);
}

void combination_next(CombinationIterator iterator)
{
    while (iterator->i >= 0)
    {
        iterator->subset[iterator->i]++;

        if (iterator->subset[iterator->i] > iterator->n)
        {
            iterator->i--;
        }
        else if (iterator->i == iterator->k - 1)
        {
            return;
        }
        else
        {
            iterator->i++;
            iterator->subset[iterator->i] = iterator->subset[iterator->i - 1];
        }
    }

    iterator->end = true;
}
