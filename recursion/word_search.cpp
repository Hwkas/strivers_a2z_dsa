#include <iostream>

// My Solution
bool dfs(
    std::vector<std::vector<char>> &board,
    std::string &word,
    std::vector<int> &path,
    int row,
    int col,
    int index)
{
    if (index == word.size())
    {
        return true;
    }

    if (
        (row < 0) ||
        (col < 0) ||
        (row >= board.size()) ||
        (col >= board[0].size()) ||
        path[(row * board[0].size()) + col] ||
        board[row][col] != word[index])
    {
        return false;
    }

    path[(row * board[0].size()) + col] = 1;

    bool ans = (dfs(board, word, path, row, (col + 1), (index + 1)) || // Right
                dfs(board, word, path, row, (col - 1), (index + 1)) || // Left
                dfs(board, word, path, (row - 1), col, (index + 1)) || // Up
                dfs(board, word, path, (row + 1), col, (index + 1)));  // Down

    path[(row * board[0].size()) + col] = 0;

    return ans;
}

bool exist(std::vector<std::vector<char>> &board, std::string word)
{
    std::vector<int> path((board.size() * board[0].size()), 0);

    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (dfs(board, word, path, i, j, 0))
            {
                return true;
            }
        }
    }
    return false;
}

// Striver's Solution
// bool dfs(std::vector<std::vector<char>> &board, std::string &word, int i, int j, int idx)
// {
//     // If all characters matched, return true
//     if (idx == word.size())
//         return true;

//     // Check boundaries and character match
//     if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] != word[idx])
//     {
//         return false;
//     }

//     // Store current character and mark as visited
//     char temp = board[i][j];
//     board[i][j] = '#';

//     // Explore all four directions
//     bool found = dfs(board, word, i + 1, j, idx + 1) ||
//                  dfs(board, word, i - 1, j, idx + 1) ||
//                  dfs(board, word, i, j + 1, idx + 1) ||
//                  dfs(board, word, i, j - 1, idx + 1);

//     // Restore the character (backtracking)
//     board[i][j] = temp;

//     return found;
// }

// bool exist(std::vector<std::vector<char>> &board, std::string word)
// {
//     // Get number of rows
//     int rows = board.size();
//     // Get number of columns
//     int cols = board[0].size();

//     // Loop through every cell in the grid
//     for (int i = 0; i < rows; i++)
//     {
//         for (int j = 0; j < cols; j++)
//         {
//             // Start DFS if first letter matches
//             if (dfs(board, word, i, j, 0))
//             {
//                 return true;
//             }
//         }
//     }
//     // If no path found, return false
//     return false;
// }

int main()
{
    std::vector<std::vector<char>> board = {{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::string word = "ABCCED";
    std::cout << (exist(board, word) ? "True" : "False") << std::endl;
    return 0;
}

// https://leetcode.com/problems/word-search/submissions/2104280769/