#include <iostream>

// My Solution
// std::string longestCommonPrefix(std::vector<std::string> &strs)
// {
//     int n = strs.size();

//     if (n == 0)
//     {
//         return "";
//     }
//     if (n == 1)
//     {
//         return strs[0];
//     }

//     int prefix_size = strs[0].size();

//     for (int i = 1; i < n; i++)
//     {
//         int j = 0, m = strs[i].size();
//         while ((j < m) && (j < prefix_size) && (strs[i][j] == strs[0][j]))
//         {
//             j++;
//         }

//         if (j == 0)
//         {
//             return "";
//         }
//         prefix_size = j;

//         strs[i].substr(0, (j));
//     }
//     return strs[0].substr(0, prefix_size);
// }

// Striver's Solution
std::string longestCommonPrefix(std::vector<std::string> &strs)
{
    int n = strs.size();

    if (n == 0)
    {
        return "";
    }
    if (n == 1)
    {
        return strs[0];
    }

    std::sort(strs.begin(), strs.end());

    int j = 0;

    while ((j < strs[0].size()) && (strs[0][j]) == strs[n - 1][j])
    {
        j++;
    }
    return strs[0].substr(0, j);
};

int main()
{
    std::vector<std::string> strs = {"ab", "b"};
    // {"flower", "flow", "flight"};
    // {"ab", "a"};
    std::cout << "Longest Common Prefix is " << longestCommonPrefix(strs) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/longest-common-prefix/submissions/1999516194/