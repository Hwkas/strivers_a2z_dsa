#include <iostream>

// Optimal Solution
int upperBound(std::vector<int> &arr, int x, int n)
{
    int ans = n, low = 0, high = (n - 1);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    std::vector<int> arr = {2, 3, 7, 10, 11, 11, 25};
    std::cout << "Upper Bound is : " << upperBound(arr, 11, arr.size()) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/implement-upper-bound_8165383
