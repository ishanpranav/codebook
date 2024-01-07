#include "euler.h"

int math_gaussian_sum(int n)
{
    return n * (n + 1) / 2;
}

int main(void)
{
    clock_t start = clock();
    int sum = (3 * math_gaussian_sum(999 / 3)) +
        (5 * math_gaussian_sum(999 / 5)) -
        (15 * math_gaussian_sum(999 / 15));

    euler_submit(sum, start);

    return 0;
}
