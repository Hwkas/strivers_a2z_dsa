#include <iostream>

// Brute Force Approach
// int count_digits(int n)
// {
//     int count = 0;

//     while (n > 0)
//     {
//         count++;
//         n /= 10;
//     }
//     return count;
// }

// Optimal Approach (only work for the positive value of n)
int count_digits(int n)
{
    return (int)(log10(n) + 1);
}

int main()
{
    std::cout << "ans: " << count_digits(7789) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/count-digits_8416387