#include <iostream>

int search(std::vector<int> &nums, int target)
{
    int low = 0, mid = 0, high = (nums.size() - 1);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return mid;
        }
        if (nums[low] <= nums[mid])
        {
            if (nums[low] <= target && nums[mid] >= target)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (nums[mid] <= target && nums[high] >= target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    std::vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    std::cout << "Index: " << search(nums, 10) << std::endl;
    return 0;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array/description/