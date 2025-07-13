#include <iostream>

// Optimal Approach (My Solution)
std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
{
    int row_start = 0, col_start = 0, row_end = matrix.size() - 1, col_end = matrix[0].size() - 1;
    size_t max_size = max_size = matrix.size() * matrix[0].size();
    std::vector<int> ans;

    while (row_start <= row_end)
    {
        for (int i = col_start; i <= col_end && ans.size() < max_size; i++)
        {
            ans.push_back(matrix[row_start][i]);
        }
        row_start++;

        for (int i = row_start; i <= row_end && ans.size() < max_size; i++)
        {
            ans.push_back(matrix[i][col_end]);
        }
        col_end--;

        for (int i = col_end; i >= col_start && ans.size() < max_size; i--)
        {
            ans.push_back(matrix[row_end][i]);
        }
        row_end--;

        for (int i = row_end; i >= row_start && ans.size() < max_size; i--)
        {
            ans.push_back(matrix[i][col_start]);
        }
        col_start++;
    }
    return ans;
}

// Optimal Approach (Striver's Solution)
// std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix)
// {
//     int row_start = 0, col_start = 0, row_end = matrix.size() - 1, col_end = matrix[0].size() - 1;
//     std::vector<int> ans;

//     while (row_start <= row_end && col_start <= col_end)
//     {
//         for (int i = col_start; i <= col_end; i++)
//         {
//             ans.push_back(matrix[row_start][i]);
//         }
//         row_start++;

//         for (int i = row_start; i <= row_end; i++)
//         {
//             ans.push_back(matrix[i][col_end]);
//         }
//         col_end--;

//         if (row_start <= row_end)
//         {
//             for (int i = col_end; i >= col_start; i--)
//             {
//                 ans.push_back(matrix[row_end][i]);
//             }
//             row_end--;
//         }

//         if (col_start <= col_end)
//         {
//             for (int i = row_end; i >= row_start; i--)
//             {
//                 ans.push_back(matrix[i][col_start]);
//             }
//             col_start++;
//         }
//     }
//     return ans;
// }

void print(std::vector<int> &arr)
{
    int size = arr.size();

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] " << std::endl;
}

int main()
{
    std::vector<std::vector<int>> v;
    // v.push_back({1, 2, 3});
    // v.push_back({4, 5, 6});
    // v.push_back({7, 8, 9});

    // v.push_back({1, 2, 3, 4});
    // v.push_back({5, 6, 7, 8});
    // v.push_back({9, 10, 11, 12});

    v.push_back({6, 9, 7});

    std::vector<int> ans = spiralOrder(v);
    print(ans);

    return 0;
}

// https://leetcode.com/problems/spiral-matrix/submissions/1696571393/