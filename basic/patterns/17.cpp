#include <iostream>

void print_pattern(int n)
{
    char c;
    for (int i = 0; i < n; i++)
    {
        c = 'A';
        for (int j = (-n + 1); j < n; j++)
        {
            if (std::abs(j) <= i)
            {
                std::cout << c << ' ';
                (j < 0) ? c++ : c--;
            }
            else
            {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

int main()
{
    print_pattern(3);
    return 0;
}

// https://www.naukri.com/code360/problems/alpha-hill_6581921