#include <iostream>

// My Solution - Original
// void generateCombinations(
//     std::string &digits,
//     std::vector<std::string> &result,
//     std::string &seq,
//     int start,
//     int end)
// {
//     if (start >= end)
//     {
//         result.push_back(seq);
//         return;
//     }

//     char start_char = 'a' + (((digits[start] - '0') - 2) * 3) + ((digits[start] > '7') ? 1 : 0);
//     char end_char = (start_char + 3) + +(((digits[start] == '7') || (digits[start] == '9')) ? 1 : 0);

//     for (; start_char < end_char; start_char++)
//     {
//         seq += start_char;
//         generateCombinations(digits, result, seq, (start + 1), end);
//         seq.pop_back();
//     }
// }

// std::vector<std::string> letterCombinations(std::string digits)
// {
//     std::vector<std::string> result;
//     std::string seq;

//     generateCombinations(digits, result, seq, 0, digits.size());

//     return result;
// }

void generateCombinations(
    std::string &digits,
    const std::vector<std::string> &keypad,
    std::vector<std::string> &result,
    std::string &seq,
    int start,
    int end)
{
    if (start >= end)
    {
        result.push_back(seq);
        return;
    }

    for (const auto &i : keypad[digits[start] - '2'])
    {
        seq += i;
        generateCombinations(digits, keypad, result, seq, (start + 1), end);
        seq.pop_back();
    }
}

std::vector<std::string> letterCombinations(std::string digits)
{
    std::vector<std::string> result;
    std::string seq;
    std::vector<std::string> keypad = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    generateCombinations(digits, keypad, result, seq, 0, digits.size());

    return result;
}

void print(std::vector<std::string> &arr)
{
    for (auto temp : arr)
    {
        int size = temp.size();
        std::cout << "[";
        for (int i = 0; i < size; i++)
        {
            std::cout << temp[i] << ((i == (size - 1)) ? "" : ", ");
        }
        std::cout << "] " << std::endl;
    }
}

int main()
{
    std::vector<std::string> result = letterCombinations("9");
    print(result);
    return 0;
}

// https://leetcode.com/problems/letter-combinations-of-a-phone-number/