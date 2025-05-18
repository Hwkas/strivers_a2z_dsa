#include <iostream>

// my solution
// int findComplement(int num)
// {
//     int temp = num, ans = 0;
//     while (temp > 0)
//     {
//         temp >>= 1;
//         ans = (ans << 1) | 1;
//     }
//     return num ^ ans;
// }

// optimized solution
int findComplement(int num)
{
    for (long i = 1; i <= num; i <<= 1)
    {
        num ^= i;
    }
    return num;
}

int main()
{
    std::cout << findComplement(5) << std::endl;
    return 0;
}

// https://leetcode.com/problems/number-complement/description/?envType=problem-list-v2&envId=bit-manipulation