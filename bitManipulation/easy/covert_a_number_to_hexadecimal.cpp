#include <iostream>

std::string toHex(int num)
{
    if (num == 0)
    {
        return "0";
    }
    std::string ans = "";
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

    long n = num;
    if (num < 0)
    {
        // both are same
        n = (1LL << 32) + num;
        // unsigned n = num;
    }
    std::cout << n << std::endl;
    while (n > 0)
    {
        // n &= 15 == n %= 16
        ans = arr[n & 15] + ans;
        // n >> 4 == n / 16
        n >>= 4;
    }
    return ans;
}

int main()
{
    std::cout << toHex(0) << std::endl;
    return 0;
}

// https://leetcode.com/problems/convert-a-number-to-hexadecimal/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY