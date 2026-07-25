#include <iostream>

double power(double x, long n)
{
    if (n == 0)
    {
        return 1.0;
    }

    if (n == 1)
    {
        return x;
    }

    if (n % 2 == 0)
    {

        return power(x * x, n / 2);
    }

    return x * power(x, n - 1);
}

double myPow(double x, int n)
{
    return (n < 0) ? (1.0 / power(x, -1 * (long long)n)) : power(x, n);
}

int main()
{
    double x = 2.0;
    int n = 5;
    std::cout << x << " raised to the power " << n << " is " << pow(x, n) << std::endl;
    return 0;
}

// https://leetcode.com/problems/powx-n/submissions/2080821773/