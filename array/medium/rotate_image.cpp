#include <iostream>

// Optimal Approach
void rotate(std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();

    // Transpose Matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse Rows
    for (int i = 0; i < n; i++)
    {
        // int j = 0, k = n - 1;
        // while (j < k)
        // {
        //     std::swap(matrix[i][j++], matrix[i][k--]);
        // }
        std::reverse(matrix[i].begin(), matrix[i].end());
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
    v.push_back({1, 2, 3});
    v.push_back({4, 5, 6});
    v.push_back({7, 8, 9});

    rotate(v);
    print(v);
    return 0;
}

// https://leetcode.com/problems/rotate-image/submissions/1692262182/