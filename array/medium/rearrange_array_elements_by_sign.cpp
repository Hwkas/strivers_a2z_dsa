#include <iostream>

// std::vector<int> rearrangeArray(std::vector<int> &nums)
// {
//     std::vector<int> ans;
//     int i = 0, j = 0, size = nums.size();

//     while (i < size || j < size)
//     {
//         while (i < size && nums[i] < 0)
//         {
//             i++;
//         }
//         while (j < size && nums[j] >= 0)
//         {
//             j++;
//         }

//         if (i < size)
//         {
//             ans.push_back(nums[i++]);
//         }
//         if (j < size)
//         {
//             ans.push_back(nums[j++]);
//         }
//     }
//     return ans;
// }

std::vector<int> rearrangeArray(std::vector<int> &nums)
{
    int j = 0, k = 1, size = nums.size();
    std::vector<int> ans(size);

    for (auto i : nums)
    {
        if (i >= 0)
        {
            ans[j] = i;
            j += 2;
        }
        else
        {
            ans[k] = i;
            k += 2;
        }
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
    std::vector<int> v;
    v.push_back(3);
    v.push_back(1);
    v.push_back(-2);
    v.push_back(-5);
    v.push_back(2);
    v.push_back(-4);

    std::vector<int> ans = rearrangeArray(v);

    std::cout << "ans: ";
    print(ans);
    return 0;
}

// https://leetcode.com/problems/rearrange-array-elements-by-sign/