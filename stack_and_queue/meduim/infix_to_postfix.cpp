#include <iostream>

std::string infixToPostfix(std::string exp)
{
    std::unordered_map<char, int> mp = {{'^', 3},
                                        {'*', 2},
                                        {'/', 2},
                                        {'+', 1},
                                        {'-', 1},
                                        {'(', 0},
                                        {')', 0}};
    std::string ans;
    std::stack<char> s;

    for (const auto c : exp)
    {
        if ((c >= '0' && c <= '9') ||
            (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z'))
        {
            ans.push_back(c);
        }
        else if (c == '(')
        {
            s.push(c);
        }
        else if (c == ')')
        {
            while (s.top() != '(')
            {
                ans.push_back(s.top());
                s.pop();
            }
            s.pop();
        }
        else
        {
            while (!s.empty() && mp[s.top()] >= mp[c])
            {
                ans.push_back(s.top());
                s.pop();
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    return ans;
}

int main()
{
    std::cout << infixToPostfix("a+b+c+d-e") << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/infix-to-postfix_1382146?leftPanelTabValue=SUBMISSION