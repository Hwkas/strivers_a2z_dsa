#include <iostream>

// Better Approach(My Approch)
// void setZeroes(std::vector<std::vector<int>> &matrix)
// {
//     std::vector<std::pair<int, int>> zero_indexes;
//     int m = matrix.size(), n = matrix[0].size();
//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 zero_indexes.push_back({i, j});
//             }
//         }
//     }

//     for (auto i : zero_indexes)
//     {
//         int x = 0;
//         while (x < m || x < n)
//         {
//             if (x < n)
//             {
//                 matrix[i.first][x] = 0;
//             }
//             if (x < m)
//             {
//                 matrix[x][i.second] = 0;
//             }
//             x++;
//         }
//     }
// }

// Better Approach(Striver's Approch)
// void setZeroes(std::vector<std::vector<int>> &matrix)
// {
//     int m = matrix.size(), n = matrix[0].size();
//     std::vector<bool> row(m), col(n);

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (matrix[i][j] == 0)
//             {
//                 row[i] = true;
//                 col[j] = true;
//             }
//         }
//     }

//     for (int i = 0; i < m; i++)
//     {
//         for (int j = 0; j < n; j++)
//         {
//             if (row[i] == true || col[j] == true)
//             {
//                 matrix[i][j] = 0;
//             }
//         }
//     }
// }

// Optimal Approach
void setZeroes(std::vector<std::vector<int>> &matrix)
{
    int m = matrix.size(), n = matrix[0].size(), col0 = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if (j == 0)
                {
                    col0 = 0;
                }
                else
                {
                    matrix[0][j] = 0;
                }
            }
        }
    }

    for (int i = (m - 1); i >= 0; i--)
    {
        for (int j = (n - 1); j >= 0; j--)
        {
            if (matrix[i][0] == 0 || ((j == 0) ? col0 == 0 : matrix[0][j] == 0))
            {
                matrix[i][j] = 0;
            }
        }
    }
}

void print(std::vector<std::vector<int>> &arr)
{
    for (auto temp : arr)
    {
        int size = temp.size();
        std::cout << "[";
        for (int i = 0; i < size; i++)
        {
            std::cout << temp[i] << ((i == (size - 1)) ? "" : ", ");
        }
        std::cout << "] " << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> v;
    // v.push_back({1, 1, 1});
    // v.push_back({1, 0, 1});
    // v.push_back({1, 1, 1});

    // v.push_back({0, 1});

    v.push_back({0, 1, 2, 0});
    v.push_back({3, 4, 5, 2});
    v.push_back({1, 3, 1, 5});

    setZeroes(v);
    print(v);
    return 0;
}

// https://leetcode.com/problems/set-matrix-zeroes/submissions/1682934803/