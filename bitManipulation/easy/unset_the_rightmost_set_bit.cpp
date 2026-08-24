#include <iostream>

int UnsetRightmostSetBit(int n)
{
    return n & (n - 1);
}

int main()
{
    std::cout << "ans: " << UnsetRightmostSetBit(12) << std::endl;
    return 0;
}