#include <iostream>

int ToggleithBit(int n, int i)
{
    return (n ^ (1 << i));
}

int main()
{
    std::cout << ToggleithBit(13, 2) << std::endl;
    return 0;
}