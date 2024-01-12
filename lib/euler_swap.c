// Licensed under the MIT License.

#include "euler_swap.h"

void euler_swap(long* p, long* q)
{
    long swap = *p;

    *p = *q;
    *q = swap;
}
