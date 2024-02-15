// Licensed under the MIT License.

// Find Smallest Letter Greater Than Target

#include "../lib/binary_search.h"

char nextGreatestLetter(char* letters, int lettersSize, char target) 
{
    if (target >= letters[lettersSize - 1]) 
    {
        target = letters[0];
    } 
    else 
    {
        target++;
    }

    return *(char*)binary_search_min(
        &target, 
        letters, 
        lettersSize, 
        sizeof * letters, 
        char_comparer);
}
