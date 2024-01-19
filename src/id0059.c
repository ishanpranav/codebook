// Licensed under the MIT License.

// XOR Decryption

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/euler.h"
#include "../lib/lp_string_builder.h"

int main(void)
{
    char buffer[8192];
    clock_t start = clock();
    int read = fread(buffer, 1, sizeof buffer, stdin);

    assert(read != 0);
    assert(!ferror(stdin));

    struct LPStringBuilder message;

    Exception ex = lp_string_builder(&message, 0);

    euler_ok();

    for (LPString tok = strtok(buffer, ","); tok; tok = strtok(NULL, ","))
    {
        ex = lp_string_builder_append_char(&message, strtol(tok, NULL, 10));

        euler_ok();
    }

    int i = 0;
    int frequencies[3][256] = { 0 };
    char key[3] = { 0 };

    for (char* it = message.begin; it < message.end; it++)
    {
        int* frequency = frequencies[i] + *it;

        *frequency = *frequency + 1;

        if (*frequency > frequencies[i][(int)key[i]])
        {
            key[i] = *it;
        }

        i++;

        if (i == 3)
        {
            i = 0;
        }
    }

    for (i = 0; i < 3; i++)
    {
        key[i] ^= ' ';
    }

    long sum = 0;

    for (char* it = message.begin; it < message.end; it++)
    {
        if (i == 3)
        {
            i = 0;
        }

        sum += *it ^ key[i];
        i++;
    }

    return euler_submit(59, sum, start);
}
