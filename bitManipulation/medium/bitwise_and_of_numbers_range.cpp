#include <iostream>

int rangeBitwiseAnd(int left, int right)
{
    /*
        The logic here is that, for every range of numbers only the most significat common set bits will 
        set after the bitwise & operation, rest will become 0, so if we shift both left & right to a point
        where they become equal & count the number of right shift operation & 
        then left shift the number to that count will be ans.

        13 = 1101 >> 1 = 110 >> 1 = 11
        15 = 1111 >> 1 = 111 >> 1 = 11
        Number of right shift operations = 2
        ans = 11 << 2 = 1100 
        verify = 1101 & 1111 = 1100
    */
    int count = 0;
    while (left != right)
    {
        left >>= 1;
        right >>= 1;
        count++;
    }
    return (left << count);
}

int main()
{
    std::cout << "ans: " << rangeBitwiseAnd(2147483646, 2147483647) << std::endl;
    return 0;
}

// https://leetcode.com/problems/bitwise-and-of-numbers-range/?envType=problem-list-v2&envId=bit-manipulation