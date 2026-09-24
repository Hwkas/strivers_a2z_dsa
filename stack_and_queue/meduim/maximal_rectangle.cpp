#include <iostream>

int largestRectangleArea(std::vector<int> &heights)
{
    std::stack<int> s;
    int max = 0, n = heights.size();

    for (int i = 0; i < n; i++)
    {
        while ((!s.empty()) && (heights[s.top()] > heights[i]))
        {
            int val = heights[s.top()];

            s.pop();

            int left = s.empty() ? -1 : s.top();

            max = std::max(max, val * (i - left - 1));
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int val = heights[s.top()];

        s.pop();

        int left = s.empty() ? -1 : s.top();

        max = std::max(max, val * (n - left - 1));
    }

    return max;
}

int maximalRectangle(std::vector<std::vector<char>> &matrix)
{
    std::vector<int> histogram(matrix[0].size(), 0);
    int max = 0;

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
        {
            histogram[j] = ((matrix[i][j] == '1') ? (histogram[j] + 1) : 0);
        }

        max = std::max(max, largestRectangleArea(histogram));
    }

    return max;
}

int main()
{
    std::vector<std::vector<char>> matrix = {{'1', '0', '1', '0', '0'},
                                             {'1', '0', '1', '1', '1'},
                                             {'1', '1', '1', '1', '1'},
                                             {'1', '0', '0', '1', '0'}};
    std::cout << maximalRectangle(matrix) << std::endl;
    return 0;
}

// https://leetcode.com/problems/maximal-rectangle/submissions/2145922983/