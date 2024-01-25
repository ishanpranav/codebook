// Licensed under the MIT License.

// Cyclic Figurate Numbers

#include "../lib/euler.h"
#include "../lib/list.h"

bool math_is_cyclic(int a, int b)
{
    return a != b && a / 100 == b % 100;
}

bool math_is_octagonal_or_smaller_polygonal(int x)
{
    for (int s = 3; s < 6; s++)
    {
        if (math_is_polygonal(s, x, NULL))
        {
            return true;
        }
    }

    return math_is_polygonal(7, x, NULL) || math_is_polygonal(8, x, NULL);
}

bool math_is_permuted_polygonal(int values[])
{
    int flags = 0;

    for (int* x = values; x < values + 6; x++)
    {
        for (int s = 8; s >= 3; s--)
        {
            if (math_is_polygonal(s, *x, NULL))
            {
                flags |= (1 << s);

                break;
            }
        }
    }

    return flags == 0x1f8;
}

int math_cyclic_polygonal_sum(List polygonals)
{
    long long* begin = polygonals->begin;
    long long* end = polygonals->end;

    for (long long* a = begin; a < end; a++)
    {
        for (long long* b = begin; b < end; b++)
        {
            if (!math_is_cyclic(*a, *b))
            {
                continue;
            }

            for (long long* c = begin; c < end; c++)
            {
                if (!math_is_cyclic(*b, *c))
                {
                    continue;
                }

                for (long long* d = begin; d < end; d++)
                {
                    if (!math_is_cyclic(*c, *d))
                    {
                        continue;
                    }

                    for (long long* e = begin; e < end; e++)
                    {
                        if (!math_is_cyclic(*d, *e))
                        {
                            continue;
                        }

                        for (long long* f = begin; f < end; f++)
                        {
                            if (!math_is_cyclic(*e, *f) || 
                                !math_is_cyclic(*f, *a))
                            {
                                continue;
                            }

                            int values[] = { *a, *b, *c, *d, *e, *f };
                            
                            if (!math_is_permuted_polygonal(values))
                            {
                                continue;
                            }

                            return *a + *b + *c + *d + *e + *f;
                        }
                    }
                }
            }
        }
    }

    return -1;
}

int main(void)
{
    struct List polygonals;
    clock_t start = clock();
    Exception ex = list(&polygonals, 0);

    euler_ok();

    for (int x = 1000; x < 10000; x++)
    {
        if (math_is_octagonal_or_smaller_polygonal(x))
        {
            list_add(&polygonals, x);
        }
    }

    int sum = math_cyclic_polygonal_sum(&polygonals);

    finalize_list(&polygonals);
    euler_submit(61, sum, start);
}
