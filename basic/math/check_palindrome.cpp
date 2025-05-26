#include <iostream>

bool isPalindrome(int x)
{
    if (x < 0)
    {
        return false;
    }

    long y = 0, z = x;

    while (z > 0)
    {
        y = (y * 10) + (z % 10);
        z /= 10;
    }
    return x == y;
}

int main()
{
    std::cout << "ans: " << isPalindrome(121) << std::endl;
    return 0;
}

// https://leetcode.com/problems/palindrome-number/description/