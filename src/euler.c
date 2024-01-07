// Licensed under the MIT License.

// Multiples of 3 or 5

#include <stdio.h>
#include "euler.h"

void euler_submit(int id, clock_t start)
{
    printf("%04d %lf\n", 
        id, 
        (double)(clock() - start) / CLOCKS_PER_SEC);
}
