#include <iostream>
#include <set>

// My Solution
// bool isIsomorphic(std::string s, std::string t)
// {
//     std::unordered_map<char, char> map;
//     std::set<char> st;
//     int n = s.size();

//     for (int i = 0; i < n; i++)
//     {
//         if ((map.find(s[i]) == map.end()) && (st.find(t[i]) == st.end()))
//         {
//             map[s[i]] = t[i];
//             st.insert(t[i]);
//         }
//         else if (map[s[i]] != t[i])
//         {
//             return false;
//         }
//     }
//     return true;
// }

// Striver's Solution
bool isIsomorphic(std::string s, std::string t)
{
    int m1[256] = {0}, m2[256] = {0};
    int n = s.size();

    for (int i = 0; i < n; ++i)
    {
        if (m1[s[i]] != m2[t[i]])
        {
            return false;
        }
        m1[s[i]] = i + 1;
        m2[t[i]] = i + 1;
    }
    return true;
}

int main()
{
    std::string s = "paper"; //"egg";
    std::string t = "title"; //"add";
    std::cout << "Given strings are " << (isIsomorphic(s, t) ? "" : "not ") << "isomorphic." << std::endl;
    return 0;
}

// https://leetcode.com/problems/isomorphic-strings/submissions/