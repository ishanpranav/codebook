// Licensed under the MIT License.

#include <stdlib.h>
#include <string.h>
#include "priority_queue.h"

Exception priority_queue(
    PriorityQueue instance,
    size_t itemSize,
    size_t prioritySize,
    size_t capacity,
    Comparer priorityComparer)
{
    if (capacity < 4)
    {
        capacity = 4;
    }

    instance->items = malloc((capacity + 1) * itemSize);

    if (!instance->items)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->priorities = malloc((capacity + 1) * prioritySize);

    if (!instance->priorities)
    {
        free(instance->items);

        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->itemSize = itemSize;
    instance->prioritySize = prioritySize;
    instance->count = 0;
    instance->capacity = capacity;
    instance->priorityComparer = priorityComparer;

    return 0;
}

Exception priority_queue_ensure_capacity(
    PriorityQueue instance,
    size_t capacity)
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

    void* newItems = realloc(
        instance->items,
        (newCapacity + 1) * instance->itemSize);

    if (!newItems)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    void* newPriorities = realloc(
        instance->priorities,
        (newCapacity + 1) * instance->prioritySize);

    if (!newPriorities)
    {
        instance->items = realloc(
            instance->items,
            (instance->capacity + 1) * instance->itemSize);

        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->capacity = newCapacity;
    instance->items = newItems;
    instance->priorities = newPriorities;

    return 0;
}

Exception priority_queue_enqueue(
    PriorityQueue instance,
    Object item,
    Object priority)
{
    Exception ex = priority_queue_ensure_capacity(
        instance,
        instance->count + 1);

    if (ex)
    {
        return ex;
    }

    instance->count++;

    char* p = instance->items;
    char* q = instance->priorities;
    size_t i = instance->count;
    size_t itemSize = instance->itemSize;
    size_t prioritySize = instance->prioritySize;
    Comparer compare = instance->priorityComparer;

    while (i != 1 && compare(priority, q + (i / 2) * prioritySize) < 0)
    {
        size_t j = i / 2;

        memcpy(p + i * itemSize, p + j * itemSize, itemSize);
        memcpy(q + i * prioritySize, q + j * prioritySize, prioritySize);

        i = j;
    }

    if (item)
    {
        memcpy(p + i * itemSize, item, instance->itemSize);
    }

    if (priority)
    {
        memcpy(q + i * prioritySize, priority, instance->prioritySize);
    }

    return 0;
}

bool priority_queue_try_dequeue(
    PriorityQueue instance,
    Object item,
    Object priority)
{
    size_t i = 1;
    size_t child = 2;

    if (!instance->count)
    {
        return false;
    }

    char* p = instance->items;
    char* q = instance->priorities;
    size_t itemSize = instance->itemSize;
    size_t prioritySize = instance->prioritySize;
    Comparer compare = instance->priorityComparer;

    if (item)
    {
        memcpy(item, p + itemSize, itemSize);
    }

    if (priority)
    {
        memcpy(priority, q + prioritySize, prioritySize);
    }

    memcpy(p, p + instance->count * itemSize, itemSize);
    memcpy(q, q + instance->count * prioritySize, prioritySize);

    while (child < instance->count)
    {
        if (child < instance->count - 1 && compare(
            q + child * prioritySize, 
            q + (child + 1) * prioritySize) > 0)
        {
            child++;
        }

        if (compare(q, q + child * prioritySize) <= 0)
        {
            break;
        }

        memcpy(p + i * itemSize, p + child * itemSize, itemSize);
        memcpy(q + i * prioritySize, q + child * prioritySize, prioritySize);

        i = child;
        child *= 2;
    }

    memcpy(p + i * itemSize, p, itemSize);
    memcpy(q + i * prioritySize, q, prioritySize);

    instance->count--;

    return true;
}

void finalize_priority_queue(PriorityQueue instance)
{
    free(instance->items);
    free(instance->priorities);

    instance->items = NULL;
    instance->itemSize = 0;
    instance->priorities = NULL;
    instance->prioritySize = 0;
    instance->count = 0;
    instance->capacity = 0;
    instance->priorityComparer = NULL;
}
