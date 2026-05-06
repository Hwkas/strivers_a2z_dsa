#include <iostream>

// Brute Force Approach
// int rowWithMax1s(std::vector<std::vector<int>> &matrix, int n, int m)
// {
//     int row_index = -1, max_1_count = 0, temp = 0;

//     for (int i = 0; i < n; i++)
//     {
//         temp = 0;
//         for (int j = 0; j < m; j++)
//         {
//             temp += matrix[i][j];
//         }
//         if (temp > max_1_count)
//         {
//             row_index = i;
//             max_1_count = temp;
//         }
//     }
//     return row_index;
// }

// Binary Search
int lowerBound(std::vector<int> &row, int m, int x)
{
    int low = 0, mid = 0, high = (m - 1);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (row[mid] == x)
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

int rowWithMax1s(std::vector<std::vector<int>> &matrix, int n, int m)
{
    int row_index = -1, max_1_count = 0, temp = 0;

    for (int i = 0; i < n; i++)
    {
        if (matrix[i][m - 1] == 0)
        {
            continue;
        }

        temp = m - lowerBound(matrix[i], m, 1);

        if (temp > max_1_count)
        {
            row_index = i;
            max_1_count = temp;
        }
    }
    return row_index;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    std::cout << "Row with Maximum 1's is " << rowWithMax1s(matrix, 3, 3) << "." << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/row-with-maximum-1-s_1112656?leftPanelTabValue=SUBMISSION