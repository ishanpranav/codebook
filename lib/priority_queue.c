#include "priority_queue.h"

Exception priority_queue(
    PriorityQueue instance, 
    size_t itemSize, 
    size_t capacity)
{
    return list(instance, itemSize, capacity);
}

static void priority_queue_swap(
    struct PriorityQueueElement heap[], 
    size_t i, 
    size_t j)
{
    struct PriorityQueueElement swap;

    swap = heap[i];
    heap[i] = heap[j];
    heap[j] = swap;
}

static void priority_queue_sift_up(PriorityQueue instance, size_t index)
{
    struct PriorityQueueElement* heap = instance->items;
    int priority = heap[index - 1].priority;

    while (heap[index / 2].priority > priority)
    {
        priority_queue_swap(heap, index - 1, index / 2 - 1);

        index /= 2;
    }
}

static bool priority_queue_test(PriorityQueue instance, size_t index)
{
    struct PriorityQueueElement* heap = instance->items;
    int priority = heap[index - 1].priority;

    if (priority > heap[index * 2 - 1].priority)
    {
        return false;
    }

    size_t min = index * 2;

    if (instance->count < min)
    {
        min = instance->count;
    }

    return priority <= heap[min - 1].priority;
}

static void priority_queue_sift_down(PriorityQueue instance, size_t index)
{
    struct PriorityQueueElement* heap = instance->items;

    while (2 * index <= instance->count && 
        !priority_queue_test(instance, index))
    {
        if (2 * index < instance->count &&
            heap[index * 2].priority < heap[index * 2 - 1].priority)
        {
            priority_queue_swap(heap, index - 1, 2 * index);

            index = 2 * index + 1;
        }
        else
        {
            priority_queue_swap(heap, index - 1, 2 * index - 1);

            index *= 2;
        }
    }
}

static void priority_queue_remove_at(PriorityQueue instance, size_t index)
{
    struct PriorityQueueElement* heap = instance->items;

    heap[index - 1] = heap[instance->count - 1];
    instance->count--;

    if (heap[index - 1].priority < heap[index / 2 - 1].priority)
    {
        priority_queue_sift_up(instance, index);
    }
    else
    {
        priority_queue_sift_down(instance, index);
    }
}

bool priority_queue_try_dequeue(
    PriorityQueueElement result, 
    PriorityQueue instance)
{
    if (!instance->count)
    {
        return false;
    }

    struct PriorityQueueElement* heap = instance->items;

    *result = heap[0];

    priority_queue_remove_at(instance, 0);

    return true;
}

Exception priority_queue_enqueue(
    PriorityQueue instance, 
    Object item, 
    int priority)
{
    struct PriorityQueueElement element =
    {
        .item = item,
        .priority = priority
    };

    Exception ex = list_add(instance, &element);

    if (ex)
    {
        return ex;
    }

    priority_queue_sift_up(instance, instance->count);

    return 0;
}
