#include <iostream>

int countWays(
    std::vector<int> &arr,
    int k,
    int sum,
    int start,
    int end)
{
    if ((start >= end) || (sum > k))
    {
        return (sum == k) ? 1 : 0;
    }

    // Not Include
    int left = countWays(arr, k, sum, start + 1, end);

    sum += arr[start];

    // Include
    int right = countWays(arr, k, sum, start + 1, end);
    // sum -= arr[start]; // This line has no effect on the function.

    return left + right;
}

int findWays(std::vector<int> &arr, int k)
{
    return countWays(arr, k, 0, 0, arr.size());
}

int main()
{
    std::vector<int> arr = {1, 2, 1};
    std::cout << "The possible number of ways are " << findWays(arr, 2) << "." << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/count-subsets-with-sum-k_3952532?leftPanelTabValue=SUBMISSION