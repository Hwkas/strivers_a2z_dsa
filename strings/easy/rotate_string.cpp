#include <iostream>

// Brute Force Approach
// bool rotateString(std::string s, std::string goal)
// {
//     int n = s.size(), m = goal.size();

//     if (n != m)
//     {
//         return false;
//     }

//     std::string rotated_string;

//     for (int i = 0; i < n; i++)
//     {
//         rotated_string = s.substr(i + 1, n) + s.substr(0, i + 1);

//         if (rotated_string == goal)
//         {
//             return true;
//         }
//     }
//     return false;
// }

// Optimal Approach
bool rotateString(std::string s, std::string goal)
{
    if (s.size() != goal.size())
    {
        return false;
    }

    std::string doubledS = s + s;
    return doubledS.find(goal) != std::string::npos;
}

int main()
{
    std::string s = "abcde";
    std::string goal = "abce";
    std::cout << "String '" << s << "' can " << (rotateString(s, goal) ? "" : "not ") << "becomme '" << goal << "' after rotation." << std::endl;
    return 0;
}

// https://leetcode.com/problems/rotate-string/submissions/2001520639/