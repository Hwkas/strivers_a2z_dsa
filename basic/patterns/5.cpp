#include <iostream>

void print_pattern(int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    print_pattern(3);
    return 0;
}

// https://www.naukri.com/code360/problems/seeding_6581892