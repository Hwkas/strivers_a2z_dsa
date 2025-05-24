#include <iostream>

// my approch
// void print_pattern(int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = (-n + 1); j < n; j++)
//         {
//             std::cout << ((j >= -i && j <= i) ? '*' : ' ');
//         }
//         std::cout << std::endl;
//     }
//     for (int i = n - 1; i >= 0; i--)
//     {
//         for (int j = (-n + 1); j < n; j++)
//         {
//             std::cout << ((j >= -i && j <= i) ? '*' : ' ');
//         }
//         std::cout << std::endl;
//     }
// }

// optimal approch
void print_pattern(int n)
{
    int gap = n - 1, stars = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < gap; j++)
        {
            std::cout << ' ';
        }
        for (int j = gap; j < gap + stars; j++)
        {
            std::cout << '*';
        }
        std::cout << '\n';

        gap--;
        stars += 2;
    }

    gap = 0;
    stars = (n * 2) - 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < gap; j++)
        {
            std::cout << ' ';
        }
        for (int j = gap; j < gap + stars; j++)
        {
            std::cout << '*';
        }
        std::cout << '\n';

        gap++;
        stars -= 2;
    }
}

int main()
{
    print_pattern(3);
    return 0;
}

// https://www.naukri.com/code360/problems/star-diamond_6573686