#include <iostream>

char findTheDifference(std::string s, std::string t)
{
    int n = s.size();
    char ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= s[i];
        ans ^= t[i];
    }
    ans ^= t[n];
    return ans;
}

int main()
{
    std::cout << findTheDifference("abcd", "abcde") << std::endl;
    return 0;
}

// https://leetcode.com/problems/find-the-difference/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY