#include <iostream>

std::string prefixToInfixConversion(std::string &s)
{
    std::unordered_map<char, int> mp = {{'^', 3},
                                        {'*', 2},
                                        {'/', 2},
                                        {'+', 1},
                                        {'-', 1},
                                        {'(', 0},
                                        {')', 0}};

    std::stack<std::string> stk;

    for (int i = (s.size() - 1); i >= 0; i--)
    {
        if (std::isalpha(s[i]) || std::isdigit(s[i]))
        {
            stk.push(std::string(1, s[i]));
        }
        else
        {
            std::string first = stk.top();
            stk.pop();
            std::string second = stk.top();
            stk.pop();

            stk.push("(" + first + s[i] + second + ")");
        }
    }
    return stk.top();
}

int main()
{
    std::string s = "/-ab+-cde";
    std::cout << prefixToInfixConversion(s) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/prefix-to-infix_1215000