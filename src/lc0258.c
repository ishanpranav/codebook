// Licensed under the MIT License.

// Add Digits

int addDigits(int n) 
{
    if (!n)
    {
        return 0;
    }

    int mod = n % 9;

    if (!mod)
    {
        return 9;
    }

    return mod;
}
