#include <gmp.h>
#include "../lib/euler.h"

int main(void)
{
    mpz_t q;
    mpz_t a[3];
    mpz_t b[3];
    int count = 1;
    clock_t start = clock();

    mpz_init_set_ui(a[0], 2);
    mpz_init(a[1]);
    mpz_init(a[2]);
    mpz_init_set_ui(b[0], 1);
    mpz_init(b[1]);
    mpz_init(b[2]);
    mpz_init(q);

    for (int i = 0; i < 92; i++)
    {
        mpz_add(q);
        mpz_add(a[2], a[0], q);
        mpz_set(a[0], a[1]);
        mpz_set(b[0], b[1]);

        if (math_huge_length(a[0]) > math_huge_length(b[0]))
        {
            count++;
        }
    }

    mpz_clear(a[0]);
    mpz_clear(a[1]);
    mpz_clear(b[0]);
    mpz_clear(b[1]);

    return euler_submit(57, count, start);
}
