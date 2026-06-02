#include <iostream>

std::string longestPalindrome(std::string s)
{
    int n = s.size(), left = 0, right = 0, start = 0, max_len = 0;

    for (int i = 0; i < n; i++)
    {
        // odd length
        left = i;
        right = i;
        while ((left >= 0) && (right < n) && (s[left] == s[right]))
        {
            left--;
            right++;
        }

        if (max_len < (right - left - 1))
        {
            start = left + 1;
            max_len = (right - left - 1);
        }

        // even length
        left = i;
        right = i + 1;
        while ((left >= 0) && (right < n) && (s[left] == s[right]))
        {
            left--;
            right++;
        }

        if (max_len < (right - left - 1))
        {
            start = left + 1;
            max_len = (right - left - 1);
        }
    }
    return s.substr(start, max_len);
}

int main()
{
    std::string s = "bb";
    // "bb";
    // "babad";
    std::cout << "Longest Palindromic Substring is " << longestPalindrome(s) << std::endl;
    return 0;
}

// https://leetcode.com/problems/longest-palindromic-substring/description/