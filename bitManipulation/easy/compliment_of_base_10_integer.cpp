#include <iostream>

int bitwiseComplement(int n)
{
    if (n == 0)
    {
        return 1;
    }

    for (int i = 1; i <= n; i <<= 1)
    {
        n ^= i;
    }
    return n;
}

int main()
{
    std::cout << "ans: " << bitwiseComplement(0) << std::endl;
    return 0;
}

// https://leetcode.com/problems/complement-of-base-10-integer/?envType=problem-list-v2&envId=bit-manipulation