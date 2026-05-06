#include <iostream>

int findMin(std::vector<int> &nums)
{
    int low = 0, mid = 0, high = (nums.size() - 1), ans = INT_MAX;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (nums[low] <= nums[high])
        {
            return std::min(nums[low], ans);
        }

        if (nums[low] <= nums[mid])
        {
            ans = std::min(nums[low], ans);
            low = mid + 1;
        }
        else
        {
            ans = std::min(nums[mid], ans);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << "Minimum in Rotated Sorted Array is " << findMin(nums) << std::endl;
    return 0;
}

// https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/