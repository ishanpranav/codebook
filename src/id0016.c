// Licensed under the MIT License.

// Power Digit Sum

#include <gmp.h>
#include <string.h>
#include "../lib/euler.h"

int main(void)
{
    mpz_t megahuge;
    char digits[512];
    clock_t start = clock();

    mpz_init_set_ui(megahuge, 2);
    mpz_pow_ui(megahuge, megahuge, 1000);
    mpz_get_str(digits, 10, megahuge);

    int sum = 0;

    for (char* p = digits; *p; p++)
    {
        sum += *p - '0';
    }

    euler_submit(15, sum, start);
    mpz_clear(megahuge);
}
