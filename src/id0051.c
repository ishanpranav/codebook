#include <string.h>
#include "../lib/euler.h"
#include "../lib/lp_string.h"
#include "../lib/prime_list.h"

void mask_list_replace(List value, long oldItem, long newItem)
{
    for (long* it = value->begin; it < value->end; it++)
    {
        if (*it == oldItem)
        {
            *it = newItem;
        }
    }
}

bool mask_list_mask(List value)
{
    int counts[10] = { 0 };

    for (long* it = value->begin; it < value->end; it++)
    {
        counts[*it]++;
    }

    if (counts[0] >= 2)
    {
        mask_list_replace(value, 0, -1);

        return true;
    }

    if (counts[1] >= 2)
    {
        mask_list_replace(value, 1, -1);

        return true;
    }

    if (counts[2] >= 2)
    {
        mask_list_replace(value, 2, -1);

        return true;
    }

    return false;
}

Exception math_prime_digit_replacement(
    PrimeList primes,
    List mask,
    List image,
    long* first)
{
    long length;

    for (long* p = primes->primes.begin; p < primes->primes.end; p++)
    {
        *first = 0;
        length = 0;

        char str[10];

        sprintf(str, "%ld", *p);
        list_clear(mask);

        for (char* q = str; *q; q++)
        {
            Exception ex = list_add(mask, *q - '0');

            if (ex)
            {
                return ex;
            }
        }

        if (!mask_list_mask(mask))
        {
            continue;
        }

        for (int i = 0; i < 10; i++)
        {
            list_clear(image);

            for (long* it = mask->begin; it < mask->end; it++)
            {
                Exception ex;

                if (*it == -1)
                {
                    ex = list_add(image, i);
                }
                else
                {
                    ex = list_add(image, *it);
                }

                if (ex)
                {
                    return ex;
                }
            }
            
            long n = 0;

            for (long* q = image->begin; q < image->end; q++)
            {
                n = n * 10 + *q;
            }

            if (n <= 100000 || !prime_list_is_prime(primes, n))
            {
                continue;
            }

            if (!length)
            {
                *first = n;
            }

            length++;
        }

        if (length == 8)
        {
            return 0;
        }
    }

    return 1;
}

int main(void)
{
    struct PrimeList primes;
    clock_t start = clock();
    Exception ex = prime_list(&primes, 1000000l);

    euler_ok();

    struct List mask;

    ex = list(&mask, 0);

    euler_ok();

    struct List image;

    ex = list(&image, 0);

    long first;

    ex = math_prime_digit_replacement(&primes, &mask, &image, &first);

    euler_ok();

    finalize_prime_list(&primes);
    finalize_list(&mask);
    finalize_list(&image);

    return euler_submit(51, first, start);
}
