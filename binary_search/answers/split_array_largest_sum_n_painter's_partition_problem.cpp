#include <iostream>
#include <numeric>

bool is_valid_sum(const std::vector<int> &nums, int k, int threshold)
{
    int sum = 0;
    int sub_array_count = 1;

    for (const auto &i : nums)
    {
        if ((sum + i) <= threshold)
        {
            sum += i;
        }
        else
        {
            sum = i;
            sub_array_count++;
        }
    }
    return (sub_array_count <= k);
}

int splitArray(std::vector<int> &nums, int k)
{
    int low = *std::max_element(nums.begin(), nums.end()), mid = 0, high = std::accumulate(nums.begin(), nums.end(), 0);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (is_valid_sum(nums, k, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    std::vector<int> nums = {7, 2, 5, 10, 8};
    int k = 2;
    std::cout << "Minimized largest sum of the split is " << splitArray(nums, k) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/split-array-largest-sum/description/
// https://www.naukri.com/code360/problems/painter's-partition-problem_1089557