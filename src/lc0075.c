// Licensed under the MIT License.

// Sort Colors

#include "../lib/comparer.h"

void sortColors(int items[], int length) 
{
    qsort(items, length, sizeof * items, int_comparer);
}
