#include <iostream>

void print_pattern(int n)
{
    int k = n * 2 - 1;
    int x, y;
    for (int i = 0; i < k; i++)
    {
        x = std::abs(i - n + 1);
        for (int j = 0; j < k; j++)
        {
            y = std::abs(j - n + 1);
            std::cout << (std::max(x, y) + 1);
        }
        std::cout << std::endl;
    }
}

int main()
{
    print_pattern(3);
    return 0;
}

// https://www.naukri.com/code360/problems/ninja-and-the-number-pattern-i_6581959