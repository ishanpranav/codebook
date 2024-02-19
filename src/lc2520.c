// Licensed under the MIT License.

// Count the Digits That Divide a Number

int countDigits(int n)
{
    int result = 0;
    
    for (int k = n; k; k /= 10)
    {
        if (n % (k % 10) == 0)
        {
            result++;
        }
    }

    return result;
}
