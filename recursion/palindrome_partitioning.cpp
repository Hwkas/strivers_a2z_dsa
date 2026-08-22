#include <iostream>

bool isPalindrome(std::string &s, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    return (s[start] != s[end]) ? false : isPalindrome(s, start + 1, end - 1);
}

void generatePalindromePartitions(
    std::string &s,
    std::vector<std::vector<std::string>> &result,
    std::vector<std::string> &v,
    int start,
    int end)
{
    if (start == end)
    {
        result.push_back(v);
        return;
    }

    for (int i = start; i < end; i++)
    {
        if (isPalindrome(s, start, i))
        {
            v.push_back(s.substr(start, (i - start + 1)));
            generatePalindromePartitions(s, result, v, (i + 1), end);
            v.pop_back();
        }
    }
}

std::vector<std::vector<std::string>> partition(std::string s)
{
    std::vector<std::vector<std::string>> result;
    std::vector<std::string> v;

    generatePalindromePartitions(s, result, v, 0, s.size());

    return result;
}

void print(const std::vector<std::vector<std::string>> &arr)
{
    std::cout << "[\n";
    for (const auto &temp : arr)
    {
        std::size_t size = temp.size();
        std::cout << "\t[";
        for (std::size_t i = 0; i < size; ++i)
        {
            std::cout << temp[i] << ((i == (size - 1)) ? "" : ", ");
        }
        std::cout << "]\n";
    }
    std::cout << "]\n";
}

int main()
{
    std::vector<std::vector<std::string>> result = partition("aabb");
    print(result);
    return 0;
}

// https://leetcode.com/problems/palindrome-partitioning/description/