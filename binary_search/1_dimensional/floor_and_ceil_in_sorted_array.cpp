#include <iostream>

// My Optimal Solution
// int lowerBound(std::vector<int> arr, int n, int x)
// {
//     int ans = n, low = 0, high = (n - 1);

//     while (low <= high)
//     {
//         int mid = low + (high - low) / 2;

//         if (arr[mid] >= x)
//         {
//             ans = mid;
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

// std::pair<int, int> findFloorCeil(const std::vector<int> &arr, int k)
// {
//     int n = arr.size();
//     int lower_bound_index = lowerBound(arr, n, k);

//     int floor = -1, ceil = -1;

//     if (lower_bound_index == n)
//     {
//         floor = arr[lower_bound_index - 1];
//     }
//     else if (arr[lower_bound_index] == k)
//     {
//         floor = k;
//         ceil = k;
//     }
//     else if (lower_bound_index == 0)
//     {
//         ceil = arr[lower_bound_index];
//     }
//     else
//     {
//         floor = arr[lower_bound_index - 1];
//         ceil = arr[lower_bound_index];
//     }

//     return {floor, ceil};
// }

// Striver's Solution
// Modified lower bound
int findFloor(std::vector<int> arr, int n, int x)
{
    int ans = -1, low = 0, high = (n - 1);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] <= x)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

// Modified lower bound
int findCeil(std::vector<int> arr, int n, int x)
{
    int ans = -1, low = 0, high = (n - 1);

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] >= x)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

std::pair<int, int> findFloorCeil(const std::vector<int> &arr, int k)
{
    int n = arr.size();
    int floor = findFloor(arr, n, k);
    int ceil = findCeil(arr, n, k);
    return {floor, ceil};
}

int main()
{
    std::vector<int> arr = {1, 3, 5, 7, 9, 11};
    std::pair<int, int> ans = findFloorCeil(arr, 12);
    std::cout << "Floor: " << ans.first << ", Ceil: " << ans.second << std::endl;
    return 0;
}

// https://www.codechef.com/practice/course/binary-search/INTBINS01/problems/FLOORCEIL