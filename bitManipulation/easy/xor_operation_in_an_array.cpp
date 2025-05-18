#include <iostream>

int xorOperation(int n, int start)
{
    int temp = 0;
    for (int i = 0; i < n; i++)
    {
        temp ^= start + (2 * i);
    }
    return temp;
}

int main()
{
    std::cout << "ans: " << xorOperation(4, 3) << std::endl;
    return 0;
}

// https://leetcode.com/problems/xor-operation-in-an-array/submissions/1484412428/?envType=problem-list-v2&envId=bit-manipulation