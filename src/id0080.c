// Licensed under the MIT License.

// Square Root Digital Expansion

#include <math.h>
#include <gmp.h>
#include <string.h>
#include "../lib/euler.h"

int main(void)
{
    mpf_t tuple;
    char buffer[103];
    long sum = 0;
    clock_t start = clock();

    mpf_init2(tuple, log2(1e102) + 1);

    for (int i = 2; i < 100; i++)
    {
        if (math_is_polygonal(4, i, NULL)) 
        {
            continue;
        }
        
        mpf_sqrt_ui(tuple, i);
        gmp_snprintf(buffer, sizeof buffer, "%.101Ff\n", tuple);
        
        char* mid = strchr(buffer, '.');

        euler_assert(mid);

        sum += buffer[0] - '0';
        
        for (int i = 1; i < 100; i++)
        {
            sum += mid[i] - '0';
        }
    }

    mpf_clear(tuple);

    return euler_submit(80, sum, start);
}
