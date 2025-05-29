#include <iostream>

void print_pattern(int n)
{
    for (int i = (-n + 1); i < n; i++)
    {
        for (int j = 0; j < (n - std::abs(i)); j++)
        {
            std::cout << '*';
        }
        std::cout << std::endl;
    }
}

int main()
{
    print_pattern(3);
    return 0;
}

// https://www.naukri.com/code360/problems/rotated-triangle_6573688