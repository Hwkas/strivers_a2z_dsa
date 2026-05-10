#include <iostream>

std::string largestOddNumber(std::string num)
{
    int n = num.size();
    int i = (n - 1), digit = 0;

    while (i >= 0)
    {
        digit = num[i] - '0';
        if ((digit > 0) && ((digit % 2) != 0))
        {
            break;
        }
        i--;
    }
    return num.substr(0, (i + 1));
}

int main()
{
    std::string num = "52";
    std::cout << "Largest Odd Number in String is " << largestOddNumber(num) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/largest-odd-number-in-string/submissions/1999503421/