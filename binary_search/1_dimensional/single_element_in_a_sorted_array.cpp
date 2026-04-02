#include <iostream>

int singleNonDuplicate(std::vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }

    if (nums[0] != nums[1])
    {
        return nums[0];
    }

    if (nums[n - 1] != nums[n - 2])
    {
        return nums[n - 1];
    }

    int low = 1, mid = 0, high = (n - 2);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (nums[mid] != nums[mid + 1] && nums[mid] != nums[mid - 1])
        {
            return nums[mid];
        }

        if (
            ((mid % 2 == 0) && (nums[mid] == nums[mid + 1])) || ((mid % 2 == 1) && (nums[mid] == nums[mid - 1])))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    std::vector<int> nums = {1, 2, 2, 3, 3};
    // {1, 1, 2, 3, 3, 4, 4, 8, 8};
    std::cout << "Single Element in a Sorted Array is: " << singleNonDuplicate(nums) << std::endl;
    return 0;
}

// https://leetcode.com/problems/single-element-in-a-sorted-array/description/