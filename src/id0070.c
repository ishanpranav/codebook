// Licensed under the MIT License.

// Totient Permutation

#include <math.h>
#include "../lib/euler.h"
#include "../lib/string_builder.h"
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
    struct SieveIterator p;
    struct StringBuilder nDigits;
    struct StringBuilder phiDigits;
    clock_t start = clock();

    euler_ok(sieve(&primes, max));
    euler_ok(string_builder(&nDigits, 0));
    euler_ok(string_builder(&phiDigits, 0));
    sieve_begin(&p, &primes);

    for (sieve_jump(&p, min); p.current < max; sieve_next(&p))
    {
        struct SieveIterator q;

        for (q = p; ; sieve_next(&q))
        {
            long n = p.current * q.current;

            if (n > 10000000l)
            {
                break;
            }

            long phi = n - p.current - q.current + 1;
            double nRPhi = (double)n / phi;

            if (nRPhi >= minNRPhi)
            {
                continue;
            }

            string_builder_clear(&nDigits);
            euler_ok(string_builder_append_format(&nDigits, "%ld", n));
            string_builder_clear(&phiDigits);
            euler_ok(string_builder_append_format(&phiDigits, "%ld", phi));

            if (permutation_test(
                nDigits.buffer,
                nDigits.length,
                phiDigits.buffer,
                phiDigits.length,
                1,
                char_equality_comparer))
            {
                minN = n;
                minNRPhi = nRPhi;
            }
        }
    }

    finalize_sieve(&primes);
    finalize_string_builder(&nDigits);
    finalize_string_builder(&phiDigits);
    
    return euler_submit(70, minN, start);
}
