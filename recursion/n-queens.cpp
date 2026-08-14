#include <iostream>

// My Solution
bool checkValidCell(
    const std::vector<std::string> &board,
    int row,
    int col)
{
    int n = board.size();

    for (int i = 0; i < row; i++)
    {
        if (
            (board[i][col] == 'Q') ||                                        // Check if there is a queen in the same column above
            ((col + (row - i)) < n && (board[i][col + (row - i)] == 'Q')) || //  Check upper-right diagonal (row - i, col + i)
            ((col - (row - i)) >= 0 && (board[i][col - (row - i)] == 'Q'))   // Check upper-left diagonal (row - i, col - i)
        )
        {
            return false;
        }
    }

    return true;
}

void placeNQueens(
    int n,
    std::vector<std::vector<std::string>> &result,
    std::vector<std::string> &board,
    int row)
{
    if (row == n)
    {
        result.push_back(board);
        return;
    }

    for (int col = 0; col < n; col++)
    {
        if (checkValidCell(board, row, col))
        {
            board[row][col] = 'Q';

            placeNQueens(n, result, board, (row + 1));

            board[row][col] = '.';
        }
    }
}

std::vector<std::vector<std::string>> solveNQueens(int n)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> board(n, std::string(n, '.'));

    placeNQueens(n, result, board, 0);

    return result;
}

// Striver's Solution
// void solve(
//     int col,
//     std::vector<std::string> &board,
//     int n,
//     std::vector<int> &leftRow,
//     std::vector<int> &upperDiagonal,
//     std::vector<int> &lowerDiagonal,
//     std::vector<std::vector<std::string>> &ans)
// {
//     // If all queens are placed
//     if (col == n)
//     {
//         ans.push_back(board);
//         return;
//     }

//     // Iterate through all rows
//     for (int row = 0; row < n; row++)
//     {
//         // Check if it's safe to place the queen
//         if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 &&
//             upperDiagonal[n - 1 + col - row] == 0)
//         {

//             // Place the queen
//             board[row][col] = 'Q';

//             // Mark the row and diagonals
//             leftRow[row] = 1;
//             lowerDiagonal[row + col] = 1;
//             upperDiagonal[n - 1 + col - row] = 1;

//             // Recurse to next column
//             solve(col + 1, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);

//             // Backtrack and remove the queen
//             board[row][col] = '.';
//             leftRow[row] = 0;
//             lowerDiagonal[row + col] = 0;
//             upperDiagonal[n - 1 + col - row] = 0;
//         }
//     }
// }

// std::vector<std::vector<std::string>> solveNQueens(int n)
// {
//     std::vector<std::vector<std::string>> ans;
//     std::vector<std::string> board(n, std::string(n, '.'));
//     std::vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
//     solve(0, board, n, leftRow, upperDiagonal, lowerDiagonal, ans);
//     return ans;
// }

void print(const std::vector<std::vector<std::string>> &arr)
{
    std::cout << "[\n";
    for (const auto &temp : arr)
    {
        std::size_t size = temp.size();
        std::cout << "\t[";
        for (std::size_t i = 0; i < size; ++i)
        {
            std::cout << temp[i] << ((i == (size - 1)) ? "" : ", ");
        }
        std::cout << "]\n";
    }
    std::cout << "]\n";
}

int main()
{
    std::vector<std::vector<std::string>> result = solveNQueens(4);
    print(result);
    return 0;
}

// https://leetcode.com/problems/n-queens/description/