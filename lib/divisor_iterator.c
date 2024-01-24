// Licensed under the MIT License.

#include <math.h>
#include "divisor_iterator.h"
#include "euler.h"

void divisor_begin(DivisorIterator iterator, long long n)
{
    iterator->n = n;
    iterator->end = sqrt(n);
    iterator->current = 1;
    iterator->next = 0;
    iterator->state = DIVISOR_ITERATOR_STATE_INITIAL;
}

bool divisor_end(DivisorIterator iterator)
{
    if (iterator->state == DIVISOR_ITERATOR_STATE_SWAP)
    {
        return iterator->next > iterator->end;
    }

    return iterator->current > iterator->end;
}

void divisor_next(DivisorIterator iterator)
{
    long long n = iterator->n;
    long long end = iterator->end;

    if (iterator->state == DIVISOR_ITERATOR_STATE_SWAP)
    {
        euler_swap(&iterator->current, &iterator->next);
    }

    if (iterator->state == DIVISOR_ITERATOR_STATE_YIELD)
    {
        euler_swap(&iterator->current, &iterator->next);

        iterator->state = DIVISOR_ITERATOR_STATE_SWAP;

        return;
    }

    do
    {
        iterator->current++;
    }
    while (iterator->current <= end && n % iterator->current != 0);

    if (iterator->current != n / iterator->current)
    {
        iterator->next = n / iterator->current;
        iterator->state = DIVISOR_ITERATOR_STATE_YIELD;
    }
    else
    {
        iterator->state = DIVISOR_ITERATOR_STATE_INITIAL;
    }
}

long long divisor_sum(long long n)
{
    int result = 0;
    struct DivisorIterator it;

    for (divisor_begin(&it, n); !divisor_end(&it); divisor_next(&it))
    {
        result += it.current;
    }

    return result;
}
