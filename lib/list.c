// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "array.h"
#include "euler.h"
#include "list.h"
#include "object.h"
#include "swap.h"

Exception list(List instance, size_t itemSize, size_t capacity)
{
    if (capacity < 4)
    {
        capacity = 4;
    }

    instance->items = malloc(capacity * itemSize);

    if (!instance->items)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->itemSize = itemSize;
    instance->count = 0;
    instance->capacity = capacity;

    return 0;
}

Exception list_ensure_capacity(List instance, size_t capacity)
{
    if (instance->capacity >= capacity)
    {
        return 0;
    }

    size_t newCapacity = instance->capacity * 2;

    if (capacity > newCapacity)
    {
        newCapacity = capacity;
    }

    void* newItems = realloc(instance->items, newCapacity * instance->itemSize);

    if (!newItems)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->capacity = newCapacity;
    instance->items = newItems;

    return 0;
}

Exception list_add(List instance, Object item)
{
    Exception ex = list_ensure_capacity(instance, instance->count + 1);

    if (ex)
    {
        return ex;
    }

    void* end = (char*)instance->items + instance->count * instance->itemSize;

    if (item)
    {
        memcpy(end, item, instance->itemSize);
    }
    
    instance->count++;

    return 0;
}

Exception list_add_range(List instance, Object items, size_t count)
{
    Exception ex = list_ensure_capacity(instance, instance->count + count);

    if (ex)
    {
        return ex;
    }

    void* end = (char*)instance->items + instance->count * instance->itemSize;

    if (item)
    {
        memcpy(end, items, count * instance->itemSize);
    }
    
    instance->count += count;

    return 0;
}

Exception list_remove_at(List instance, size_t index)
{
    if (index < 0 || index >= instance->count)
    {
        return EXCEPTION_ARGUMENT_OUT_OF_RANGE;
    }

    instance->count--;

    if (index == instance->count)
    {
        return 0;
    }

    memmove(
        instance->items + index, 
        instance->items + index + 1, 
        (instance->count - index) * instance->itemSize);

    return 0;
}

bool list_contains(List instance, Object item, EqualityComparer itemComparer)
{
    char* begin = instance->items;
    char* end = begin + instance->count * instance->itemSize;

    for (char* it = begin; it < end; it += instance->itemSize)
    {
        if (itemComparer(it, item))
        {
            return true;
        }
    }

    return false;
}

void list_reverse(List instance)
{
    if (!instance->count)
    {
        return;
    }

    char* left = instance->items;
    char* right = left + (instance->count - 1) * instance->itemSize;

    while (left < right)
    {
        swap(left, right, instance->itemSize);

        left += instance->itemSize;
        right -= instance->itemSize;
    }
}

bool list_sequence_equal(List left, List right, EqualityComparer itemComparer)
{
    size_t itemSize = left->itemSize;

    if (right->itemSize != itemSize)
    {
        return false;
    }

    size_t count = left->count;
    
    if (right->count != count)
    {
        return false;
    }

    size_t length = count * itemSize;
    char* leftBegin = (char*)left->items;
    char* rightBegin = (char*)right->items;

    for (size_t offset = 0; offset < length; offset += itemSize)
    {
        if (itemComparer(leftBegin + offset, rightBegin + offset))
        {
            return false;
        }
    }

    return true;
}

void list_clear(List instance)
{
    instance->count = 0;
}

void finalize_list(List instance)
{
    list_clear(instance);
    free(instance->items);

    instance->items = NULL;
    instance->itemSize = 0;
    instance->capacity = 0;
}
