#include <iostream>

bool isValid(std::string s)
{
    std::stack<char> stk;

    for (const auto &i : s)
    {
        if (
            i == '(' ||
            i == '[' ||
            i == '{')
        {
            stk.push(i);
        }
        else
        {
            if (
                stk.empty() ||
                (i == ')' && stk.top() != '(') ||
                (i == ']' && stk.top() != '[') ||
                (i == '}' && stk.top() != '{'))
            {
                return false;
            }
            stk.pop();
        }
    }

    return stk.empty();
}

int main()
{
    std::cout << (isValid("(([{}))") ? "True" : "False") << std::endl;
    return 0;
}

// https://leetcode.com/problems/valid-parentheses/description/