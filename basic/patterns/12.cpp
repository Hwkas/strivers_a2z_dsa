#include <iostream>

void print_pattern(int n)
{
    int k;
    for (int i = 1; i <= n; i++)
    {
        k = i;
        for (int j = 1; j <= (n * 2); j++)
        {

            if (j <= i)
            {
                std::cout << j << ' ';
            }
            else if (j > ((n * 2) - i))
            {
                std::cout << k-- << ' ';
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

// https://www.naukri.com/code360/problems/number-crown_6581894