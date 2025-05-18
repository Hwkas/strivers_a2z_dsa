#include <iostream>

int hammingDistance(int x, int y)
{
    int z = x ^ y;
    int set_bits_cout = 0;
    while (z > 0)
    {
        if (z & 1)
        {
            set_bits_cout++;
        }
        z >>= 1;
    }
    return set_bits_cout;
}

int main()
{
    std::cout << "Hamming Distance: " << hammingDistance(93, 73) << std::endl;
    return 0;
}

// https://leetcode.com/problems/hamming-distance/submissions/1480401777/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY