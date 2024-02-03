// Licensed under the MIT License.

// Combinatoric Selections

#include "../lib/binomial.h"
#include "../lib/euler.h"

int main(void)
{
    int count = 0;
    clock_t start = clock();

    for (int n = 1; n <= 100; n++)
    {
        long long* binomials = binomial_mod_range(n + 1, 0);
        
        euler_assert(binomials);

        for (int r = 1; r <= n; r++)
        {
            int k = r;

            if (k > n - k)
            {
                k = n - k;
            }

            if (binomials[k] > 1000000l)
            {
                count++;
            }
        }

        free(binomials);
    }

    return euler_submit(53, count, start);
}
