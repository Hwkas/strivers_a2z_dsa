#include <iostream>

// Optimal Approach
int first_occurrence(const std::vector<int> &arr, int k)
{
    int low = 0, high = (arr.size() - 1), ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int last_occurrence(const std::vector<int> &arr, int k)
{
    int low = 0, high = (arr.size() - 1), ans = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] == k)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

std::vector<int> searchRange(std::vector<int> &nums, int target)
{
    return {first_occurrence(nums, target), last_occurrence(nums, target)};
}

void print(const std::vector<int> &arr)
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
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};
    std::vector<int> range = searchRange(nums, 8);
    print(range);
    return 0;
}

// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/