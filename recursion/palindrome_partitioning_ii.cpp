#include <iostream>

bool isPalindrome(std::string &s, int start, int end)
{
    if (start >= end)
    {
        return true;
    }

    return (s[start] != s[end]) ? false : isPalindrome(s, start + 1, end - 1);
}

int calculateMinPartitionCuts(std::string &s, std::vector<int> &dp, int start, int end)
{
    if (start == end)
    {
        return 0;
    }

    if (dp[start] != -1)
    {
        return dp[start];
    }

    int min_cost = INT_MAX;

    for (int i = start; i < end; i++)
    {
        if (isPalindrome(s, start, i))
        {
            int cost = 1 + calculateMinPartitionCuts(s, dp, (i + 1), end);
            min_cost = std::min(min_cost, cost);
        }
    }
    return dp[start] = min_cost;
}

int minCut(std::string s)
{
    int n = s.size();
    std::vector<int> dp(n, -1);
    return (calculateMinPartitionCuts(s, dp, 0, n) - 1);
}

int main()
{
    std::string s = "aabb";
    std::cout << "The minimum cuts needed for a palindrome partitioning of " << s << " is " << minCut(s) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/palindrome-partitioning-ii/description/