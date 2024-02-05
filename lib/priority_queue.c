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

    char* items = instance->items;
    char* keys = instance->priorities;
    size_t i = instance->count;
    size_t itemSize = instance->itemSize;
    size_t keySize = instance->prioritySize;
    Comparer compare = instance->priorityComparer;

    while (i != 1 && compare(priority, keys + i * keySize / 2) < 0)
    {
        size_t j = i / 2;

        memcpy(items + i * itemSize, items + j * itemSize, itemSize);
        memcpy(keys + i * keySize, keys + j * keySize, keySize);

        i = j;
    }

    memcpy(items + i * itemSize, item, instance->itemSize);
    memcpy(keys + i * keySize, priority, instance->prioritySize);

    return 0;
}

bool priority_queue_try_dequeue(
    PriorityQueueElement result, 
    PriorityQueue instance)
{
	size_t i = 1;
    size_t child = 2;

    if (!instance->count)
    {
        return false;
    }

    char* items = instance->items;
    char* keys = instance->priorities;
    size_t itemSize = instance->itemSize;
    size_t keySize = instance->prioritySize;
    Comparer compare = instance->priorityComparer;

    instance->count--;

    memcpy(result->item, items + itemSize, itemSize);
    memcpy(result->priority, keys + keySize, keySize);
    memcpy(items, items + instance->count * itemSize, itemSize);
    memcpy(keys, keys + instance->count * keySize, keySize);

	while (child <= instance->count)
    {
		if (child < instance->count &&
            compare(keys + child * keySize, keys + (child + 1) * keySize) > 0)
        {
			child++;
		}

		if (compare(keys, keys + child * keySize) <= 0) 
        {
			break;
		}

        memcpy(items + i * itemSize, items + child * itemSize, itemSize);
        memcpy(keys + i * keySize, keys + child * keySize, keySize);

		i = child;
		child *= 2;
	}

    memcpy(items + i * itemSize, items, itemSize);
    memcpy(keys + i * keySize, keys, keySize);

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
