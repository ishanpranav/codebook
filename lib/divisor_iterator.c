// Licensed under the MIT License.

#include <math.h>
#include <stdio.h>
#include "divisor_iterator.h"

void divisor_begin(DivisorIterator iterator, long n)
{
    iterator->n = n;
    iterator->end = sqrt(n);
    iterator->current = 1;
    iterator->next = 0;
    iterator->state = 0;

    printf("DIVISOR_BEGIN n = %ld end = %ld current = %ld next = %ld state = %d\n", iterator->n, iterator->end, iterator->current, iterator->next, iterator->state);
}

bool divisor_end(DivisorIterator iterator)
{
    if (iterator->state == 1)
    {
        return iterator->next > iterator->end;
    }

    return iterator->current > iterator->end;
}

void divisor_next(DivisorIterator iterator)
{
    long n = iterator->n;
    long end = iterator->end;

    if (iterator->state == 1)
    {
        long swap = iterator->current;

        iterator->current = iterator->next;
        iterator->next = swap;
    }

    if (iterator->state == 0 || iterator->state == 1)
    {
        do
        {
            iterator->current++;
        }
        while (iterator->current <= end && n % iterator->current != 0);

        if (iterator->current != n / iterator->current)
        {
            iterator->next = n / iterator->current;
            iterator->state = 2;
        }
        else
        {
            iterator->next = 0;
            iterator->state = 0;
        }
    }
    else
    {
        long swap = iterator->current;

        iterator->current = iterator->next;
        iterator->next = swap;
        iterator->state = 1;
    }    
    
    printf("DIVISOR_NEXT n = %ld end = %ld current = %ld next = %ld state = %d\n", iterator->n, iterator->end, iterator->current, iterator->next, iterator->state);
}
