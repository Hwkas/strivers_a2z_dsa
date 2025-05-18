#include <iostream>

// solution O(n), where n = 31
// bool isPowerOfFour(int n)
// {
//     int count = 0;
//     // using long for the case of INT_MIN
//     long temp = n;
//     if (temp && !(temp & (temp - 1)))
//     {
//         while (temp > 1)
//         {
//             temp >>= 1;
//             count += 1;
//         }
//         return (count % 2 == 0) ? true : false;
//     }
//     return false;
// }

bool isPowerOfFour(int n)
{
    if (n == 1)
    {
        return true;
    }
    // using long for the case of INT_MIN
    long temp = n;
    return ((temp && !(temp & (temp - 1))) &&
            (temp % 10 == 4 || temp % 10 == 6))
               ? true
               : false;
}

int main()
{
    int n = 8;
    std::cout << (isPowerOfFour(n) ? "True" : "False") << std::endl;
    return 0;
}

// https://leetcode.com/problems/power-of-four/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY