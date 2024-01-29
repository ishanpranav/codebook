// Licensed under the MIT License.

// Totient Permutation

#include <math.h>
#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/sieve_iterator.h"
#define MAX_SEARCH 0.375

int main(void)
{
    double mid = sqrt(1e7);
    double minNRPhi = INFINITY;
    long minN = -1;
    int min = mid * (1 - MAX_SEARCH);
    int max = mid * (1 + MAX_SEARCH);
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, max);

    euler_ok();

    struct List nDigits;

    ex = list(&nDigits, sizeof(int), 0);

    euler_ok();

    struct List phiDigits;

    ex = list(&phiDigits, sizeof(int), 0);

    euler_ok();

    struct SieveIterator p;

    sieve_begin(&p, &primes);

    for (sieve_jump(&p, min); *p.current < max; sieve_next(&p))
    {
        struct SieveIterator q;

        for (q = p; ; sieve_next(&q))
        {
            long n = *p.current * *q.current;

            if (n > 10000000l)
            {
                break;
            }

            long phi = n - *p.current - *q.current + 1;
            double nRPhi = (double)n / phi;

            if (nRPhi >= minNRPhi)
            {
                continue;
            }

            list_clear(&nDigits);

            for (long k = n; k; k /= 10)
            {
                int d = k % 10;

                ex = list_add(&nDigits, &d);

                euler_ok();
            }
            
            list_clear(&phiDigits);

            for (long k = phi; k; k /= 10)
            {
                int d = k % 10;

                ex = list_add(&phiDigits, &d);

                euler_ok();
            }

            if (permutation_test(&nDigits, &phiDigits, int_equality_comparer))
            {
                minN = n;
                minNRPhi = nRPhi;
            }
        }
    }

    finalize_list(&nDigits);
    finalize_list(&phiDigits);
    finalize_sieve(&primes);
    
    return euler_submit(70, minN, start);
}
