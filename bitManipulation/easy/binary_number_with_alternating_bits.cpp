#include <iostream>

// Solution 1
// bool hasAlternatingBits(int n)
// {
//     int temp = n & 1;
//     n >>= 1;
//     bool ans = true;
//     while (n > 0 && ans)
//     {
//         if (temp == (n & 1))
//         {
//             ans = false;
//         }
//         temp = n & 1;
//         n >>= 1;
//     }
//     return ans;
// }

// Solution 2
bool hasAlternatingBits(int n)
{
    n ^= (n >> 1);
    // type casting to long for the case of INT_MAX + 1
    return ((n & ((long)n + 1)) == 0);
}

int main()
{
    std::cout << "missing number is: " << hasAlternatingBits(1431655765) << std::endl;

    return 0;
}

// https://leetcode.com/problems/missing-number/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY