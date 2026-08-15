#include <iostream>

// My Solution
void dfs(
    std::vector<std::vector<int>> &arr,
    std::vector<std::string> &result,
    std::string &path,
    int n,
    int row,
    int col)
{
    if ((row == (n - 1)) && (col == (n - 1)))
    {
        result.push_back(path);
        return;
    }

    if ((row == n) || (col == n) || (row < 0) || (col < 0) || (arr[row][col] == 0))
    {
        return;
    }

    arr[row][col] = 0;

    path.push_back('D');
    dfs(arr, result, path, n, (row + 1), col); // Down
    path.pop_back();

    path.push_back('L');
    dfs(arr, result, path, n, row, (col - 1)); // Left
    path.pop_back();

    path.push_back('R');
    dfs(arr, result, path, n, row, (col + 1)); // Right
    path.pop_back();

    path.push_back('U');
    dfs(arr, result, path, n, (row - 1), col); // Up
    path.pop_back();

    arr[row][col] = 1;
}

std::vector<std::string> searchMaze(std::vector<std::vector<int>> &arr, int n)
{
    std::vector<std::string> result;
    std::string path;

    dfs(arr, result, path, n, 0, 0);

    return result;
}

// Striver's Solution
// void dfs(
//     std::vector<std::vector<int>> &arr,
//     std::vector<std::string> &result,
//     std::string &path,
//     std::string &dir,
//     std::vector<int> &di,
//     std::vector<int> &dj,
//     int n,
//     int row,
//     int col)
// {
//     if ((row == (n - 1)) && (col == (n - 1)))
//     {
//         result.push_back(path);
//         return;
//     }

//     for (int index = 0; index < 4; index++)
//     {
//         int next_row = (row + di[index]);
//         int next_col = (col + dj[index]);

//         if (
//             (next_row >= 0) &&
//             (next_col >= 0) &&
//             (next_row < n) &&
//             (next_col < n) &&
//             ((arr[next_row][next_col] == 1)))
//         {
//             arr[next_row][next_col] = 0;
//             path.push_back(dir[index]);

//             dfs(arr, result, path, dir, di, dj, n, next_row, next_col);

//             arr[next_row][next_col] = 1;
//             path.pop_back();
//         }
//     }
// }

// std::vector<std::string> searchMaze(std::vector<std::vector<int>> &arr, int n)
// {
//     std::vector<std::string> result;
//     std::string path;
//     std::string dir = "DLRU";
//     std::vector<int> di = {1, 0, 0, -1};
//     std::vector<int> dj = {0, -1, 1, 0};

//     if (n > 0 && arr[0][0] == 1)
//     {
//         arr[0][0] = 0;
//         dfs(arr, result, path, dir, di, dj, n, 0, 0);
//         arr[0][0] = 1;
//     }

//     return result;
// }

void print(std::vector<std::string> &arr)
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
    std::vector<std::vector<int>> arr = {{1, 0, 0, 0},
                                         {1, 1, 0, 0},
                                         {1, 1, 0, 0},
                                         {0, 1, 1, 1}};

    std::vector<std::string> result = searchMaze(arr, 4);
    print(result);
    return 0;
}

// https://www.naukri.com/code360/problems/rat-in-a-maze_1215030?leftPanelTabValue=SUBMISSION