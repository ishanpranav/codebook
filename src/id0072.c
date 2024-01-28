// Licensed under the MIT License.

// Counting Fractions

#include "../lib/euler.h"
#include "../lib/totient.h"

int main(void)
{
    struct List totients;
    clock_t start = clock();
    Exception ex = list(&totients, 0);

    euler_ok();

    ex = totient_range(&totients, 1000001);

    euler_ok();

    long long summatoryTotient = list_sum(&totients) - totients.begin[1];
    
    return euler_submit(72, summatoryTotient, start);
}
