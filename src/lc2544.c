// Licensed under the MIT License.

// Alternating Digit Sum

int alternateDigitSum(int n) 
{
    int sign = 1;
    int result = 0;

    for (int k = n; k; k /= 10)
    {
        sign = -sign;
        result += sign * (k % 10);
    }

    return result;
}
