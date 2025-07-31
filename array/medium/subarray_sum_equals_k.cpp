#include <iostream>

// Brute Force
// int subarraySum(std::vector<int> &nums, int k)
// {
//     int size = nums.size(), count = 0, sum = 0;
//     for (int i = 0; i < size; i++)
//     {
//         sum = 0;
//         for (int j = i; j < size; j++)
//         {
//             sum += nums[j];
//             if (sum == k)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// Optimal Approach
int subarraySum(std::vector<int> &nums, int k)
{
    std::unordered_map<long long, int> map;
    map[0] = 1;
    int size = nums.size(), count = 0;
    long long prefix_sum = 0;

    for (int i = 0; i < size; i++)
    {
        prefix_sum += nums[i];
        count += map[prefix_sum - k];
        map[prefix_sum]++;
    }
    return count;
}

int main()
{
    std::vector<int> v = {1, 2, 3};
    std::cout << "ans: " << subarraySum(v, 3) << std::endl;
    return 0;
}

// https://leetcode.com/problems/subarray-sum-equals-k/