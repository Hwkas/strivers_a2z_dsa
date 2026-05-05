#include <iostream>

// My Solution
// int findRow(const std::vector<std::vector<int>> &matrix, int target)
// {
//     int low = 0, mid = 0, high = (matrix.size() - 1);

//     while (low <= high)
//     {
//         mid = low + (high - low) / 2;

//         int first_element = matrix[mid][0];
//         int last_element = matrix[mid][matrix[mid].size() - 1];

//         if ((target >= first_element) && (target <= last_element))
//         {
//             return mid;
//         }

//         if (target < first_element)
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return -1;
// }

// bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
// {
//     int row = findRow(matrix, target);

//     if (row == -1)
//     {
//         return false;
//     }

//     int low = 0, mid = 0, high = (matrix[row].size() - 1);

//     while (low <= high)
//     {
//         mid = low + (high - low) / 2;

//         if (matrix[row][mid] == target)
//         {
//             return true;
//         }

//         if (target < matrix[row][mid])
//         {
//             high = mid - 1;
//         }
//         else
//         {
//             low = mid + 1;
//         }
//     }
//     return false;
// }

// Striver's Solution
bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
{
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, mid = 0, high = ((n * m) - 1);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
        {
            return true;
        }

        if (target < matrix[row][col])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 1}};
    // {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 2;
    // 3;
    std::cout << "Target " << target << (searchMatrix(matrix, target) ? " " : " does not ") << "exists in this matrix." << std::endl;
    return 0;
}

// https://leetcode.com/problems/search-a-2d-matrix/