#include <iostream>

void generate(int n, std::string curr, std::vector<std::string> &result)
{
    if (curr.size() == n)
    {
        result.push_back(curr);
        return;
    }

    generate(n, curr + "1", result);

    if (curr.empty() || curr.back() != '0')
    {
        generate(n, curr + "0", result);
    }
}

std::vector<std::string> validStrings(int n)
{
    std::vector<std::string> result;
    generate(n, "", result);
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
    std::vector<std::string> binary_strings = validStrings(3);
    print(binary_strings);
    return 0;
}

// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros/description/