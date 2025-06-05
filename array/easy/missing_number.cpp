#include <iostream>

// my approach
// int missingNumber(std::vector<int> &nums)
// {
//     int total = (nums.size() * (nums.size() + 1)) / 2;

//     for (auto i : nums)
//     {
//         total -= i;
//     }
//     return total;
// }

// strivers approach
int missingNumber(std::vector<int> &nums)
{
    int xor1 = 0, xor2 = 0, size = nums.size();

    for (int i = 0; i < size; i++)
    {
        xor2 = xor2 ^ nums[i]; // XOR of array elements
        xor1 = xor1 ^ i;       // XOR up to [1...N-1]
    }
    xor1 = xor1 ^ size; // XOR up to [1...N]

    return (xor1 ^ xor2);
}

int main()
{
    std::vector<int> v;
    v.push_back(3);
    v.push_back(0);
    v.push_back(1);

    std::cout << "ans: " << missingNumber(v) << std::endl;
    return 0;
}

// https://leetcode.com/problems/missing-number/description/