// Licensed under the MIT License.

// Factorial Digit Sum

#include <gmp.h>
#include "../lib/euler.h"
#include "../lib/exception.h"
#include "../lib/lp_string.h"
#include "../lib/series.h"

int main(void)
{
    mpz_t megahuge;
    struct Series series;
    clock_t start = clock();

    mpz_init(megahuge);
    mpz_fac_ui(megahuge, 100);
    
    LPString digits = lp_string(mpz_sizeinbase(megahuge, 10));
    
    if (!digits)
    {
        Exception ex = EXCEPTION_OUT_OF_MEMORY;

        euler_ok();
    }
    
    mpz_get_str(digits, 10, megahuge);
    mpz_clear(megahuge);
    series_from_string(&series, digits);

    long sum = series_sum(&series);

    return euler_submit(20, sum, start);
}
