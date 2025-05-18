#include <iostream>

std::vector<int> generate_state(std::vector<std::string> &words)
{
    std::vector<int> state;
    int n = words.size();

    for (int i = 0; i < n; i++)
    {
        int m = words[i].size();
        int temp = 0;
        for (int j = 0; j < m; j++)
        {
            temp |= (1 << (words[i][j] - 'a'));
        }
        state.push_back(temp);
    }
    return state;
}

int maxProduct(std::vector<std::string> &words)
{
    std::vector<int> state = generate_state(words);
    int n = words.size();
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (
                ((state[i] & state[j]) == 0) &&
                ((int)(words[i].size() * words[j].size()) > max))
            {
                max = words[i].size() * words[j].size();
            }
        }
    }
    return max;
}

int main()
{
    std::vector<std::string> words;
    words.push_back("abcw");
    words.push_back("baz");
    words.push_back("foo");
    words.push_back("bar");
    words.push_back("xtfn");
    words.push_back("abcdef");

    std::cout << "Max words count: " << maxProduct(words) << std::endl;
    return 0;
}

// https://leetcode.com/problems/maximum-product-of-word-lengths/submissions/1524605177/?envType=problem-list-v2&envId=bit-manipulation