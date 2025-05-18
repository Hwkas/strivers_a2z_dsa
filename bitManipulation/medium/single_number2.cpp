#include <iostream>

// Solution 1
// int singleNumber(std::vector<int> &nums)
// {
//     int size = nums.size();
//     int ans = 0;

//     for (int i = 0; i < 32; i++)
//     {
//         int count = 0;
//         for (int j = 0; j < size; j++)
//         {
//             if (nums[j] & (1 << i))
//             {
//                 count++;
//             }
//         }
//         if ((count % 3) == 1)
//         {
//             ans |= (1 << i);
//         }
//     }
//     return ans;
// }

// Solution 2
int singleNumber(std::vector<int> &nums)
{
    int n = nums.size(), ones = 0, twos = 0;
    for (int i = 0; i < n; i++)
    {
        ones = (ones ^ nums[i]) & (~twos);
        twos = (twos ^ nums[i]) & (~ones);
    }
    return ones;
}

int main()
{
    std::vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(3);
    v.push_back(2);

    std::cout << "ans: " << singleNumber(v) << std::endl;
    return 0;
}

// https://leetcode.com/problems/single-number-ii/description/?envType=problem-list-v2&envId=bit-manipulation