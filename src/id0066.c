// Licensed under the MIT License.

// Diophantine Equation

#include <gmp.h>
#include "../lib/euler.h"

int main(void)
{
    int maxD = -1;
    mpz_t huge, maxX, a, h, k, x[3], y[3];
    clock_t start = clock();

    mpz_inits(huge, maxX, a, h, k, x[0], x[1], x[2], y[0], y[1], y[2], NULL);

    for (int d = 2; d <= 1000; d++)
    {
        long isqrt;

        if (math_is_polygonal(4, d, &isqrt))
        {
            continue;
        }

        mpz_set_ui(a, isqrt);    // a := floor(sqrt(D))
        mpz_set_ui(h, 0);        // h := 0
        mpz_set_ui(k, 1);        // k := 1
        mpz_set_ui(x[0], 0);     // x := ( 0 )
        mpz_set_ui(x[1], 1);     // x := ( 0, 1 )
        mpz_set_ui(x[2], isqrt); // x := ( 0, 1, a )
        mpz_set_ui(y[0], 0);     // y := ( 0 )
        mpz_set_ui(y[1], 0);     // y := ( 0, 0 )
        mpz_set_ui(y[2], 1);     // y := ( 0, 0, 1 )

        do
        {
            mpz_submul(h, a, k);          // h := h - ak
            mpz_neg(h, h);                // h := ak - h
            mpz_set_ui(huge, d);          // _ := D
            mpz_submul(huge, h, h);       // _ := D - h^2
            mpz_tdiv_q(k, huge, k);       // k := (D - h^2) div k
            mpz_add_ui(a, h, isqrt);      // a := h + floor(sqrt(D))
            mpz_tdiv_q(a, a, k);          // a := (h + floor(sqrt(D))) div k
            mpz_set(x[0], x[1]);          // x_0 := x_1
            mpz_set(x[1], x[2]);          // x_1 := x_2
            mpz_mul(x[2], a, x[1]);       // x_2 := ax_1
            mpz_add(x[2], x[2], x[0]);    // x_2 := ax_1 + x_0
            mpz_set(y[0], y[1]);          // y_0 := y_1
            mpz_set(y[1], y[2]);          // y_1 := y_2
            mpz_mul(y[2], a, y[1]);       // y_2 := ay_1
            mpz_add(y[2], y[2], y[0]);    // y_2 := ay_1 + y_0
            mpz_mul(huge, y[2], y[2]);    // _ := y_2^2
            mpz_mul_ui(huge, huge, d);    // _ := Dy_2^2
            mpz_neg(huge, huge);          // _ := -Dy_2^2
            mpz_addmul(huge, x[2], x[2]); // _ := x_2^2 - Dy_2^2
        }
        while (mpz_cmp_ui(huge, 1) != 0); // UNTIL (x_2^2 - Dy_2^2) = 1

        if (mpz_cmp(x[2], maxX) > 0) // IF x_2 > max_x
        {
            maxD = d;

            mpz_set(maxX, x[2]); // max_x := x_2
        }
    }

    mpz_clears(huge, maxX, a, h, k, x[0], x[1], x[2], y[0], y[1], y[2], NULL);
    euler_submit(66, maxD, start);
}
