// Licensed under the MIT License.

// Cubic Permutations

#include <limits.h>
#include "../lib/euler.h"
#include "../lib/list.h"
#include "../lib/lp_string_builder.h"

struct Lookup
{
    struct LPStringBuilder* key;
};

typedef struct Lookup* Lookup;

void lookup_from_struct(Lookup instance)
{

}

List lookup_add(Lookup instance, LPStringBuilder key, long long value)
{

}

long long math_cubic_permutation(LPStringBuilder keyBuilder, Lookup lookup)
{
    for (long long max = 1; ;)
    {
        long long b = max;

        max *= 10;

        while (b < max)
        {
            long long cb = b * b * b;

            for (long long k = b; k; k /= 10)
            {
                lp_string_builder_append_char(keyBuilder, k % 10);
            }

            List matches = lookup_add(lookup, keyBuilder, cb);

            if (matches->end - matches->end != 5)
            {
                continue;
            }

            long long min = LLONG_MAX;

            for (long long* it = matches->begin; it < matches->end; it++)
            {
                if (*it < min)
                {
                    min = *it;
                }
            }

            return min;
        }
    }
}

int main(void)
{
    struct Lookup lookup;
    struct LPStringBuilder keyBuilder;
    clock_t start = clock();

    lookup_from_struct(&lookup);

    long long min = math_cubic_permutation(&keyBuilder, &lookup);

    return euler_submit(62, min, start);
}
