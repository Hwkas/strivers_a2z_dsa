#include <iostream>

int romanToInt(std::string s)
{
    std::unordered_map<char, int> roman_int_map = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int int_number = 0, n = s.size();
    char last_char = '\0';

    for (int i = (n - 1); i >= 0; i--)
    {
        if ((last_char == '\0') || roman_int_map[last_char] <= roman_int_map[s[i]])
        {
            int_number += roman_int_map[s[i]];
        }
        else
        {
            int_number -= roman_int_map[s[i]];
        }
        last_char = s[i];
    }
    return int_number;
}

int main()
{
    std::string s = "III";
    std::cout << "Roman to Integer is " << romanToInt(s) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/roman-to-integer/submissions/2007334360/