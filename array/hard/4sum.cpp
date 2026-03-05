#include <iostream>
#include <set>
#include <map>

// Brute Force Approach
// std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
// {
//     std::vector<std::vector<int>> ans;
//     std::set<std::vector<int>> st;
//     std::vector<int> temp;
//     int size = nums.size();

//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i + 1; j < size; j++)
//         {
//             for (int k = j + 1; k < size; k++)
//             {
//                 for (int l = k + 1; l < size; l++)
//                 {
//                     if (nums[i] + nums[j] + nums[k] + nums[l] == target)
//                     {
//                         temp = {nums[i], nums[j], nums[k], nums[l]};
//                         std::sort(temp.begin(), temp.end());
//                         if (st.find(temp) == st.end())
//                         {
//                             st.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }
//     }
//     ans.assign(st.begin(), st.end());
//     return ans;
// }

// Better Approach
// std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
// {
//     std::vector<std::vector<int>> ans;
//     std::set<std::vector<int>> st;
//     std::set<long long> hash_set;
//     std::vector<int> temp;
//     int size = nums.size();
//     long long sum = 0, element = 0;

//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i + 1; j < size; j++)
//         {
//             hash_set.clear();
//             for (int k = j + 1; k < size; k++)
//             {
//                 sum = nums[i] + nums[j];
//                 sum += nums[k];
//                 element = target - (sum);
//                 if (hash_set.find(element) != hash_set.end())
//                 {
//                     temp = {nums[i], nums[j], nums[k], (int)element};
//                     std::sort(temp.begin(), temp.end());
//                     if (st.find(temp) == st.end())
//                     {
//                         st.insert(temp);
//                     }
//                 }
//                 hash_set.insert(nums[k]);
//             }
//         }
//     }
//     ans.assign(st.begin(), st.end());
//     return ans;
// }

// Optimal Approach
std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
{
    std::vector<std::vector<int>> ans;
    int size = nums.size(), k = 0, l = 0;
    long long sum = 0;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < size; i++)
    {
        if (i > 0 && nums[i - 1] == nums[i])
        {
            continue;
        }
        for (int j = (i + 1); j < size; j++)
        {
            if (j != (i + 1) && nums[j - 1] == nums[j])
            {
                continue;
            }
            k = j + 1, l = size - 1;
            while (k < l)
            {
                sum = (long long)nums[i] + nums[j] + nums[k] + nums[l];
                if (sum > target)
                {
                    l--;
                }
                else if (sum < target)
                {
                    k++;
                }
                else
                {
                    ans.push_back({nums[i], nums[j], nums[k++], nums[l--]});
                    while (k < l && nums[k - 1] == nums[k])
                    {
                        k++;
                    }
                    while (k < l && nums[l + 1] == nums[l])
                    {
                        l--;
                    }
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
    std::vector<int> v = {1, 0, -1, 0, -2, 2};
    std::vector<std::vector<int>> ans = fourSum(v, 0);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/4sum/