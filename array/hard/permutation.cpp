#include <iostream>
#include <map>

// Approach 1
// void solve(std::vector<int> &nums, std::vector<int> &ds, std::vector<std::vector<int>> &ans, std::unordered_map<int, int> &map)
// {
//     if (ds.size() == nums.size())
//     {
//         ans.push_back(ds);
//         return;
//     }

//     for (auto i : nums)
//     {
//         if (!map[i])
//         {
//             ds.push_back(i);
//             map[i] = 1;
//             solve(nums, ds, ans, map);
//             map[i] = 0;
//             ds.pop_back();
//         }
//     }
// }

// std::vector<std::vector<int>> generate_permutations(std::vector<int> &nums)
// {
//     std::vector<std::vector<int>> ans;
//     std::vector<int> ds;
//     std::unordered_map<int, int> map;

//     int size = nums.size();

//     for (int i = 0; i < size; i++)
//     {
//         map[i] = 0;
//     }

//     solve(nums, ds, ans, map);
//     return ans;
// }

// Approach 2
void solve(std::vector<int> &nums, std::vector<std::vector<int>> &ans, int index)
{
    int size = nums.size();

    if (index == size)
    {
        ans.push_back(nums);
        return;
    }

    for (int i = index; i < size; i++)
    {
        std::swap(nums[i], nums[index]);
        solve(nums, ans, index + 1);
        std::swap(nums[i], nums[index]);
    }
}

std::vector<std::vector<int>> generate_permutations(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;
    solve(nums, ans, 0);
    return ans;
}

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
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(4);

    std::vector<std::vector<int>> ans = generate_permutations(nums);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/permutations/submissions/1671833736/