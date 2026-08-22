#include <iostream>
#include <unordered_set>

// My Solution
bool isValidCellValue(
    std::vector<std::vector<char>> &board,
    int row,
    int col,
    char c)
{
    int sub_box_row_start = (row / 3) * 3;
    int sub_box_col_start = (col / 3) * 3;

    for (int i = 0; i < 9; i++)
    {
        if (
            (board[row][i] == c) ||
            (board[i][col] == c) ||
            (board[sub_box_row_start + (i / 3)][sub_box_col_start + (i % 3)] == c))
        {
            return false;
        }
    }

    return true;
}

bool dfs(
    std::vector<std::vector<char>> &board,
    int row,
    int col)
{
    if (row == 9)
    {
        return true;
    }

    if (col == 9)
    {
        return dfs(board, (row + 1), 0);
    }

    if (board[row][col] != '.')
    {
        return dfs(board, row, (col + 1));
    }

    for (char i = '1'; i <= '9'; i++)
    {
        if (isValidCellValue(board, row, col, i))
        {
            board[row][col] = i;

            if (dfs(board, row, (col + 1)))
            {
                return true;
            }

            board[row][col] = '.';
        }
    }

    return false;
}

void solveSudoku(std::vector<std::vector<char>> &board)
{
    dfs(board, 0, 0);
}

// Striver's Solution
// bool isValid(std::vector<std::vector<char>> &board, int row, int col, char c)
// {

//     for (int i = 0; i < 9; i++)
//     {

//         if (board[i][col] == c)
//             return false;
//     }

//     for (int j = 0; j < 9; j++)
//     {

//         if (board[row][j] == c)
//             return false;
//     }

//     int boxRowStart = 3 * (row / 3);
//     int boxColStart = 3 * (col / 3);

//     for (int i = 0; i < 3; i++)
//     {
//         for (int j = 0; j < 3; j++)
//         {

//             if (board[boxRowStart + i][boxColStart + j] == c)
//                 return false;
//         }
//     }

//     return true;
// }

// bool dfs(std::vector<std::vector<char>> &board)
// {
//     for (int i = 0; i < 9; i++)
//     {
//         for (int j = 0; j < 9; j++)
//         {
//             if (board[i][j] == '.')
//             {
//                 for (char c = '1'; c <= '9'; c++)
//                 {
//                     if (isValid(board, i, j, c))
//                     {
//                         board[i][j] = c;

//                         if (dfs(board))
//                             return true;

//                         board[i][j] = '.';
//                     }
//                 }

//                 return false;
//             }
//         }
//     }

//     return true;
// }

// void solveSudoku(std::vector<std::vector<char>> &board)
// {
//     dfs(board);
// }

void print(std::vector<std::vector<char>> &arr)
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
    std::vector<std::vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
                                            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
                                            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
                                            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
                                            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
                                            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
                                            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
                                            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
                                            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};

    solveSudoku(board);

    print(board);

    return 0;
}

// https://leetcode.com/problems/sudoku-solver/description/