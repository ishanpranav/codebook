// Licensed under the MIT License.

#include "../random.h"

long long xorshift32_random(Object instance, long long max)
{
    return xorshift32_random32(instance) % max;
}

uint32_t xorshift32_random32(Object instance)
{
    uint32_t* state = instance;
    uint32_t x = *state;

    x ^= x << 13;
    x ^= x >> 17;
    x ^= x << 5;
    *state = x;

    return x;
}
