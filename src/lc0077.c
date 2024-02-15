// Licensed under the MIT License.

// Combinations

#include "../lib/combination_iterator.h"

int** combine(int n, int k, int* returnSize, int** returnColumnSizes) 
{
    int i = 0;
    int nCK = binomial(n, k);
    int** results = malloc(nCK * sizeof * results);
    int* subset = malloc(k * sizeof * subset);
    struct CombinationIterator it;

    for (combination_begin(&it, subset, n, k); !it.end; combination_next(&it))
    {
        results[i] = malloc(k * sizeof * results[i]);

        memcpy(results[i], subset, k * sizeof * subset);
        
        i++;
    }

    free(subset);

    *returnSize = nCK;
    *returnColumnSizes = malloc(nCK * sizeof ** returnColumnSizes);

    for (i = 0; i < nCK; i++)
    {
        returnColumnSizes[0][i] = k;
    }

    return results;
}
