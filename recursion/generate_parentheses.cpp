#include <iostream>

void generate(std::string curr, std::vector<std::string> &result, int n, int opening_breaces_count, int closing_breaces_count)
{
    if (curr.size() == (n * 2))
    {
        result.push_back(curr);
        return;
    }

    if (opening_breaces_count < n)
    {
        generate(curr + "(", result, n, opening_breaces_count + 1, closing_breaces_count);
    }

    if (closing_breaces_count < opening_breaces_count)
    {
        generate(curr + ")", result, n, opening_breaces_count, closing_breaces_count + 1);
    }
}

std::vector<std::string> generateParenthesis(int n)
{
    std::vector<std::string> result;
    generate("", result, n, 0, 0);
    return result;
}

void print(std::vector<std::string> &arr)
{
    int size = arr.size();

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] " << std::endl;
}

int main()
{
    std::vector<std::string> parenthesis_strings = generateParenthesis(3);
    print(parenthesis_strings);
    return 0;
}

// https://leetcode.com/problems/generate-parentheses/description/