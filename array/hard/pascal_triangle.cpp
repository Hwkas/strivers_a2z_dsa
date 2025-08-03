#include <iostream>

std::vector<std::vector<int>> generate(int numRows)
{
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < numRows; i++)
    {
        std::vector<int> row(i + 1);
        row[0] = row[i] = 1;
        for (int j = 1; j < i; j++)
        {
            row[j] = ans[i - 1][j - 1] + ans[i - 1][j];
        }
        ans.push_back(row);
    }
    return ans;
}

long long find_element(int row, int col)
{
    long long numerator = 1, denominator = 1;
    for (int i = 0; i < col; i++)
    {
        numerator *= row - i;
        denominator *= col - i;
    }
    return numerator / denominator;
}

std::vector<int> generate_row(int row)
{
    std::vector<int> ans(row);
    ans[0] = ans[row - 1] = 1;
    long long numerator = 1, denominator = 1;
    for (int i = 1; i < row - 1; i++)
    {
        numerator *= row - i;
        denominator *= i;
        ans[i] = numerator / denominator;
    }
    return ans;
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
    std::vector<std::vector<int>> v1 = generate(5);
    std::cout << "Printing Pascal Triangle: " << std::endl;
    print(v1);
    std::cout << std::endl;

    std::cout << "Element: " << find_element(10, 3) << std::endl
              << std::endl;

    std::vector<int> v2 = generate_row(5);
    std::cout << "Printing Pascal Triangle row: " << std::endl;
    print(v2);
    return 0;
}

// https://leetcode.com/problems/pascals-triangle/