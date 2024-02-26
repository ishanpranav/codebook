// Licensed under the MIT License.

// Arithmetic Expressions

#include <stdarg.h>
#include <string.h>
#include "../lib/combination_iterator.h"
#include "../lib/euler.h"
#include "../lib/permutation_iterator.h"
#include "../lib/rpn.h"

void rpn_evaluate_formatted(bool results[], String format, ...)
{
    va_list argl;
    char buffer[8];
    char longBuffer[14];
    char* expression[7];

    va_start(argl, format);
    vsprintf(buffer, format, argl);
    va_end(argl);

    for (int i = 0; i < 7; i++)
    {
        longBuffer[i + i] = buffer[i];
        longBuffer[i + i + 1] = '\0';
        expression[i] = longBuffer + i + i;
    }

    int result = rpn_evaluate(expression, 7);

    if (result > 0 && !results[result])
    {
        results[result] = true;
    }
}

int math_arithmetic_expression_length(int digits[])
{
    bool results[1001] = { 0 };
    struct PermutationIterator it;

    for (permutation_begin(
        &it,
        digits,
        4,
        1,
        char_comparer);
        !it.end;
        permutation_next(&it))
    {
        char* operators = "+-*/";

        for (char* p = operators; *p; p++)
        {
            for (char* q = operators; *q; q++)
            {
                for (char* r = operators; *r; r++)
                {
                    rpn_evaluate_formatted(
                        results,
                        "%d%d%d%d%c%c%c",
                        digits[0], digits[1], digits[2], digits[3], *p, *q, *r);
                    rpn_evaluate_formatted(
                        results,
                        "%d%d%d%c%d%c%c",
                        digits[0], digits[1], digits[2], *p, digits[3], *q, *r);
                    rpn_evaluate_formatted(
                        results,
                        "%d%d%d%c%c%d%c",
                        digits[0], digits[1], digits[2], *p, *q, digits[3], *r);
                    rpn_evaluate_formatted(
                        results,
                        "%d%d%c%d%d%c%c",
                        digits[0], digits[1], *p, digits[2], digits[3], *q, *r);
                    rpn_evaluate_formatted(
                        results,
                        "%d%d%c%d%c%d%c",
                        digits[0], digits[1], *p, digits[2], *q, digits[3], *r);
                }
            }
        }
    }

    int result = 0;

    for (int i = 1; i < 1000; i++)
    {
        if (!results[i])
        {
            break;
        }

        result++;
    }

    return result;
}

int main(void)
{
    int maxLength = 0;
    int digits[4];
    int maxDigits[4] = { 0 };
    struct CombinationIterator it;
    clock_t start = clock();

    for (combination_begin(&it, digits, 9, 4);
        !it.end;
        combination_next(&it))
    {
        int length = math_arithmetic_expression_length(digits);

        if (length > maxLength)
        {
            maxLength = length;

            memcpy(maxDigits, digits, sizeof digits);
        }
    }

    int result = 0;

    for (int i = 0; i < 4; i++)
    {
        result = result * 10 + maxDigits[i];
    }

    return euler_submit(92, result, start);
}
