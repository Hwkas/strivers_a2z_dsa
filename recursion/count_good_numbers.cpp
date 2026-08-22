#include <iostream>

const int MOD = 1e9 + 7;

long long power(long long x, long long y)
{
    if (y == 0)
    {
        return 1;
    }

    if (y == 1)
    {
        return x % MOD;
    }

    if (y % 2 == 0)
    {
        return power(((x * x) % MOD), y / 2);
    }
    return x * power(x, y - 1) % MOD;
}

int countGoodNumbers(long long n)
{
    long long odd_index_count = n / 2;
    long long even_index_count = (n + 1) / 2;

    return (power(5, even_index_count) * power(4, odd_index_count)) % MOD;
}

int main()
{
    int long long n = 5;
    std::cout << "The total number of good digit strings of length " << n << " is " << countGoodNumbers(n) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/count-good-numbers/