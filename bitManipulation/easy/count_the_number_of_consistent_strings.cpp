#include <iostream>

int func(std::string &str)
{
    int temp = 0;
    int size = str.size();
    for (int i = 0; i < size; i++)
    {
        temp |= (1 << (str[i] - 'a'));
    }
    return temp;
}

int countConsistentStrings(std::string allowed, std::vector<std::string> &words)
{
    int val = func(allowed);
    int count = 0;
    int size = words.size();

    for (int i = 0; i < size; i++)
    {
        // using (val | func(words[i])) == val instead of (val == func(words[i]))
        // because allowed = "abc", word = "a" , then this word would be allowed
        // as it has only a in it.
        count += (val | func(words[i])) == val;
    }
    return count;
}

int main()
{
    std::string allowed = "abc";
    std::vector<std::string> words;

    words.push_back("a");
    words.push_back("b");
    words.push_back("c");
    words.push_back("ab");
    words.push_back("ac");
    words.push_back("bc");
    words.push_back("abc");
    std::cout << countConsistentStrings(allowed, words) << std::endl;
    return 0;
}

// https://leetcode.com/problems/count-the-number-of-consistent-strings/submissions/1484433964/?envType=problem-list-v2&envId=bit-manipulation