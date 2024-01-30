// Licensed under the MIT License.

// XOR Decryption

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/euler.h"
#include "../lib/string_builder.h"

int main(void)
{
    char buffer[8192];
    clock_t start = clock();
    int read = fread(buffer, 1, sizeof buffer, stdin);

    assert(read != 0);
    assert(!ferror(stdin));

    struct StringBuilder message;
    Exception ex = string_builder(&message, 0);

    euler_ok();

    for (String tok = strtok(buffer, ","); tok; tok = strtok(NULL, ","))
    {
        ex = string_builder_append_char(&message, strtol(tok, NULL, 10));

        euler_ok();
    }

    // Assume that the most frequent characters in the ciphertext represent
    // spaces, and construct the key accordingly.

    int i = 0;
    int frequencies[3][256] = { 0 };
    char key[3] = { 0 };

    for (size_t j = 0; j < message.length; j++)
    {
        int* frequency = frequencies[i] + message.buffer[j];

        *frequency = *frequency + 1;

        if (*frequency > frequencies[i][(int)key[i]])
        {
            key[i] = message.buffer[j];
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

    for (size_t j = 0; j < message.length; j++)
    {
        if (i == 3)
        {
            i = 0;
        }

        sum += message.buffer[j] ^ key[i];
        i++;
    }

    return euler_submit(59, sum, start);
}
