#include <iostream>
#include <map>

// Better Solution
// std::vector<int> majorityElement(std::vector<int> &nums)
// {
//     std::vector<int> ans;
//     std::unordered_map<int, int> mpp;
//     int min_count_for_majority = (int)(nums.size() / 3) + 1;

//     for (auto i : nums)
//     {
//         mpp[i]++;

//         if (mpp[i] == min_count_for_majority)
//         {
//             ans.push_back(i);
//         }
//         if ((int)ans.size() == 2)
//         {
//             break;
//         }
//     }
//     return ans;
// }

// Optimal Solution
std::vector<int> majorityElement(std::vector<int> &nums)
{
    std::vector<int> ans;
    int count1 = 0, count2 = 0, element1 = INT_MIN, element2 = INT_MIN;
    int min_count_for_majority = (int)(nums.size() / 3) + 1;

    for (auto i : nums)
    {
        if (count1 == 0 && i != element2)
        {
            count1++;
            element1 = i;
        }
        else if (count2 == 0 && i != element1)
        {
            count2++;
            element2 = i;
        }
        else if (i == element1)
        {
            count1++;
        }
        else if (i == element2)
        {
            count2++;
        }
        else
        {
            count1--;
            count2--;
        }
    }

    count1 = 0, count2 = 0;
    for (auto i : nums)
    {
        if (element1 == i)
        {
            count1++;
        }
        else if (element2 == i)
        {
            count2++;
        }
    }

    if (count1 >= min_count_for_majority)
    {
        ans.push_back(element1);
    }
    if (count2 >= min_count_for_majority)
    {
        ans.push_back(element2);
    }
    return ans;
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
    std::vector<int> v = {3, 2, 3};
    std::vector<int> ans = majorityElement(v);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/majority-element-ii/submissions/1728925633/