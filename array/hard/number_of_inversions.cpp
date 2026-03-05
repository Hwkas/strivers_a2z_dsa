#include <iostream>
#include <map>

// Brute Force
// int numberOfInversions(std::vector<int> &a, int n)
// {
//     int count = 0;
//     for (int i = 0; i < (n - 1); i++)
//     {
//         for (int j = (i + 1); j < n; j++)
//         {
//             if (a[i] > a[j])
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// Optimal Solution
int merge(std::vector<int> &arr, int low, int mid, int high)
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
            count += (mid - left + 1);
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
    count += merge(arr, low, mid, high);
    return count;
}

int numberOfInversions(std::vector<int> &a, int n)
{
    return mergeSort(a, 0, n - 1);
}

int main()
{
    std::vector<int> v = {5, 3, 2, 1, 4};
    int n = 5;
    std::cout << "Number of Inversion: " << numberOfInversions(v, n) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/number-of-inversions_6840276