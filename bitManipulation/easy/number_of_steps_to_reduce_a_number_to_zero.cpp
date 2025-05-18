#include <iostream>

int numberOfSteps(int num)
{
    int count = 0;
    while (num > 0)
    {
        num = (num & 1) ? (num - 1) : (num >> 1);
        count++;
    }
    return count;
}

int main()
{
    std::cout << "ans: " << numberOfSteps(123) << std::endl;
    return 0;
}

// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/?envType=problem-list-v2&envId=bit-manipulation