#include <iostream>

// My Solution
// std::string removeOuterParentheses(std::string s)
// {
//     std::string update_string;
//     int open_parentheses_count = 0;

//     for (const auto &i : s)
//     {
//         if (i == '(')
//         {
//             open_parentheses_count++;

//             if (open_parentheses_count != 1)
//             {
//                 update_string += '(';
//             }
//         }
//         else
//         {
//             open_parentheses_count--;

//             if (open_parentheses_count != 0)
//             {
//                 update_string += ')';
//             }
//         }
//     }
//     return update_string;
// }

// Better Code
std::string removeOuterParentheses(std::string s)
{
    std::string update_string;
    int open_parentheses_count = 0;

    for (const auto &i : s)
    {
        if (i == ')')
        {
            open_parentheses_count--;
        }
        if (open_parentheses_count != 0)
        {
            update_string += i;
        }
        if (i == '(')
        {
            open_parentheses_count++;
        }
    }
    return update_string;
}

int main()
{
    std::string s = "(()())(())";
    std::cout << "Updated String is " << removeOuterParentheses(s) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/remove-outermost-parentheses/submissions/1997609864/