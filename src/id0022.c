// Licensed under the MIT License.

// Names Scores

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "../lib/euler.h"
#include "../lib/lp_string.h"

int main(void)
{
    char buffer[65536];
    clock_t start = clock();
    int read = fread(buffer, 1, sizeof buffer, stdin);

    assert(read != 0);

    long sum = 0;
    int count = 0;
    LPString names[8192];

    for (LPString tok = strtok(buffer, "\","); tok; tok = strtok(NULL, "\","))
    {
        names[count] = lp_string_clone(tok);
        count++;
    }

    qsort(names, count, sizeof * names, lp_string_compare);

    for (int i = 0; i < count; i++)
    {
        int rank = 0;

        for (char* p = names[i]; *p; p++)
        {
            rank += *p - 'A' + 1;
        }

        sum += rank * (i + 1);

        free(names[i]);
    }

    return euler_submit(22, sum, start);
}
