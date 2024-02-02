// Licensed under the MIT License.

// Powerful Digit Sum

#include <gmp.h>
#include <math.h>
#include "../lib/euler.h"

int main(void)
{
    int max = 0;
    mpz_t megahuge;
    clock_t start = clock();
    String str = string(math_length(99, 99));

    mpz_init(megahuge);

    for (int b = 99; b >= 1; b--)
    {
        if (max >= 9 * math_length(99, b))
        {
            break;
        }

        for (int a = 99; a >= 90; a--)
        {
            int sum = 0;
            
            mpz_ui_pow_ui(megahuge, a, b);
            mpz_get_str(str, 10, megahuge);

            for (char* p = str; *p; p++)
            {
                sum += *p - '0';
            }

            if (sum > max)
            {
                max = sum;
            }
        }
    }

    mpz_clear(megahuge);

    return euler_submit(56, max, start);
}
