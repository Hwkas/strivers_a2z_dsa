#include <iostream>

int hammingWeight(int n)
{
    int temp = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            temp++;
        }
        n >>= 1;
    }
    return temp;
}

int main()
{
    int n = 2147483645;
    std::cout << "ans: " << hammingWeight(n) << std::endl;
    return 0;
}

// https://leetcode.com/problems/number-of-1-bits/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY