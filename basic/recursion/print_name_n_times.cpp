#include <iostream>

void pirnt_name(std::string name, int n)
{
    if (n == 0)
    {
        return;
    }
    std::cout << name << std::endl;
    pirnt_name(name, --n);
}

int main()
{
    pirnt_name("Hwkas", 5);
    return 0;
}