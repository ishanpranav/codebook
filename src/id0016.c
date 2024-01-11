// Licensed under the MIT License.

// Power Digit Sum

#include <gmp.h>
#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/series.h"

int main(void)
{
    mpz_t megahuge;
    char digits[512];
    clock_t start = clock();

    mpz_init_set_ui(megahuge, 2);
    mpz_pow_ui(megahuge, megahuge, 1000);
    mpz_get_str(digits, 10, megahuge);
    mpz_clear(megahuge);

    Series series = series_from_string(digits);
    int sum = series_sum(series);

    free(series);
    
    return euler_submit(16, sum, start);
}
