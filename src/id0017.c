// Licensed under the MIT License.

// Number Letter Counts

#include "../lib/euler.h"

int main(void)
{
    int ones[] = { 3, 3, 5, 4, 4, 3, 5, 5, 4 };
    int teens[] = { 3, 6, 6, 8, 8, 7, 7, 9, 8, 8 };
    int tens[] = { 6, 6, 5, 5, 5, 7, 6, 6 };
    int sumOfOnes = 0;
    int sumOfTeens = 0;
    int sumOfTens = 0;
    clock_t start = clock();

    for (int i = 0; i < 9; i++)
    {
        sumOfOnes += ones[i];    
    }   

    for (int i = 0; i < 10; i++)
    {
        sumOfTeens += teens[i];
    }

    for (int i = 0; i < 8; i++)
    {
        sumOfTens += tens[i];
    }

    int sum = 
        ones[0] + // one
        8 + // thousand
        sumOfOnes * 100 + // one, two, three, ...nine
        7 * 9 * 100 + // hundred
        3 * 9 * 99 + // and
        sumOfTens * 100 + // twenty, thirty, fourty, ...ninety
        sumOfTeens * 10 + // ten, eleven, twelve, ...nineteen
        sumOfOnes * 90; // one, two, three, ...nine
    euler_submit(17, sum, start);
}
