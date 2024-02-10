// Licensed under the MIT License.

#include <math.h>
#include <stdlib.h>
#include "euclidean.h"
#include "pythagorean_iterator.h"

int* pythagorean_triplet_count_range(long max)
{
    int* result = calloc(max, sizeof * result);

    if (!result)
    {
        return NULL;
    }

    long end = sqrt(max);

    for (long m = 1; m < end; m += 2)
    {
        for (long n = 2; n < end; n += 2)
        {
            if (gcd(m, n) != 1)
            {
                continue;
            }

            long sum = labs(m * m - n * n) + m * m + n * n + 2 * m * n;

            for (long kSum = sum; kSum < max; kSum += sum)
            {
                result[kSum]++;
            }
        }
    }

    return result;
}

void pythagorean_begin(PythagoreanIterator iterator, long max)
{
    iterator->c = 2;
    iterator->m = 0;
    iterator->n = 1;
    iterator->max = max;
    iterator->sqrtMax = sqrt(max);
    iterator->end = false;

    pythagorean_next(iterator);
}

void pythagorean_next(PythagoreanIterator iterator)
{
    while (iterator->m < iterator->max)
    {
        while (iterator->n < iterator->m)
        {
            iterator->a = iterator->m * iterator->m - iterator->n * iterator->n;
            iterator->b = 2 * iterator->m * iterator->n;
            iterator->c = iterator->m * iterator->m + iterator->n * iterator->n;
            iterator->n++;

            if (iterator->c < iterator->max)
            {
                return;
            }
        }

        iterator->m++;
        iterator->n = 1;
    }

    iterator->end = true;
}
