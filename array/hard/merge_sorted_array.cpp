#include <iostream>

// Brute Force Approach
// void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
// {
//     std::vector<int> ans;

//     int i = 0, j = 0;

//     while (i < m && j < n)
//     {
//         if (nums1[i] <= nums2[j])
//         {
//             ans.push_back(nums1[i++]);
//         }
//         else
//         {
//             ans.push_back(nums2[j++]);
//         }
//     }

//     while (i < m)
//     {
//         ans.push_back(nums1[i++]);
//     }

//     while (j < n)
//     {
//         ans.push_back(nums2[j++]);
//     }
//     nums1 = ans;
// }

// Optimal Approach (Two Pointer)
void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n)
{
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0)
    {
        if (i >= 0 && nums1[i] > nums2[j])
        {
            nums1[k--] = nums1[i--];
        }
        else
        {
            nums1[k--] = nums2[j--];
        }
    }
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
    std::vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    std::vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;
    merge(nums1, m, nums2, n);
    print(nums1);
    return 0;
}

// https://leetcode.com/problems/merge-sorted-array/description/