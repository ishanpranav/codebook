// Licensed under the MIT License.

// Special Pythagorean Triplet

#include <math.h>
#include "../lib/euler.h"
#include "../lib/pythagorean_iterator.h"

int main(void)
{
    struct PythagoreanIterator it;
    clock_t start = clock();

    for (pythagorean_begin(&it, 500); !it.end; pythagorean_next(&it))
    {
        if (it.a + it.b + it.c == 1000)
        {
            break;
        }
    }

    long product = it.a * it.b * it.c;

    return euler_submit(9, product, start);
}
