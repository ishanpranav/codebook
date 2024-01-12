// Licensed under the MIT License.

// Factorial Digit Sum

#include <gmp.h>
#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/series.h"

int main(void)
{
    mpz_t megahuge;
    char digits[256];
    struct Series series;
    clock_t start = clock();

    mpz_init(megahuge);
    mpz_fac_ui(megahuge, 100);
    mpz_get_str(digits, 10, megahuge);
    mpz_clear(megahuge);
    series_from_string(&series, digits);

    long sum = series_sum(&series);
    
    return euler_submit(20, sum, start);
}
