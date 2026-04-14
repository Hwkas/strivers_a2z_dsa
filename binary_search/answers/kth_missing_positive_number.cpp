#include <iostream>

int findKthPositive(std::vector<int> &arr, int k)
{
    int low = 0, mid = 0, high = (arr.size() - 1);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (arr[mid] - (mid + 1) >= k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return (k + high + 1);
}

int main()
{
    std::vector<int> arr = {2, 3, 4, 7, 11};
    int k = 5;
    std::cout << k << "th Missing Positive Number is " << findKthPositive(arr, k) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/kth-missing-positive-number/description/