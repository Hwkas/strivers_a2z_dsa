#include <iostream>

void print_pattern(int n)
{
    for (int i = (-n + 1); i < n; i++)
    {
        for (int j = 0; j < (n * 2); j++)
        {
            if (j < (n - std::abs(i)) || j >= (n + std::abs(i)))
            {
                std::cout << '*' << ' ';
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

// https://www.naukri.com/code360/problems/symmetry_6581914?leftPanelTabValue=SUBMISSION