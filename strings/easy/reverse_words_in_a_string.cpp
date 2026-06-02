#include <iostream>

// My Solution
// std::string reverseWords(std::string s)
// {
//     std::string reversed_words;
//     std::string word;
//     bool empty_space = false;

//     for (const auto &c : s)
//     {
//         if (c != ' ')
//         {
//             word += c;
//             if (empty_space && !reversed_words.empty() && reversed_words.front() != ' ')
//             {
//                 reversed_words = ' ' + reversed_words;
//             }
//         }
//         else
//         {
//             reversed_words = word + reversed_words;
//             word.clear();
//             empty_space = true;
//         }
//     }
//     reversed_words = word + reversed_words;
//     return reversed_words;
// }

// Striver's Brute Force
// std::string reverseWords(std::string s)
// {
//     std::string reversed_words;
//     std::vector<std::string> words;
//     std::string word;

//     for (const auto &c : s)
//     {
//         if (c != ' ')
//         {
//             word += c;
//         }
//         else if (!word.empty())
//         {
//             words.push_back(word);
//             word.clear();
//         }
//     }

//     if (!word.empty())
//     {
//         words.push_back(word);
//     }

//     int n = words.size();

//     for (int i = (n - 1); i > 0; i--)
//     {
//         reversed_words += words[i] + ' ';
//     }
//     reversed_words += words[0];
//     return reversed_words;
// }

// Optimal Approach
std::string reverseWords(std::string s)
{
    std::reverse(s.begin(), s.end());
    int n = s.size(), left = 0, right = 0, i = 0;
    while (i < n)
    {
        while ((i < n) && (s[i] == ' '))
        {
            i++;
        }
        if (i == n)
        {
            break;
        }
        while (i < n && s[i] != ' ')
        {
            s[right++] = s[i++];
        }
        std::reverse(s.begin() + left, s.begin() + right);
        s[right++] = ' ';
        left = right;
        i++;
    }
    s.resize(right - 1);
    return s;
}

int main()
{
    std::string s = "       the sky      is blue        ";
    std::cout << "Reversed Word is " << reverseWords(s) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/reverse-words-in-a-string/