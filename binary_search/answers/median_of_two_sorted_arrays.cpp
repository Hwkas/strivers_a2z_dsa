#include <iostream>

// Brute Force
// double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
// {
//     std::vector<int> merged_nums;
//     int i = 0, j = 0, n = nums1.size(), m = nums2.size();
//     while ((i < n) && (j < m))
//     {
//         if (nums1[i] < nums2[j])
//         {
//             merged_nums.push_back(nums1[i++]);
//         }
//         else
//         {
//             merged_nums.push_back(nums2[j++]);
//         }
//     }

//     while (i < n)
//     {
//         merged_nums.push_back(nums1[i++]);
//     }

//     while (j < m)
//     {
//         merged_nums.push_back(nums2[j++]);
//     }

//     int mid = (m + n) / 2;

//     if ((m + n) % 2 == 0)
//     {
//         return ((merged_nums[mid - 1] + merged_nums[mid]) / 2.0);
//     }
//     return merged_nums[mid];
// }

// Optimal Approach
double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2)
{
    if (nums2.size() < nums1.size())
    {
        return findMedianSortedArrays(nums2, nums1);
    }

    int n = nums1.size(), m = nums2.size();
    int low = 0, high = n;

    while (low <= high)
    {
        int cut1 = low + (high - low) / 2;
        int cut2 = ((n + m + 1) / 2) - cut1; // ((n + m + 1) / 2) - this means number of elements on left side

        int left1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
        int left2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];

        int right1 = (cut1 == n) ? INT_MAX : nums1[cut1];
        int right2 = (cut2 == m) ? INT_MAX : nums2[cut2];

        if ((left1 <= right2) && (left2 <= right1))
        {
            if ((n + m) % 2 == 0)
            {
                return (std::max(left1, left2) + std::min(right1, right2)) / 2.0;
            }
            return std::max(left1, left2);
        }

        if (left1 > right2)
        {
            high = cut1 - 1;
        }
        else
        {
            low = cut1 + 1;
        }
    }
    return 0;
}

int main()
{
    std::vector<int> nums1 = {1, 2};
    std::vector<int> nums2 = {3, 4};
    std::cout << "The Median is " << findMedianSortedArrays(nums1, nums2) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/median-of-two-sorted-arrays/submissions/1992019424/