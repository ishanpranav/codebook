// Licensed under the MIT License.

// 1000-digit Fibonacci Number

#include <gmp.h>
#include "../lib/euler.h"

int main(void)
{
    mpz_t f0;
    mpz_t f1;
    mpz_t f2;
    unsigned int n = 12;
    clock_t start = clock();

    mpz_init(f0);
    mpz_init(f1);
    mpz_init(f2);
    mpz_fib2_ui(f1, f0, n);

    while (mpz_sizeinbase(f0, 10) < 1000)
    {
        mpz_add(f2, f0, f1);
        mpz_set(f0, f1);
        mpz_set(f1, f2);

        n++;
    }

    mpz_clear(f0);
    mpz_clear(f1);
    mpz_clear(f2);

    return euler_submit(25, n, start);
}
