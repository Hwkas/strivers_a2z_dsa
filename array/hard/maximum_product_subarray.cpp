#include <iostream>

// Brute Force Approach
// int maxProduct(std::vector<int> &nums)
// {
//     int n = nums.size(), max = INT_MIN;

//     for (int i = 0; i < n; i++)
//     {
//         int temp = 1;
//         for (int j = i; j < n; j++)
//         {
//             temp *= nums[j];
//             max = std::max(temp, max);
//         }
//     }
//     return max;
// }

int maxProduct(std::vector<int> &nums)
{
    int n = nums.size(), max = INT_MIN, prefix = 1, suffix = 1;

    for (int i = 0; i < n; i++)
    {
        if (prefix == 0)
        {
            prefix = 1;
        }
        if (suffix == 0)
        {
            suffix = 1;
        }

        prefix *= nums[i];
        suffix *= nums[n - i - 1];

        max = std::max({prefix, suffix, max});
    }
    return max;
}

int main()
{
    std::vector<int> nums = {2, 3, -2, 4};
    // {2, 3, -2, 4};
    std::cout << "Max Product: " << maxProduct(nums) << std::endl;
    return 0;
}

// https://leetcode.com/problems/maximum-product-subarray/description/xxw