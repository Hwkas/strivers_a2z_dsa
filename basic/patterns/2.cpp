#include <iostream>

void print_pattern(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    print_pattern(5);
    return 0;
}

// https://www.naukri.com/code360/problems/n-2-forest_6570178