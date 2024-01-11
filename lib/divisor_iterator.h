// Licensed under the MIT License.

#include <stdbool.h>

struct DivisorIterator
{
    long n;
    long current;
    long next;
    long end;
    int state;
};

typedef struct DivisorIterator* DivisorIterator;

void divisor_begin(DivisorIterator iterator, long n);
bool divisor_end(DivisorIterator iterator);
void divisor_next(DivisorIterator iterator);
