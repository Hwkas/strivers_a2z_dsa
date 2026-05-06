#include <iostream>

std::pair<int, int> findLowHigh(const std::vector<std::vector<int>> &matrix, int m, int n)
{
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        low = std::min(matrix[i][0], low);
        high = std::max(matrix[i][n - 1], high);
    }
    return {low, high};
}

int findSmallerEqualElementsCount(const std::vector<std::vector<int>> &matrix, int m, int element)
{
    int count = 0;
    for (const auto &arr : matrix)
    {
        count += std::upper_bound(arr.begin(), arr.end(), element) - arr.begin();
    }
    return count;
}

int median(std::vector<std::vector<int>> &matrix, int m, int n)
{
    auto [low, high] = findLowHigh(matrix, m, n);
    int mid = 0, median_index = ((m * n) / 2), count = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        count = findSmallerEqualElementsCount(matrix, m, mid);

        if (count <= median_index)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 5, 7, 9, 11},
                                            {2, 3, 4, 8, 9},
                                            {4, 11, 14, 19, 20},
                                            {6, 10, 22, 99, 100},
                                            {7, 15, 17, 24, 28}};
    std::cout << "Median is " << median(matrix, 5, 5) << "." << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/median-of-a-row-wise-sorted-matrix_1115473