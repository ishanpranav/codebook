// Licensed under the MIT License.

#include <stdbool.h>

enum DivisorIteratorState
{
    DIVISOR_ITERATOR_STATE_INITIAL,
    DIVISOR_ITERATOR_STATE_SWAP,
    DIVISOR_ITERATOR_STATE_YIELD
};

struct DivisorIterator
{
    long n;
    long current;
    long next;
    long end;
    enum DivisorIteratorState state;
};

typedef struct DivisorIterator* DivisorIterator;

void divisor_begin(DivisorIterator iterator, long n);
bool divisor_end(DivisorIterator iterator);
void divisor_next(DivisorIterator iterator);
long divisor_sum(long n);
