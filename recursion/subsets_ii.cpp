#include <iostream>

// My Solution
void generatesubsetsWithOutDup(
    std::vector<int> &nums,
    std::vector<std::vector<int>> &result,
    std::vector<int> &subset,
    int start,
    int end)
{
    if (start >= end)
    {
        result.push_back(subset);
        return;
    }

    // Include
    subset.push_back(nums[start]);
    generatesubsetsWithOutDup(nums, result, subset, (start + 1), end);

    // Not Include
    subset.pop_back();
    int i = 1;
    while (((start + i) < end) && (nums[start] == nums[start + i]))
    {
        i++;
    }
    generatesubsetsWithOutDup(nums, result, subset, (start + i), end);
}

std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
{
    std::vector<std::vector<int>> result;
    std::vector<int> subset;
    std::vector<int> nums_copy = nums;

    std::sort(nums_copy.begin(), nums_copy.end());
    generatesubsetsWithOutDup(nums_copy, result, subset, 0, nums_copy.size());

    return result;
}

// Striver's Solution
// void backtrack(
//     int start,
//     std::vector<int> &nums,
//     std::vector<int> &current,
//     std::vector<std::vector<int>> &result)
// {
//     // Add the current subset to result
//     result.push_back(current);

//     // Iterate over the array from 'start' index
//     for (int i = start; i < nums.size(); i++)
//     {
//         // Skip duplicates: if current number is same as previous and not at the start index
//         if (i > start && nums[i] == nums[i - 1])
//             continue;

//         // Include nums[i] in current subset
//         current.push_back(nums[i]);

//         // Recurse for next index
//         backtrack(i + 1, nums, current, result);

//         // Backtrack: remove last added element
//         current.pop_back();
//     }
// }

// // Main function to get unique subsets
// std::vector<std::vector<int>> subsetsWithDup(std::vector<int> &nums)
// {
//     // Sort the array to handle duplicates
//     sort(nums.begin(), nums.end());

//     std::vector<std::vector<int>> result;
//     std::vector<int> current;

//     // Start backtracking from index 0
//     backtrack(0, nums, current, result);

//     return result;
// }

void print(std::vector<std::vector<int>> &arr)
{
    for (auto temp : arr)
    {
        int size = temp.size();
        std::cout << "[";
        for (int i = 0; i < size; i++)
        {
            std::cout << temp[i] << ((i == (size - 1)) ? "" : ", ");
        }
        std::cout << "] " << std::endl;
    }
}

int main()
{
    std::vector<int> nums = {1, 2, 2};
    std::vector<std::vector<int>> result = subsetsWithDup(nums);
    print(result);
    return 0;
}

// https://leetcode.com/problems/subsets-ii/description/