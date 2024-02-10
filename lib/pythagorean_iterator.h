// Licensed under the MIT License.

#include <stdbool.h>

/** Iterates over all Pythagorean triplets in an interval. */
struct PythagoreanIterator
{
    long a;
    long b;
    long c;
    long m;
    long n;
    long max;
    long sqrtMax;
    bool end;
};

/** Iterates over all Pythagorean triplets in an interval. */
typedef struct PythagoreanIterator* PythagoreanIterator;

/**
 * Provides an iterator over the Pythagorean triplets whose components are in
 * the interval [3, `max`).
 * 
 * @param iterator the iterator.
 * @param max      the upper bound for each component.
*/
void pythagorean_begin(PythagoreanIterator iterator, long max);

/**
 * Advances the iterator to the next Pythagorean triplet.
 * 
 * @param iterator the iterator.
*/
void pythagorean_next(PythagoreanIterator iterator);
