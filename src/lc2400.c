// Licensed under the MIT License.

// Number of Ways to Reach a Position After Exactly k Steps

#include "../lib/binomial.h"
#include "../lib/euler.h"

int numberOfWays(int start, int end, int k)
{
    int difference = abs(end - start);
    
    if (difference > k || (difference + k) % 2 == 1)
    {
        return 0;
    }

    long long* binomials = mod_binomial_range(k + 1, 0);

    euler_assert(binomials);

    long long result = binomials[(difference + k) / 2];

    free(binomials);

    return result;
}
