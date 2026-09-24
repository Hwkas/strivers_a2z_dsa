#include <iostream>

std::string removeKdigits(std::string num, int k)
{
    if (num.size() == k)
    {
        return "0";
    }

    std::string ans;

    for (const auto &i : num)
    {
        while (
            (k > 0) &&
            (!ans.empty()) &&
            (ans.back() > i))
        {
            ans.pop_back();
            k--;
        }
        ans += i;
    }

    while (k-- > 0)
    {
        ans.pop_back();
    }

    while ((!ans.empty()) && (ans.front() == '0'))
    {
        ans = ans.substr(1);
    }

    return (ans.empty() ? "0" : ans);
}

int main()
{
    std::cout << removeKdigits("10200", 1) << std::endl;
    return 0;
}

// https://leetcode.com/problems/remove-k-digits/submissions/2142693515/