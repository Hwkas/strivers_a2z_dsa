#include <iostream>

int maxElementIndex(std::vector<std::vector<int>> &mat, int col)
{
    int max_element = INT_MIN, row_index = 0;

    for (int i = 0; i < mat.size(); i++)
    {
        if (mat[i][col] > max_element)
        {
            max_element = mat[i][col];
            row_index = i;
        }
    }
    return row_index;
}

std::vector<int> findPeakGrid(std::vector<std::vector<int>> &mat)
{
    int rows = mat.size(), cols = mat[0].size();
    int low = 0, mid = 0, high = (cols - 1);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        int row_index = maxElementIndex(mat, mid);

        int left = ((mid - 1) < 0) ? -1 : mat[row_index][mid - 1];
        int right = ((mid + 1) >= cols) ? -1 : mat[row_index][mid + 1];

        if ((mat[row_index][mid] > left) && (mat[row_index][mid] > right))
        {
            return {row_index, mid};
        }

        if (mat[row_index][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}

int main()
{
    std::vector<std::vector<int>> matrix = {{1, 4}, {3, 2}};
    std::vector<int> ans = findPeakGrid(matrix);
    std::cout << "Coordinates of Peak Element in Grid is " << ans[0] << ", " << ans[1] << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/find-a-peak-element-ii/submissions/1996522781/