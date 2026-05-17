#include <iostream>

int maxDepth(std::string s)
{
    int max_depth = 0, current_depth = 0;

    for (const auto &c : s)
    {
        if (c == '(')
        {
            current_depth++;
        }
        else if (c == ')')
        {
            current_depth--;
        }
        max_depth = std::max(max_depth, current_depth);
    }
    return max_depth;
}

int main()
{
    std::string s = "(1+(2*3)+((8)/4))+1";
    std::cout << "Maximum Nesting Depth of the Parentheses is " << maxDepth(s) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/