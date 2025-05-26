#include <iostream>

int reverse(int x)
{
    long y = 0, z = x;
    bool signed_int = false;

    if (z < 0)
    {
        z *= -1;
        signed_int = true;
    }

    while (z > 0)
    {
        y = (y * 10) + (z % 10);
        z /= 10;
    }

    if (y > INT_MAX)
    {
        return 0;
    }
    return (signed_int ? y * -1 : y);
}

int main()
{
    std::cout << "ans: " << reverse(7789) << std::endl;
    return 0;
}

// https://leetcode.com/problems/reverse-integer/