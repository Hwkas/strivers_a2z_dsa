#include <iostream>

// int getSum(int a, int b)
// {
//     if (((a ^ b) == (a | b)))
//     {
//         return (a | b);
//     }

//     int ans = 0, count = 0, carry = 0;

//     while (count < 32)
//     {
//         if ((a & 1) == (b & 1))
//         {
//             if (carry)
//             {
//                 ans |= (1 << count);
//                 carry--;
//             }
//             if (a & 1)
//             {
//                 carry++;
//             }
//         }
//         else if (!carry)
//         {
//             ans |= (1 << count);
//         }
//         count++;
//         a >>= 1;
//         b >>= 1;
//     }

//     return ans;
// }

// More consinge solution
int getSum(int a, int b)
{
    return b == 0 ? a : getSum(a ^ b, (a & b) << 1);
}

int main()
{
    std::cout << "sum: " << getSum(-1, -2) << std::endl;
    return 0;
}

// https://leetcode.com/problems/sum-of-two-integers/description/?envType=problem-list-v2&envId=bit-manipulation