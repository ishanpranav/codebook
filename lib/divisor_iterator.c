// Licensed under the MIT License.

#include <math.h>
#include "divisor_iterator.h"
#include "euler.h"
#include "swap.h"

void divisor_begin(DivisorIterator iterator, long long n)
{
    iterator->n = n;
    iterator->sqrtN = sqrt(n);
    iterator->current = 1;
    iterator->next = 0;
    iterator->state = DIVISOR_ITERATOR_STATE_INITIAL;
}

bool divisor_end(DivisorIterator iterator)
{
    if (iterator->state == DIVISOR_ITERATOR_STATE_SWAP)
    {
        return iterator->next > iterator->sqrtN;
    }

    return iterator->current > iterator->sqrtN;
}

void divisor_next(DivisorIterator iterator)
{
    long long n = iterator->n;
    long long end = iterator->sqrtN;

    if (iterator->state == DIVISOR_ITERATOR_STATE_SWAP)
    {
        swap(&iterator->current, &iterator->next, sizeof(long long));
    }

    if (iterator->state == DIVISOR_ITERATOR_STATE_YIELD)
    {
        swap(&iterator->current, &iterator->next, sizeof(long long));

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
