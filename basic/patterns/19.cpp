#include <iostream>

// // my solution
// void print_pattern(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < (n * 2); j++)
//         {
//             if (j < (n - i) || j >= (n + i))
//             {
//                 std::cout << '*' << ' ';
//             }
//             else
//             {
//                 std::cout << "  ";
//             }
//         }
//         std::cout << std::endl;
//     }
//     for (int i = (n - 1); i >= 0; i--)
//     {
//         for (int j = 0; j < (n * 2); j++)
//         {
//             if (j < (n - i) || j >= (n + i))
//             {
//                 std::cout << '*' << ' ';
//             }
//             else
//             {
//                 std::cout << "  ";
//             }
//         }
//         std::cout << std::endl;
//     }
// }

// another approach
void print_pattern(int n)
{
    n = 2 * n;
    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {

            // Condition for first half of the rows.
            if (row < n / 2 && (col < (n / 2 - row) || col >= (n / 2 + row)))
            {
                std::cout << '*';
            }

            // Condition for the second half of the rows.
            else if (row >= n / 2 && (col <= (row - n / 2) || col >= (n - row + n / 2 - 1)))
            {
                std::cout << '*';
            }

            else
            {
                std::cout << ' ';
            }

            std::cout << ' ';
        }

        // End the current row of the pattern.
        std::cout << std::endl;
    }
}

int main()
{
    print_pattern(3);
    return 0;
}

// https://www.naukri.com/code360/problems/symmetric-void_6581919