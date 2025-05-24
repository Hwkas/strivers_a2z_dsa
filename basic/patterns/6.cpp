#include <iostream>

void print_pattern(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << j + 1 << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    print_pattern(5);
    return 0;
}

// https://www.naukri.com/code360/problems/reverse-number-triangle_6581889