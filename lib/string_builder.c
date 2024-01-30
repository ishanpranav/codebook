// Licensed under the MIT License.

#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_builder.h"

Exception string_builder(StringBuilder instance, size_t capacity)
{
    if (capacity < 4)
    {
        capacity = 4;
    }

    instance->buffer = malloc(capacity + 1);

    if (!instance->buffer)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    instance->length = 0;
    instance->capacity = capacity;
    instance->buffer[0] = '\0';

    return 0;
}

void string_builder_from_string(StringBuilder instance, String value)
{
    instance->buffer = value;
    instance->length = strlen(value);
    instance->capacity = 0;
}

Exception string_builder_ensure_capacity(
    StringBuilder instance,
    size_t capacity)
{
    if (instance->capacity >= capacity)
    {
        return 0;
    }

    size_t newCapacity = (instance->capacity - 1) * 2;

    if (capacity > newCapacity)
    {
        newCapacity = capacity;
    }

    char* newBuffer = realloc(instance->buffer, newCapacity + 1);

    if (!newBuffer)
    {
        return EXCEPTION_OUT_OF_MEMORY;
    }

    newBuffer[instance->length + 1] = '\0';
    instance->capacity = newCapacity;
    instance->buffer = newBuffer;

    return 0;
}

Exception string_builder_append_char(StringBuilder instance, char item)
{
    size_t newCount = instance->length + 1;
    Exception ex = string_builder_ensure_capacity(instance, newCount);

    if (ex)
    {
        return ex;
    }

    instance->buffer[instance->length] = item;
    instance->length++;
    instance->buffer[instance->length] = '\0';

    return 0;
}

Exception string_builder_append_string(StringBuilder instance, String value)
{
    size_t length = strlen(value);
    size_t newCount = instance->length + length;
    Exception ex = string_builder_ensure_capacity(instance, newCount);

    if (ex)
    {
        return ex;
    }

    memcpy(instance->buffer + instance->length, value, length);

    instance->length += length;
    instance->buffer[instance->length] = '\0';

    return 0;
}

Exception string_builder_append_format(
    StringBuilder instance,
    String format,
    ...)
{
    va_list argl;

    va_start(argl, format);

    int size = vsnprintf(NULL, 0, format, argl);

    va_end(argl);

    if (size < 1)
    {
        return EXCEPTION_FORMAT;
    }

    size_t capacity = instance->length + size + 1;
    Exception ex = string_builder_ensure_capacity(instance, capacity);

    if (ex)
    {
        return ex;
    }

    va_start(argl, format);

    int newSize = vsprintf(instance->buffer + instance->length, format, argl);

    va_end(argl);

    if (size != newSize)
    {
        return EXCEPTION_FORMAT;
    }

    instance->length += size;

    return 0;
}

void string_builder_clear(StringBuilder instance)
{
    instance->length = 0;
}

String string_builder_to_string(StringBuilder instance)
{
    String result = malloc((instance->length + 1) * sizeof * result);

    if (!result)
    {
        return NULL;
    }

    memcpy(result, instance->buffer, instance->length);

    result[instance->length] = '\0';

    return result;
}

bool string_builder_equals(StringBuilder left, StringBuilder right)
{
    if (left->length != right->length)
    {
        return false;
    }

    return memcmp(left->buffer, right->buffer, left->length) == 0;
}

void finalize_string_builder(StringBuilder instance)
{
    free(instance->buffer);

    instance->buffer = NULL;
    instance->length = 0;
    instance->capacity = 0;
}
