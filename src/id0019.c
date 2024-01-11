// Licensed under the MIT License.

// Counting Sundays

#include "../lib/euler.h"

enum DayOfWeek
{
    DAY_OF_WEEK_SUNDAY = 0,
    DAY_OF_WEEK_TUESDAY = 2,
    DAY_OF_WEEK_NONE = 7
};

typedef enum DayOfWeek DayOfWeek;

int main(void)
{
    int count = 0;
    int calendar[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    DayOfWeek dayOfWeek = DAY_OF_WEEK_TUESDAY;
    clock_t start = clock();

    for (int year = 1901; year <= 2000; year++) 
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            calendar[1]++;
        }

        for (int month = 0; month < 12; month++) 
        {
            if (dayOfWeek == DAY_OF_WEEK_SUNDAY) 
            {
                count++;
            }

            dayOfWeek = (dayOfWeek + calendar[month]) % 7;
        }

        calendar[1] = 28;
    }

    return euler_submit(19, count, start);
}
