// Licensed under the MIT License.

// 1000-digit Fibonacci Number

#include <gmp.h>
#include "../lib/euler.h"

int main(void)
{
    unsigned int n = 12;
    mpz_t f0, f1, f2;
    clock_t start = clock();

    mpz_inits(f0, f1, f2, NULL);
    mpz_fib2_ui(f1, f0, n - 1);

    while (mpz_sizeinbase(f2, 10) < 1000)
    {
        mpz_add(f2, f0, f1);
        mpz_set(f0, f1);
        mpz_set(f1, f2);

        n++;
    }

    mpz_clears(f0, f1, f2, NULL);

    return euler_submit(25, n, start);
}
