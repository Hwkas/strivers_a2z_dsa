#include <iostream>
#include <map>

// Brute Force Solution
// int maxSubArray(std::vector<int> &nums)
// {
//     int size = nums.size();
//     int max_sum = INT_MIN, temp_sum = 0;

//     for (int i = 0; i < size; i++)
//     {
//         temp_sum = 0;
//         for (int j = i; j < size; j++)
//         {
//             temp_sum += nums[j];
//             max_sum = std::max(temp_sum, max_sum);
//         }
//     }
//     return max_sum;
// }

// Optimal Approach
int maxSubArray(std::vector<int> &nums)
{
    int max_sum = INT_MIN, sum = 0;

    for (auto i : nums)
    {
        sum = std::max(sum, 0);
        sum += i;
        max_sum = std::max(max_sum, sum);
    }
    return max_sum;
}

// Print the SubArray with largest Sum
// int maxSubArray(std::vector<int> &nums)
// {
//     int max_sum = INT_MIN, size = nums.size(), sum = 0, start = 0, end = 0, temp = 0;

//     for (int i = 0; i < size; i++)
//     {
//         if (sum < 0)
//         {
//             sum = 0;
//             temp = i;
//         }

//         sum += nums[i];

//         if (max_sum < sum)
//         {
//             start = temp;
//             end = i;
//             max_sum = sum;
//         }
//     }

//     for (; start <= end; start++)
//     {
//         std::cout << nums[start] << ", ";
//     }
//     std::cout << std::endl;

//     return max_sum;
// }

int main()
{
    std::vector<int> v;
    v.push_back(-1);
    v.push_back(-2);
    // v.push_back(-2);
    // v.push_back(1);
    // v.push_back(-3);
    // v.push_back(4);
    // v.push_back(-1);
    // v.push_back(2);
    // v.push_back(1);
    // v.push_back(-5);
    // v.push_back(4);

    std::cout << "ans: " << maxSubArray(v) << std::endl;
    return 0;
}

// https://leetcode.com/problems/maximum-subarray/