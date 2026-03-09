#include <iostream>

// My Solution
// int binary_search(const std::vector<int> &arr, int target, int low, int high)
// {
//     if (low > high)
//     {
//         if (arr[low] > target)
//         {
//             return low;
//         }
//         return -1;
//     }

//     int mid = low + (high - low) / 2;

//     if (arr[mid] == target)
//     {
//         int temp = mid;
//         while (arr[temp] == target)
//         {
//             temp--;
//         }
//         return (mid == temp) ? mid : temp + 1;
//     }
//     if (arr[mid] > target)
//     {
//         high = mid - 1;
//     }
//     else
//     {
//         low = mid + 1;
//     }
//     return binary_search(arr, target, low, high);
// }

// int lowerBound(std::vector<int> arr, int n, int x)
// {
//     int index = binary_search(arr, x, 0, (n - 1));
//     return (index == -1) ? n : index;
// }

// Optimal Solution
int lowerBound(std::vector<int> arr, int n, int x)
{
    int ans = n, low = 0, high = (n - 1);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
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
    std::cout << "Lower Bound is : " << lowerBound(arr, arr.size(), 11) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/lower-bound_8165382