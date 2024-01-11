// Licensed under the MIT License.

#include <math.h>
#include "divisor_iterator.h"

void divisor_begin(DivisorIterator iterator, long n)
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

static void divisor_iterator_swap(long* p, long* q)
{
    long swap = *p;

    *p = *q;
    *q = swap;
}

void divisor_next(DivisorIterator iterator)
{
    long n = iterator->n;
    long end = iterator->end;

    if (iterator->state == DIVISOR_ITERATOR_STATE_SWAP)
    {
        divisor_iterator_swap(&iterator->current, &iterator->next);
    }

    if (iterator->state == DIVISOR_ITERATOR_STATE_YIELD)
    {
        divisor_iterator_swap(&iterator->current, &iterator->next);

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
