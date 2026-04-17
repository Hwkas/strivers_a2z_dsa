#include <iostream>
#include <numeric>

bool is_valid_allocation(const std::vector<int> &arr, int n, int m, int pages)
{
    int sum = 0;
    int allocated_student_count = 1;

    for (const auto &i : arr)
    {
        if (i > pages)
        {
            return false;
        }
        if ((sum + i) <= pages)
        {
            sum += i;
        }
        else
        {
            allocated_student_count++;
            sum = i;
        }
    }
    return (allocated_student_count <= m);
}

int findPages(std::vector<int> &arr, int n, int m)
{
    if (m > n)
    {
        return -1;
    }

    if (m == n)
    {
        return *std::max_element(arr.begin(), arr.end());
    }

    if (m == 1)
    {
        return std::accumulate(arr.begin(), arr.end(), 0);
    }

    int low = *std::max_element(arr.begin(), arr.end()), mid = 0, high = std::accumulate(arr.begin(), arr.end(), 0);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (is_valid_allocation(arr, n, m, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    std::vector<int> arr = {25, 46, 28, 49, 24};
    // {12, 34, 67, 90};
    // int n = 4, m = 2;
    int n = 5, m = 4;
    std::cout << "Maximum number of pages assigned to a student is minimum is " << findPages(arr, n, m) << "." << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/allocate-books_1090540