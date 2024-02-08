// Licensed under the MIT License.

#include "../random.h"

static uint64_t rol64(uint64_t x, int k)
{
    return (x << k) | (x >> (64 - k));
}

long long xoshiro256_star_star_random(Object instance, long long max)
{
    return xoshiro256_star_star_random64(instance) % max;
}

uint64_t xoshiro256_star_star_random64(Object instance)
{
    uint64_t* s = instance;
    uint64_t result = rol64(s[1] * 5, 7) * 9;
    uint64_t t = s[1] << 17;

    s[2] ^= s[0];
    s[3] ^= s[1];
    s[1] ^= s[2];
    s[0] ^= s[3];
    s[2] ^= t;
    s[3] = rol64(s[3], 45);

    return result;
}
