#include <iostream>

void print_pattern(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            std::cout << count++ << ' ';
        }
        std::cout << std::endl;
    }
}

int main()
{
    print_pattern(3);
    return 0;
}

// https://www.naukri.com/code360/problems/increasing-number-triangle_6581893