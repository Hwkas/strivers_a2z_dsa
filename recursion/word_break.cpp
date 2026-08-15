#include <iostream>
#include <unordered_set>

bool dfs(
    std::string &s,
    std::unordered_set<std::string> &st,
    std::vector<int> &t,
    int index)
{
    if ((index >= s.size()) || (st.find(s.substr(index)) != st.end()))
    {
        return true;
    }

    if (t[index] != -1)
    {
        return t[index];
    }

    for (int i = 1; i < s.size(); i++)
    {
        if (
            st.find(s.substr(index, i)) != st.end() &&
            dfs(s, st, t, (index + i)))
        {
            return t[index] = true;
        }
    }
    return t[index] = false;
}

bool wordBreak(std::string s, std::vector<std::string> &wordDict)
{
    std::unordered_set<std::string> st(wordDict.begin(), wordDict.end());
    std::vector<int> t(s.size(), -1);

    return dfs(s, st, t, 0);
}

int main()
{
    std::string s = "leetcode";

    std::vector<std::string> wordDict = {"leet", "code"};

    std::cout << (wordBreak(s, wordDict) ? "True" : "False") << std::endl;

    return 0;
}

// https://leetcode.com/problems/word-break/