// Licensed under the MIT License.

#include <stdlib.h>
#include "euler.h"
#include "list.h"
#include "object.h"

Exception list(List instance, size_t capacity)
{
    if (capacity < 4)
    {
        capacity = 4;
    }

    instance->begin = malloc(capacity * sizeof * instance->begin);

    if (!instance->begin)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->end = instance->begin;
    instance->capacity = capacity;

    return 0;
}

void list_from_array(List instance, long long values[], size_t length)
{
    instance->begin = values;
    instance->end = values + length;
    instance->capacity = length;
}

Exception list_add(List instance, long long item)
{
    size_t length = instance->end - instance->begin;

    if (length + 1 > instance->capacity)
    {
        long long* newBegin;
        size_t newCapacity = instance->capacity * 2;
        size_t newSize = newCapacity * sizeof * newBegin;

        newBegin = realloc(instance->begin, newSize);

        if (!newBegin)
        {
            return EXCEPTION_OUT_OF_MEMORY;
        }

        instance->capacity = newCapacity;
        instance->begin = newBegin;
        instance->end = newBegin + length;
    }

    *instance->end = item;
    instance->end++;

    return 0;
}

bool list_contains(List instance, long long item)
{
    for (long long* it = instance->begin; it < instance->end; it++)
    {
        if (*it == item)
        {
            return true;
        }
    }

    return false;
}

void list_clear(List instance)
{
    instance->end = instance->begin;
}

static int long_long_compare(Object left, Object right)
{
    long long leftValue = *(long long*)left;
    long long rightValue = *(long long*)right;

    if (leftValue < rightValue)
    {
        return -1;
    }

    if (leftValue > rightValue)
    {
        return 1;
    }

    return 0;
}

void list_sort(List instance)
{
    qsort(
        instance->begin,
        instance->end - instance->begin,
        sizeof * instance->begin,
        long_long_compare);
}

void list_reverse(List instance)
{
    if (instance->begin == instance->end)
    {
        return;
    }

    long long* left = instance->begin;
    long long* right = instance->end - 1;
    
    while (left < right)
    {
        euler_swap(left, right);

        left++;
        right--;
    }
}

bool list_equals(List left, List right)
{
    size_t length = left->end - left->begin;
    
    if ((size_t)(right->end - right->begin) != length)
    {
        return false;
    }

    for (size_t i = 0; i < length; i++)
    {
        if (left->begin[i] != right->begin[i])
        {
            return false;
        }
    }

    return true;
}

long long list_sum(List instance)
{
    long long result = 0;

    for (long long* it = instance->begin; it < instance->end; it++)
    {
        result += *it;
    }

    return result;
}

void finalize_list(List instance)
{
    free(instance->begin);

    instance->begin = NULL;
    instance->end = NULL;
    instance->capacity = 0;
}
