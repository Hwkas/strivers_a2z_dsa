#include <iostream>

std::string postfixToPrefix(std::string &s)
{
    std::unordered_map<char, int> mp = {{'^', 3},
                                        {'*', 2},
                                        {'/', 2},
                                        {'+', 1},
                                        {'-', 1},
                                        {'(', 0},
                                        {')', 0}};

    std::stack<std::string> stk;

    for (const auto &c : s)
    {
        if (std::isalpha(c) || std::isdigit(c))
        {
            stk.push(std::string(1, c));
        }
        else
        {
            std::string second = stk.top();
            stk.pop();
            std::string first = stk.top();
            stk.pop();

            stk.push(c + first + second);
        }
    }

    return stk.top();
}

int main()
{

    std::string s = "abc*+";
    std::cout << postfixToPrefix(s) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/postfix-to-prefix_1788455