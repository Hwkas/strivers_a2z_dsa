#include <iostream>

// My Solution
// bool isAnagram(std::string s, std::string t)
// {
//     int n = s.size(), m = t.size();

//     if (n != m)
//     {
//         return false;
//     }

//     int arr1[26] = {0};
//     int arr2[26] = {0};

//     for (int i = 0; i < n; i++)
//     {
//         arr1[s[i] - 'a']++;
//         arr2[t[i] - 'a']++;
//     }

//     for (int i = 0; i < 26; i++)
//     {
//         if (arr1[i] != arr2[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// Striver's Solution
bool isAnagram(std::string s, std::string t)
{
    int n = s.size(), m = t.size();

    if (n != m)
    {
        return false;
    }

    int freq[26] = {0};

    for (int i = 0; i < n; i++)
    {
        freq[s[i] - 'a']++;
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    std::string s = "anagram";
    std::string goal = "nagaram";
    std::cout << "String '" << s << "' is " << (isAnagram(s, goal) ? "" : "not ") << "an anagram of '" << goal << "'." << std::endl;
    return 0;
}

// https://leetcode.com/problems/valid-anagram/submissions/2001537485/