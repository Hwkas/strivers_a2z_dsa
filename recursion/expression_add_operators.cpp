#include <iostream>
#include <unordered_set>

/*
DFS(start=0, val=0, last=0, expr="")
 ├── Take "1" (i=0) -> Start of expression
 │    └── DFS(start=1, val=1, last=1, expr="1")
 │         ├── + "2" (i=1)
 │         │    └── DFS(start=2, val=3, last=2, expr="1+2")
 │         │         ├── + "0" (i=2)
 │         │         │    └── DFS(start=3, val=3, last=0, expr="1+2+0")
 │         │         │         └── + "3" (i=3) -> val=6 == target! ADD "1+2+0+3"
 │         │         │         └── - "3" (i=3) -> val=0
 │         │         │         └── * "3" (i=3) -> val=3
 │         │         ├── - "0" (i=2)
 │         │         │    └── DFS(start=3, val=3, last=0, expr="1+2-0")
 │         │         │         └── ... (evaluates with '3')
 │         │         ├── * "0" (i=2)
 │         │         │    └── DFS(start=3, val=1, last=0, expr="1+2*0")
 │         │         │         └── ...
 │         │         └── + "03" -> SKIPPED (leading zero rule: i > start and num[start] == '0')
 │         │
 │         ├── - "2" (i=1)
 │         │    └── DFS(start=2, val=-1, last=-2, expr="1-2")
 │         │         └── ...
 │         │
 │         └── * "2" (i=1)
 │              └── DFS(start=2, val=2, last=2, expr="1*2")
 │                   └── ...
 │
 ├── Take "12" (i=1)
 │    └── DFS(start=2, val=12, last=12, expr="12")
 │         └── ...
 │
 ├── Take "120" (i=2)
 │    └── DFS(start=3, val=120, last=120, expr="120")
 │         └── ...
 │
 └── Take "1203" (i=3)
      └── DFS(start=4, val=1203, last=1203, expr="1203")
           └── (start == num.size(), val=1203 != 6, returns)
*/

void dfs(
    std::string &num,
    int target,
    int start,
    long long current_value,
    long long last_operand,
    std::string expression,
    std::vector<std::string> &result)
{
    if (start == num.size())
    {
        if (current_value == target)
        {
            result.push_back(expression);
        }
        return;
    }

    // Loop through all substrings starting from 'start' index
    for (int i = start; i < num.size(); i++)
    {
        // Skip leading zeros in numbers
        if (i > start && num[start] == '0')
        {
            return;
        }
        // Get the current number
        std::string current_num = num.substr(start, i - start + 1);
        long long current_num_val = stoll(current_num);

        // If we are at the first number, just start the expression
        if (start == 0)
        {
            dfs(
                num,
                target,
                i + 1,
                current_num_val,
                current_num_val,
                current_num,
                result);
        }
        else
        {
            // Add the current number with '+'
            dfs(
                num,
                target,
                i + 1,
                current_value + current_num_val,
                current_num_val,
                expression + "+" + current_num,
                result);

            // Add the current number with '-'
            dfs(
                num,
                target,
                i + 1,
                current_value - current_num_val,
                -current_num_val,
                expression + "-" + current_num,
                result);

            // Add the current number with '*'
            dfs(
                num,
                target,
                i + 1,
                current_value - last_operand + last_operand * current_num_val,
                last_operand * current_num_val,
                expression + "*" + current_num,
                result);
        }
    }
}

std::vector<std::string> addOperators(std::string num, int target)
{
    std::vector<std::string> result;

    dfs(num, target, 0, 0, 0, "", result);
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
    std::string num = "123";
    std::vector<std::string> result = addOperators(num, 6);

    print(result);

    return 0;
}

// https://leetcode.com/problems/expression-add-operators/description/