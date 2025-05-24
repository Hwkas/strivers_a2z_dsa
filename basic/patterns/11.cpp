#include <iostream>

// my solution
void print_pattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j >= 0; j--)
        {
            std::cout << ((j & 1) ? 0 : 1) << ' ';
        }
        std::cout << std::endl;
    }
}

// another approach
// void print_pattern(int n)
// {
//     int num = 1;
//     for (int i = 0; i < n; i++)
//     {
//         int cur = 0;
//         for (int j = 1; j <= num; j++)
//         {
//             cur = ((i + j) & 1);
//             std::cout << cur << " ";
//         }
//         std::cout << '\n';
//         num++;
//     }
// }

int main()
{
    print_pattern(3);
    return 0;
}

// https://www.naukri.com/code360/problems/binary-number-triangle_6581890