#include <iostream>

// Iterative Solution
// int binary_search(std::vector<int> &nums, int target)
// {
//     int low = 0, high = (nums.size() - 1);

//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;
//         if (nums[mid] == target)
//         {
//             return mid;
//         }
//         if (nums[mid] > target)
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }

//     return -1;
// }

// Recursive Solution
int search(const std::vector<int> &nums, int target, int low, int high)
{
    if (low > high)
    {
        return -1;
    }

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
    {
        return mid;
    }
    if (nums[mid] > target)
    {
        high = mid - 1;
    }
    else
    {
        low = mid + 1;
    }

    return search(nums, target, low, high);
}

int binary_search(std::vector<int> &nums, int target)
{
    return search(nums, target, 0, (nums.size() - 1));
}

int main()
{
    std::vector<int> nums = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 4;
    int index = binary_search(nums, target);

    if (index == -1)
    {
        std::cout << "The target is not present." << std::endl;
    }
    else
    {
        std::cout << "The target is at index: " << index << std::endl;
    }
    return 0;
}

// https://leetcode.com/problems/binary-search/description/