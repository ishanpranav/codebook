// Licensed under the MIT License.

#include <stdlib.h>
#include "binary_search.h"
/**
 * int ans = -1;
 
    while (low <= high) {
        int mid = low + (high - low + 1) / 2;
        int midVal = a[mid];
 
        if (midVal < key) {
 
            // if mid is less than key, all elements
            // in range [low, mid - 1] are <= key
            // then we search in right side of mid
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
        else if (midVal > key) {
 
            // if mid is greater than key, all elements
            // in range [mid + 1, high] are >= key
            // we note down the last found index, then 
            // we search in left side of mid
            // so we now search in [low, mid - 1]
            ans = mid;
            high = mid - 1;
        }
        else if (midVal == key) {
 
            // if mid is equal to key, all elements in
            // range [low, mid] are <= key
            // so we now search in [mid + 1, high]
            low = mid + 1;
        }
    }
 
    return ans;
*/

Object binary_search_min(
    Object min,
    Array items,
    size_t length,
    size_t itemSize,
    Comparer comparer)
{
    if (!length)
    {
        return NULL;
    }

    char* buffer = items;
    size_t left = 0;
    size_t right = length - 1;

    while (left < right)
    {
        size_t index = left + (right - left) / 2;
        int comparison = comparer(buffer + index * itemSize, min);

        if (comparison < 0)
        {
            left = index + 1;
        }
        else if (comparison > 0)
        {
            right = index;
        }
        else
        {
            return buffer + index * itemSize;
        }
    }

    return buffer + right * itemSize;
}

size_t binary_search_rank(
    Object max,
    Array items,
    size_t length,
    size_t itemSize,
    Comparer comparer)
{
    if (!length)
    {
        return 0;
    }

    char* buffer = items;
    size_t left = 0;
    size_t right = length - 1;
    size_t result = 0;

    while (left <= right)
    {
        size_t index = left + (right - left) / 2;

        if (comparer(buffer + index * itemSize, max) < 0)
        {
            result = index + 1;
            left = index + 1;
        }
        else
        {
            right = index - 1;
        }
    }

    return result;
}
