#include <iostream>

bool isKthBitSet(int n, int k)
{
    return (n & (1 << (k - 1)));
}

int main()
{
    std::cout << (isKthBitSet(3, 1) ? "True" : "False") << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/check-whether-k-th-bit-is-set-or-not_5026446