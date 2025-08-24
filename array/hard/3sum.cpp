#include <iostream>
#include <set>
#include <map>

// Brute Force Approach
// std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
// {
//     std::vector<std::vector<int>> ans;
//     std::vector<int> temp;
//     std::set<std::vector<int>> st;
//     int size = nums.size();

//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i + 1; j < size; j++)
//         {
//             for (int k = j + 1; k < size; k++)
//             {
//                 if (nums[i] + nums[j] + nums[k] == 0)
//                 {
//                     temp = {nums[i], nums[j], nums[k]};
//                     std::sort(temp.begin(), temp.end());
//                     if (st.find({temp}) == st.end())
//                     {
//                         st.insert(temp);
//                     }
//                     temp.clear();
//                 }
//             }
//         }
//     }

//     ans.assign(st.begin(), st.end());
//     return ans;
// }

// Better Approach
// std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
// {
//     std::vector<std::vector<int>> ans;
//     std::vector<int> temp;
//     std::set<std::vector<int>> st;
//     std::set<int> hash_set;
//     int element = 0;
//     int size = nums.size();

//     for (int i = 0; i < size; i++)
//     {
//         hash_set.clear();
//         for (int j = i + 1; j < size; j++)
//         {
//             element = -(nums[i] + nums[j]);
//             if (hash_set.find(element) != hash_set.end())
//             {
//                 temp = {nums[i], nums[j], element};
//                 std::sort(temp.begin(), temp.end());
//                 if (st.find({temp}) == st.end())
//                 {
//                     st.insert(temp);
//                 }
//             }
//             hash_set.insert(nums[j]);
//         }
//     }

//     ans.assign(st.begin(), st.end());
//     return ans;
// }

// Optimal Approach
std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
{
    std::vector<std::vector<int>> ans;
    int size = nums.size(), j = 0, k = 0, sum = 0;

    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < size; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
        {
            continue;
        }
        j = i + 1;
        k = size - 1;
        while (j < k)
        {
            sum = nums[i] + nums[j] + nums[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                ans.push_back({nums[i], nums[j++], nums[k--]});
                while (j < k && nums[j - 1] == nums[j])
                {
                    j++;
                }
                while (j < k && nums[k] == nums[k + 1])
                {
                    k--;
                }
            }
        }
    }

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
    std::vector<int> v = {-1, 0, 1, 2, -1, -4};
    std::vector<std::vector<int>> ans = threeSum(v);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/3sum/