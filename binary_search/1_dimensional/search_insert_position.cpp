#include <iostream>

int lowerBound(std::vector<int> arr, int n, int x)
{
    int ans = n, low = 0, high = (n - 1);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

// Optimal Solution
int searchInsert(std::vector<int> &nums, int target)
{
    return lowerBound(nums, nums.size(), target);
}

int main()
{
    std::vector<int> nums = {1, 3, 5, 6};
    std::cout << "Search Insert Position: " << searchInsert(nums, 0) << std::endl;
    return 0;
}

// https://leetcode.com/problems/search-insert-position/description/