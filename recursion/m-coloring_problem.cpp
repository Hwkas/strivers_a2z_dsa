#include <iostream>
#include <unordered_set>

// My Solution
bool dfs(
    std::vector<std::vector<int>> &mat,
    int m,
    std::vector<int> &colour_tracker,
    int row)
{
    if (row == mat.size())
    {
        return true;
    }

    std::vector<int> available_colours(m, 1);
    int i = 0;
    for (; i < row; i++)
    {
        if ((mat[row][i] != 0) && (colour_tracker[i] != -1))
        {
            available_colours[colour_tracker[i]] = 0;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (available_colours[j])
        {
            colour_tracker[row] = j;
            if (dfs(mat, m, colour_tracker, (row + 1)))
            {
                return true;
            }
            colour_tracker[row] = -1;
        }
    }
    return false;
}

std::string graphColoring(std::vector<std::vector<int>> &mat, int m)
{
    std::vector<int> colour_tracker(mat.size(), -1);
    return dfs(mat, m, colour_tracker, 0) ? "YES" : "NO";
}

int main()
{
    std::vector<std::vector<int>> mat = {{0, 1, 0},
                                         {1, 0, 1},
                                         {0, 1, 0}};

    std::cout << graphColoring(mat, 2) << std::endl;

    return 0;
}

// https://www.naukri.com/code360/problems/m-coloring-problem_981273