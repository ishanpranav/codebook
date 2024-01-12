// Licensed under the MIT license.

#include <stdbool.h>
#include <stddef.h>

struct PermutationIterator
{
    long* set;
    size_t length;
    bool end;
};

typedef struct PermutationIterator* PermutationIterator;

void permutation_begin(
    PermutationIterator iterator,
    long* values, 
    size_t length);
    
void permutation_next(PermutationIterator iterator);
