// Licensed under the MIT License.

// Combinations

#include <string.h>
#include "../lib/binomial.h"
#include "../lib/combination_iterator.h"
#include "../lib/euler.h"

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) 
{
    int i = 0;
    int nCK = binomial(n, k);
    struct CombinationIterator it;
    int** results = malloc(nCK * sizeof * results);

    euler_assert(results);

    int* subset = malloc(k * sizeof * subset);

    euler_assert(subset);

    for (combination_begin(&it, subset, n, k); !it.end; combination_next(&it))
    {
        results[i] = malloc(k * sizeof * results[i]);

        euler_assert(results[i]);
        memcpy(results[i], subset, k * sizeof * subset);
        
        i++;
    }

    free(subset);

    *returnSize = nCK;
    *returnColumnSizes = malloc(nCK * sizeof ** returnColumnSizes);

    euler_assert(*returnColumnSizes);

    for (i = 0; i < nCK; i++)
    {
        returnColumnSizes[0][i] = k;
    }

    return results;
}
