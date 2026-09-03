#include <iostream>

std::string infixToPrefix(std::string exp)
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

    std::reverse(exp.begin(), exp.end());

    for (auto &c : exp)
    {
        if (c == '(')
        {
            c = ')';
        }
        else if (c == ')')
        {
            c = '(';
        }
    }

    for (const auto &c : exp)
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
            if (c == '^')
            {
                while (!s.empty() && (mp[c] <= mp[s.top()]))
                {
                    ans.push_back(s.top());
                    s.pop();
                }
            }
            else
            {
                while (!s.empty() && (mp[c] < mp[s.top()]))
                {
                    ans.push_back(s.top());
                    s.pop();
                }
            }
            s.push(c);
        }
    }

    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    std::reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    std::cout << infixToPrefix("x+y*z/w+u") << std::endl;
    return 0;
}