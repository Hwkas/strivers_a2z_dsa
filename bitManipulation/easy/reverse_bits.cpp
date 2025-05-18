#include <iostream>

uint32_t reverseBits(uint32_t n)
{
    uint32_t temp = 0;
    for (int i = 0; i < 32; i++)
    {
        temp <<= 1;
        if (n & 1)
        {
            temp |= 1;
        }
        n >>= 1;
    }
    return temp;
}

int main()
{
    uint32_t n = 43261596;
    std::cout << "ans: " << reverseBits(n) << std::endl;
    return 0;
}

// https://leetcode.com/problems/reverse-bits/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY