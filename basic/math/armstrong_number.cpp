#include <iostream>

bool armstrongNumber(int n)
{
    int x = n, y = 0;

    while (x > 0)
    {
        y += std::pow(x % 10, 3);
        x /= 10;
    }
    return y == n;
}

int main()
{
    std::cout << "ans: " << armstrongNumber(153) << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/armstrong-numbers2727/1