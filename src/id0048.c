// Licensed under the MIT License.

// Self Powers

#include <gmp.h>
#include "../lib/euler.h"

int main(void)
{
    mpz_t sum, term;
    clock_t start = clock();

    mpz_init_set_ui(sum, 1);
    mpz_init(term);
    
    for (int i = 2; i <= 1000; i++)
    {
        mpz_ui_pow_ui(term, i, i);
        mpz_add(sum, sum, term);
    }

    mpz_mod_ui(sum, sum, 10000000000ll);
    
    double result = mpz_get_d(sum);

    mpz_clears(sum, term, NULL);

    return euler_submit(48, result, start);
}
