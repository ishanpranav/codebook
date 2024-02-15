// Licensed under the MIT License.

// Arithmetic Expressions

#include "../lib/combination_iterator.h"
#include "../lib/euler.h"

int main(void)
{
    struct CombinationIterator it;
    int subset[2];

    for (combination_begin(&it, subset, 4, 2); !it.end; combination_next(&it))
    {
        printf("=> ");

        for (int i = 0; i < 2; i++)
        {
            printf("%zu ", subset[i]);
        }
        
        printf("\n");
    }

    return 0;
}
