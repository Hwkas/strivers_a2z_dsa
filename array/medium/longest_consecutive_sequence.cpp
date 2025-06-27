#include <iostream>
#include <unordered_set>

// Brute Force Approach
// int longestConsecutive(std::vector<int> &nums)
// {
//     int max_length = 1, current_length = 1, element = 0, size = nums.size();

//     for (int i = 0; i < size; i++)
//     {
//         element = nums[i];
//         current_length = 1;
//         for (int j = 0; j < size; j++)
//         {
//             if ((element + 1) == nums[j])
//             {
//                 current_length++;
//                 element++;
//                 j = -1;
//             }
//             max_length = std::max(max_length, current_length);
//         }
//     }
//     return max_length;
// }

// Optimal Approach
int longestConsecutive(std::vector<int> &nums)
{
    if (nums.size() == 0)
    {
        return 0;
    }

    std::unordered_set<int> numSet;
    int max_length = 1, current_length = 1, element = 0;

    for (auto i : nums)
    {
        numSet.insert(i);
    }

    for (auto i : numSet)
    {
        current_length = 1;
        if (numSet.find(i - 1) == numSet.end())
        {
            element = i;
            while (numSet.find(element + 1) != numSet.end())
            {
                element++;
                current_length++;
            }
            max_length = std::max(max_length, current_length);
        }
    }
    return max_length;
}

int main()
{
    std::vector<int> v;
    v.push_back(100);
    v.push_back(4);
    v.push_back(200);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);

    std::cout << "ans: " << longestConsecutive(v) << std::endl;
    return 0;
}

// https://leetcode.com/problems/longest-consecutive-sequence/submissions/1678616206/