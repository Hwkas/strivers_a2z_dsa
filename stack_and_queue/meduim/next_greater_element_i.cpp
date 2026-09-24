#include <iostream>

// Brute Force Approach
// std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
// {
//     std::vector<int> result;

//     for (const auto &e : nums1)
//     {
//         int j = 0, next_greater = -1;

//         while ((j < nums2.size()) && (nums2[j] != e))
//         {
//             j++;
//         }

//         while ((j < nums2.size()) && (nums2[j] <= e))
//         {
//             j++;
//         }

//         if (j < nums2.size())
//         {
//             next_greater = nums2[j];
//         }

//         result.push_back(next_greater);
//     }

//     return result;
// }

// Optimal Approach
std::vector<int> nextGreaterElement(std::vector<int> &nums1, std::vector<int> &nums2)
{
    std::vector<int> result(nums1.size());
    std::stack<int> s;

    for (int i = (nums2.size() - 1); i >= 0; i--)
    {
        while ((!s.empty()) && (s.top() < nums2[i]))
        {
            s.pop();
        }

        for (int j = 0; j < nums1.size(); j++)
        {
            if (nums2[i] == nums1[j])
            {
                result[j] = (s.empty() ? -1 : s.top());
            }
        }

        s.push(nums2[i]);
    }

    return result;
}

void print(std::vector<int> &arr)
{
    int size = arr.size();

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] " << std::endl;
}

int main()
{
    std::vector<int> nums1 = {4, 1, 2};
    std::vector<int> nums2 = {1, 3, 4, 2};

    std::vector<int> result = nextGreaterElement(nums1, nums2);

    print(result);

    return 0;
}

// https://leetcode.com/problems/next-greater-element-i/submissions/2130978383/