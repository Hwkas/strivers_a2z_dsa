#include <iostream>

void swapNumber(int &a, int &b)
{
    a = a ^ b; // Step 1: 'a' now holds the XOR of both numbers
    b = a ^ b; // Step 2: 'b' becomes the original value of 'a' b = (a ^ b) ^ b = a ^ 0 = a
    a = a ^ b; // Step 3: 'a' becomes the original value of 'b' a = (a ^ b) ^ a = b ^ 0 = b
}

int main()
{
    int a = 2, b = 3;

    swapNumber(a, b);

    std::cout << "a: " << a << ", b: " << b << std::endl;

    return 0;
}

// https://www.naukri.com/code360/problems/swap-two-numbers_1112577