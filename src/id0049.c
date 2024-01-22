// Licensed under the MIT License.

// Prime Permutations

#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/sieve.h"

Exception math_prime_permutation(
    Sieve primes, 
    List aDigits, 
    List bDigits, 
    List cDigits,
    int min, 
    int max,
    long long* result)
{
    for (int a = min; a < max; a++)
    {
        int b = a + 3330;
        int c = b + 3330;

        if (sieve_test(primes, a, NULL) != PRIMALITY_PRIME ||
            sieve_test(primes, b, NULL) != PRIMALITY_PRIME ||
            sieve_test(primes, c, NULL) != PRIMALITY_PRIME)
        {
            continue;
        }

        list_clear(aDigits);

        for (int k = a; k; k /= 10)
        {
            Exception ex = list_add(aDigits, k % 10);

            if (ex)
            {
                return ex;
            }
        }
        
        list_clear(bDigits);

        for (int k = b; k; k /= 10)
        {
            Exception ex = list_add(bDigits, k % 10);

            if (ex)
            {
                return ex;
            }
        }

        if (!permutation_test(aDigits, bDigits))
        {
            continue;
        }

        list_clear(cDigits);

        for (int k = c; k; k /= 10)
        {
            Exception ex = list_add(cDigits, k % 10);

            if (ex)
            {
                return ex;
            }
        }

        if (!permutation_test(bDigits, cDigits))
        {
            continue;
        }

        *result = a * 100000000ll + b * 10000 + c;
    }

    return 0;
}

int main(void)
{
    struct Sieve primes;
    clock_t start = clock();
    Exception ex = sieve(&primes, 10000);

    euler_ok();
    
    struct List a;

    ex = list(&a, 0);

    euler_ok();
    
    struct List b;
    
    ex = list(&b, 0);

    euler_ok();

    struct List c;

    ex = list(&c, 0);

    euler_ok();
    
    long long result = -1;

    ex = math_prime_permutation(&primes, &a, &b, &c, 2, 1487, &result);
    
    euler_ok();

    if (result < 0)
    {
        long last = primes.primes.end[-1];

        ex = math_prime_permutation(&primes, &a, &b, &c, 1488, last, &result);
    }

    return euler_submit(49, result, start);
}
