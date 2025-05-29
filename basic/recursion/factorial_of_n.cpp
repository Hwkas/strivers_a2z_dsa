#include <iostream>

int factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return n * factorial(n - 1);
}

int main()
{
    std::cout << "sum: " << factorial(5) << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/factorial5739/1