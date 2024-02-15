// Licensed under the MIT License.

#include "binary_search.h"
#include "hash_helpers.h"

/** See https://planetmath.org/goodhashtableprimes. */
static size_t primes[] = 
{
    53, 97, 193, 389, 769, 1543, 3079, 6151, 12289, 24593, 49157l, 98317l,
    196613l, 393241l, 786433l, 1572869l, 3145739l, 6291469l, 12582917l,
    25165843l, 50331653l, 100663319l, 201326611l, 402653189l, 805306457l,
    1610612741l
};

size_t hash_helpers_min_capacity(size_t capacity)
{
    if (capacity < primes[0])
    {
        return primes[0];
    }

    return capacity;
}

size_t hash_helpers_new_capacity(size_t count, size_t capacity)
{
    capacity *= 2;

    size_t* prime = binary_search_min(
        &capacity, 
        primes, 
        26,
        sizeof * primes,
        size_comparer);

    if (prime && *prime > capacity)
    {
        capacity = *prime;
    }

    if (count > capacity)
    {
        return count;
    }

    return capacity;
}
