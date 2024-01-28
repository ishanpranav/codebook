#include "../lib/euler.h"

#include <stdlib.h>
#include "../lib/object.h"

struct Q {
    long a;
    long b;
};

typedef struct Q Q;

int cmp(Object l, Object r) {
    const struct Q x = *(const struct Q*)l;
    const struct Q y = *(const struct Q*)r;
    double xValue = (double)x.a / x.b;
    double yValue = (double)y.a / y.b;

    if (xValue < yValue)
    {
        return -1;
    }

    if (xValue > yValue)
    {
        return 1;
    }

    return 0;
}

int main(void)
{
    clock_t start = clock();
    // Q* arr = malloc(499999500000 * sizeof * arr);
    Q arr[1];
    Q item = {
        .a = 3,
        .b = 7
    };
    long ct = 0;

    for (long d = 1; d <= 1000000l; d++)
    {
        for (long n = 1; n < d; n++)
        {
            // arr[ct].a = n;
            // arr[ct].b = d;

        //  printf("%ld %ld/%ld\n", ct + 1, arr[ct].a, arr[ct].b);
            ct++;
        }
    }

    printf("%ld\n", ct);
exit(1);
    qsort(arr, ct, sizeof * arr, cmp);
    
    Q* mid = bsearch(&item, arr, ct, sizeof * arr, cmp);

    if (!mid) {
        return 1;
    }

    // mid--;
    

    // Q* left = arr;
    // Q* right = arr + 27;
    // Q* mid;

    // while (left != right)
    // {
    //     mid = left + (right - left) / 2;

    //     if (cmp(mid, &item) < 0)
    //     {
    //         left = mid + 1;
    //     }
    //     else
    //     {
    //         right = mid;
    //     }
    // }

    // for (Q* mid = arr; mid < arr + 27; mid++) {
    //     if (cmp(mid, &item) == 0) {
            
    //     }
    // }

    printf("%ld/%ld\n\n", mid->a, mid->b);

    for (long i = 0; i < ct; i++) {
        printf("%ld %ld/%ld\n", i + 1, arr[i].a, arr[i].b);
    }

    return euler_submit(72, 0, start);
}
