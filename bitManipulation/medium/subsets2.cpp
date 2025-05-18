#include <iostream>
#include <unordered_set>

// Solution extra time
// std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums)
// {
//     std::sort(nums.begin(), nums.end());
//     std::vector<std::vector<int> > ans;
//     int n = (1 << nums.size());

//     for (int i = 0; i < n; i++)
//     {
//         std::vector<int> temp;
//         int j = i, k = 0;

//         while (j > 0)
//         {
//             if (j & 1)
//             {
//                 temp.push_back(nums[k]);
//             }
//             j >>= 1;
//             k++;
//         }

//         int m = ans.size();
//         bool duplicate = false;

//         for (int l = 0; l < m && !duplicate; l++)
//         {
//             if (ans[l] == temp)
//             {
//                 duplicate = true;
//             }
//         }
//         if (!duplicate)
//         {
//             ans.push_back(temp);
//         }
//     }
//     return ans;
// }

// Solution extra memory
std::vector<std::vector<int> > subsetsWithDup(std::vector<int> &nums)
{
    std::sort(nums.begin(), nums.end());
    std::vector<std::vector<int> > ans;
    std::unordered_set<std::string> set;

    int n = (1 << nums.size());

    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp;
        std::string hashcode = "";
        int j = i, k = 0;

        while (j > 0)
        {
            if (j & 1)
            {
                temp.push_back(nums[k]);
                hashcode += std::to_string(nums[k]);
            }
            j >>= 1;
            k++;
        }

        if (set.find(hashcode) == set.end())
        {
            ans.push_back(temp);
            set.insert(hashcode);
        }
    }
    return ans;
}

void print(std::vector<std::vector<int> > v)
{
    std::cout << "[";
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        std::cout << "[";
        int m = v[i].size();
        for (int j = 0; j < m; j++)
        {
            std::cout << v[i][j] << ((j != (m - 1)) ? ", " : "");
        }
        std::cout << "]" << ((i != (n - 1)) ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    std::vector<std::vector<int> > ans = subsetsWithDup(v);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/subsets-ii/description/?envType=problem-list-v2&envId=bit-manipulation