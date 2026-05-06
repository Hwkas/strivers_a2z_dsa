#include <iostream>

bool searchMatrix(std::vector<std::vector<int>> &matrix, int target)
{
    int n = matrix.size(), row = 0, col = (matrix[0].size() - 1);

    while ((row < n) && (col >= 0))
    {
        if (matrix[row][col] == target)
        {
            return true;
        }

        if (matrix[row][col] > target)
        {
            col--;
        }
        else
        {
            row++;
        }
    }
    return false;
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    int target = 5;
    std::cout << "Target " << target << (searchMatrix(matrix, target) ? " " : " does not ") << "exists in this matrix." << std::endl;
    return 0;
}

// https://leetcode.com/problems/search-a-2d-matrix-ii/description/