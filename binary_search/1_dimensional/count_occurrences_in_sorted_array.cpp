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

int count_occurrence(const std::vector<int> &arr, int k)
{
    int first_occurrence_index = first_occurrence(arr, k);
    int last_occurrence_index = last_occurrence(arr, k);
    return (last_occurrence_index - first_occurrence_index + 1);
}

int main()
{
    std::vector<int> arr = {2, 2, 3, 3, 3, 3, 4};
    std::cout << "Occurrence Count: " << count_occurrence(arr, 3) << std::endl;
    return 0;
}

// https://takeuforward.org/data-structure/count-occurrences-in-sorted-array