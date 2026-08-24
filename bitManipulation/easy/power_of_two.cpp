#include <iostream>

bool isPowerOfTwo(int n)
{
    return (n > 0) && !(n & (n - 1));
}

int main()
{
    std::cout << (isPowerOfTwo(4) ? "True" : "False") << std::endl;
    return 0;
}

// https://leetcode.com/problems/power-of-two/