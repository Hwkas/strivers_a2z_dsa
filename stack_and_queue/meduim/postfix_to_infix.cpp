#include <iostream>

std::string postToInfix(std::string exp)
{
    std::unordered_map<char, int> mp = {{'^', 3},
                                        {'*', 2},
                                        {'/', 2},
                                        {'+', 1},
                                        {'-', 1},
                                        {'(', 0},
                                        {')', 0}};

    std::stack<std::string> s;

    for (const auto &c : exp)
    {
        if (std::isalpha(c) || std::isdigit(c))
        {
            s.push(std::string(1, c));
        }
        else
        {
            std::string second = s.top();
            s.pop();
            std::string first = s.top();
            s.pop();

            s.push("(" + first + c + second + ")");
        }
    }

    return s.top();
}

int main()
{
    std::cout << postToInfix("ab+c+") << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/postfix-to-infix_8382386