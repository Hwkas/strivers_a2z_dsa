#include <iostream>

bool solve(std::string &s, int start, int end)
{
    if (start >= end)
    {
        return true;
    }
    return (s[start] != s[end]) ? false : solve(s, start + 1, end - 1);
}

bool isPalindrome(std::string s)
{
    std::string refined_s;
    for (auto i : s)
    {
        if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || (i >= '0' && i <= '9'))
        {
            i = (i >= 'A' && i <= 'Z') ? char(i + 32) : i;
            refined_s.push_back(i);
        }
    }
    std::cout << refined_s << std::endl;
    return (refined_s.empty() ? true : solve(refined_s, 0, refined_s.size() - 1));
}

int main()
{
    std::string s = "A man, a plan, a canal: Panama";
    std::cout << "ans: " << isPalindrome(s) << std::endl;
    return 0;
}

// https://leetcode.com/problems/valid-palindrome/description/