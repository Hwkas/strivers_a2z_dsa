#include <iostream>

// Better Approach
// int gcd(int a, int b)
// {
//     if (a > b)
//     {
//         std::swap(a, b);
//     }

//     if (b % a == 0)
//     {
//         return a;
//     }

//     for (int i = a / 2; i > 0; i--)
//     {
//         if (a % i == 0 && b % i == 0)
//         {
//             return i;
//         }
//     }
//     return 1;
// }

// Optimal Approach (recursive)
// int gcd(int a, int b)
// {
//     if (a == 0 || b == 0)
//     {
//         return std::max(a, b);
//     }

//     if (a > b)
//     {
//         std::swap(a, b);
//     }

//     return gcd(b - a, a);
// }

// Optimal Approach (non - recursive)
int gcd(int a, int b)
{
    while (a > 0 && b > 0)
    {
        if (a > b)
        {
            std::swap(a, b);
        }
        b %= a;
    }
    return std::max(a, b);
}

int main()
{
    std::cout << "ans: " << gcd(3, 6) << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/gcd-of-two-numbers3459/1