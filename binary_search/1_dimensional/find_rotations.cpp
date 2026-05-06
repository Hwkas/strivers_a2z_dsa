#include <iostream>

// Optimal Solution
int findKRotation(std::vector<int> &arr)
{
    // My Solution
    //     // int low = 0, mid = 0, high = (arr.size() - 1);

    //     // if (arr[low] < arr[high])
    //     // {
    //     //     return low;
    //     // }

    //     // while (low < high)
    //     // {
    //     //     mid = low + (high - low) / 2;

    //     //     if (arr[mid] >= arr[0])
    //     //     {
    //     //         low = mid + 1;
    //     //     }
    //     //     else
    //     //     {
    //     //         high = mid;
    //     //     }
    //     // }
    //     // return low;

    // Better version
    int low = 0,
        high = arr.size() - 1;

    while (low < high)
    {
        int mid = low + (high - low) / 2;

        if (arr[mid] > arr[high])
        {
            low = mid + 1;
        }
        else
        {
            high = mid;
        }
    }
}

int main()
{
    std::vector<int> arr = {3, 4, 5, 1, 2};
    std::cout << "Array is rotated " << findKRotation(arr) << " times." << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/rotation_7449070?leftPanelTabValue=SUBMISSION