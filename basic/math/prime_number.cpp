#include <iostream>

bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }

    for (int i = sqrt(n); i > 1; i--)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::cout << "ans: " << isPrime(153) << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/prime-number2314/1