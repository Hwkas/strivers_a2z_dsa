#include <iostream>

// Brute Force Approach
// int reversePairs(std::vector<int> &nums)
// {
//     int n = nums.size();
//     int count = 0;

//     for (int i = 0; i < (n - 1); i++)
//     {
//         for (int j = i + 1; j < n; j++)
//         {
//             if (nums[i] > ((long long)nums[j] * 2))
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// Optimal Solution
void merge(std::vector<int> &arr, int low, int mid, int high)
{
    std::vector<int> temp;
    int left = low, right = mid + 1;
    int count = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left++]);
        }
        else
        {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

/*
    A separate function is needed for counting reverse pairs instead of
    counting within merge(), because merge() advances pointers based on
    element ordering (arr[left] <= arr[right]), which breaks the counting logic.

    Example — Left half: [3, 4, 5] | Right half: [1, 2]
    Reverse pair condition: arr[i] > 2 * arr[j]

    If we tried counting inside merge():
        Iteration 1: arr[left]=3 vs arr[right]=1 → 3 > 2*1 ✓, right++ (right=2)
        Iteration 2: arr[left]=3 vs arr[right]=2 → 3 > 2*2 ✗, so left++ (left=1)
                     ❌ But arr[right]=2 is never compared against arr[left]=4 or 5!
                        Those pairs (4,2) and (5,2) are silently missed.

    This function fixes it by iterating left half independently with a
    persistent `right` pointer — since both halves are already sorted,
    once arr[i] <= 2*arr[right], all subsequent left elements also fail,
    so we accumulate (right - (mid+1)) pairs for each i in O(n) total.
*/
int count_pairs(std::vector<int> &arr, int low, int mid, int high)
{
    int right = mid + 1;
    int count = 0;

    for (int i = low; i <= mid; i++)
    {
        while (right <= high && arr[i] > ((long long)arr[right] * 2))
        {
            right++;
        }
        count += (right - (mid + 1));
    }
    return count;
}

int mergeSort(std::vector<int> &arr, int low, int high)
{
    int count = 0;

    if (low >= high)
    {
        return count;
    }

    int mid = (low + high) / 2;

    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += count_pairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}

int reversePairs(std::vector<int> &nums)
{
    return mergeSort(nums, 0, (nums.size() - 1));
}

int main()
{
    std::vector<int> v = {1, 3, 2, 3, 1};
    std::cout << "Reverse Pairs: " << reversePairs(v) << std::endl;
    return 0;
}

// https://leetcode.com/problems/reverse-pairs/description/