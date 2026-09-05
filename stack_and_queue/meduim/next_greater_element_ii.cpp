#include <iostream>

// Brute Force Approach
// std::vector<int> nextGreaterElements(std::vector<int> &nums)
// {
//     std::vector<int> result(nums.size(), -1);

//     for (int i = 0; i < nums.size(); i++)
//     {
//         for (int j = 1; j < nums.size(); j++)
//         {
//             int index = (j + i) % nums.size();

//             if (nums[i] < nums[index])
//             {
//                 result[i] = nums[index];
//                 break;
//             }
//         }
//     }

//     return result;
// }

// Optimal Approach
std::vector<int> nextGreaterElements(std::vector<int> &nums)
{
    std::vector<int> result(nums.size());
    std::stack<int> s;

    for (int i = (nums.size() - 1); i >= 0; i--)
    {
        while (!s.empty() && nums[i] >= s.top())
        {
            s.pop();
        }
        s.push(nums[i]);
    }

    for (int i = (nums.size() - 1); i >= 0; i--)
    {
        while (!s.empty() && nums[i] >= s.top())
        {
            s.pop();
        }

        result[i] = (s.empty() ? -1 : s.top());
        s.push(nums[i]);
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
    std::vector<int> nums = {1, 2, 3, 4, 3};

    std::vector<int> result = nextGreaterElements(nums);

    print(result);

    return 0;
}

// https://leetcode.com/problems/next-greater-element-ii/description/