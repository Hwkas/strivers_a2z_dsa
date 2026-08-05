#include <iostream>

void generateSubsequences(
    std::vector<int> &candidates,
    int target,
    std::vector<std::vector<int>> &result,
    std::vector<int> &seq,
    int start,
    int end)
{
    if ((start >= end))
    {
        if (target == 0)
        {
            result.push_back(seq);
        }
        return;
    }

    generateSubsequences(candidates, target, result, seq, start + 1, end);

    if (candidates[start] <= target)
    {
        seq.push_back(candidates[start]);

        generateSubsequences(candidates, (target - candidates[start]), result, seq, start, end);

        seq.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target)
{
    std::vector<std::vector<int>> result;
    std::vector<int> seq;
    generateSubsequences(candidates, target, result, seq, 0, candidates.size());
    return result;
}

void print(std::vector<std::vector<int>> &arr)
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
    std::vector<int> arr = {2, 3, 6, 7};
    std::vector<std::vector<int>> result = combinationSum(arr, 7);
    print(result);
    return 0;
}

// https://leetcode.com/problems/combination-sum/description/