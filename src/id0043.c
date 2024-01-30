// Licensed under the MIT License.

// Sub-string Divisiblity

#include <stdlib.h>
#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/lp_string_builder.h"

static bool math_is_substring_divisible(LPStringBuilder digits)
{
    int mod[] = { 2, 3, 5, 7, 11, 13, 17 };

    for (int i = 0; i < 7; i++)
    {
        int n = 0;

        for (int j = i + 1; j <= i + 3; j++)
        {
            n = n * 10 + digits->buffer[j] - '0';
        }

        if (n % mod[i] != 0)
        {
            return false;
        }
    }

    return true;
}

int main(void)
{
    struct LPStringBuilder digits;
    struct PermutationIterator it;
    long long sum = 0;
    clock_t start = clock();
    
    lp_string_builder(&digits, 0);
    lp_string_builder_append_string(&digits, "0123456789");

    for (permutation_begin(&it, digits.buffer, 1, digits.length, char_comparer);
        !it.end;
        permutation_next(&it))
    {
        if (!math_is_substring_divisible(&digits))
        {
            continue;
        }

        sum += atoll(digits.buffer);
    }
    
    return euler_submit(43, sum, start);
}
