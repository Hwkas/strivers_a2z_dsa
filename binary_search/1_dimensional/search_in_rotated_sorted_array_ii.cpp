#include <iostream>

// Optimal Approach
bool search(std::vector<int> &nums, int target)
{
    int low = 0, mid = 0, high = (nums.size() - 1);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (nums[mid] == target)
        {
            return true;
        }
        if (nums[low] == nums[mid] && nums[mid] == nums[high])
        {
            low++;
            high--;
            continue;
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
    return false;
}

int main()
{
    std::vector<int> nums = {1, 0, 1, 1, 1};
    int target = 0;
    std::cout << target << (search(nums, target) ? " exists in the array." : " does not exists in the array.") << std::endl;
    return 0;
}

// https://leetcode.com/problems/search-in-rotated-sorted-array-ii/description/