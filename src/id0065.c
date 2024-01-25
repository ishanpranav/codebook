// Licensed under the MIT License.

// Convergents of e

#include <gmp.h>
#include "../lib/euler.h"
#include "../lib/exception.h"
#include "../lib/lp_string.h"

int main(void)
{
    mpz_t a[3];
    clock_t start = clock();

    mpz_init_set_ui(a[0], 0);
    mpz_init_set_ui(a[1], 1264);
    mpz_init_set_ui(a[2], 1457);

    for (int i = 11; i <= 100; i++)
    {
        mpz_set(a[0], a[1]);
        mpz_set(a[1], a[2]);

        if (i % 3 == 0)
        {
            mpz_mul_ui(a[2], a[1], (2 * i) / 3);
            mpz_add(a[2], a[2], a[0]);
        }
        else
        {
            mpz_add(a[2], a[0], a[1]);
        }
    }

    LPString digits = lp_string(mpz_sizeinbase(a[2], 10));

    if (!digits)
    {
        Exception ex = EXCEPTION_OUT_OF_MEMORY;

        euler_ok();
    }

    mpz_get_str(digits, 10, a[2]);

    int sum = 0;

    for (char* p = digits; *p; p++)
    {
        sum += *p - '0';
    }

    mpz_clear(a[0]);
    mpz_clear(a[1]);
    mpz_clear(a[2]);

    return euler_submit(57, sum, start);
}
