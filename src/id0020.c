// Licensed under the MIT License.

// Factorial Digit Sum

#include <gmp.h>
#include "../lib/euler.h"

int main(void)
{
    mpz_t megahuge;
    char digits[256];
    clock_t start = clock();

    mpz_init(megahuge);
    mpz_fac_ui(megahuge, 100);
    mpz_get_str(digits, 10, megahuge);

    int sum = 0;

    for (char* p = digits; *p; p++)
    {
        sum += *p - '0';
    }

    euler_submit(20, sum, start);
    mpz_clear(megahuge);

    return 0;
}
