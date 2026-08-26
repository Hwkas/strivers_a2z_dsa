#include <iostream>

int minBitFlips(int start, int goal)
{
    int _xor = start ^ goal, count = 0;

    while (_xor > 0)
    {
        count += _xor & 1;
        _xor >>= 1;
    }

    return count;
}

int main()
{
    std::cout << minBitFlips(10, 7) << std::endl;
    return 0;
}

// https://leetcode.com/problems/minimum-bit-flips-to-convert-number/submissions/2121192502/