#include <iostream>

int helper(const std::string &s, int i, long long num, int sign)
{
    if ((i >= s.size()) || !isdigit(s[i]))
    {
        return (int)(sign * num);
    }

    num = num * 10 + (s[i] - '0');

    if (sign * num <= INT_MIN)
    {
        return INT_MIN;
    }
    if (sign * num >= INT_MAX)
    {
        return INT_MAX;
    }
    return helper(s, i + 1, num, sign);
}

int myAtoi(std::string s)
{
    int i = 0;
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }
    int sign = 1;
    if ((i < s.size()) && ((s[i] == '+') || (s[i] == '-')))
    {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }
    return helper(s, i, 0, sign);
}

int main()
{
    std::string s = "0-1";
    // "21474836460";
    std::cout << "String to Integer is " << myAtoi(s) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/string-to-integer-atoi/submissions/2007376331/