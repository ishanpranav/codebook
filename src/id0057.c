// Licensed under the MIT License.

// Square Root Convergence

#include <gmp.h>
#include "../lib/euler.h"

int math_huge_length(mpz_t huge)
{
    char unit;

    return gmp_snprintf(&unit, 1, "%Zd", huge);
}

int main(void)
{
    int count = 1;
    mpz_t a[2], b[2];
    clock_t start = clock();

    mpz_init_set_ui(a[0], 1393);
    mpz_init_set_ui(b[0], 985);
    mpz_inits(a[1], b[1], NULL);

    for (int i = 0; i < 992; i++)
    {
        mpz_add(a[1], a[0], b[0]);
        mpz_set(b[1], a[1]);
        mpz_add(a[1], a[1], b[0]);
        mpz_set(a[0], a[1]);
        mpz_set(b[0], b[1]);

        if (math_huge_length(a[0]) > math_huge_length(b[0]))
        {
            count++;
        }
    }

    mpz_clears(a[0], a[1], b[0], b[1], NULL);

    return euler_submit(57, count, start);
}
