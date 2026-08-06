#include <iostream>

// My Solution
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

    int i = 1;

    while (((start + i) < end) && (candidates[start] == candidates[start + i]))
    {
        i++;
    }

    generateSubsequences(candidates, target, result, seq, (start + i), end);

    if (candidates[start] <= target)
    {
        seq.push_back(candidates[start]);

        generateSubsequences(candidates, (target - candidates[start]), result, seq, (start + 1), end);

        seq.pop_back();
    }
}

std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
{
    std::vector<std::vector<int>> result;
    std::vector<int> seq;
    std::vector<int> candidates_copy = candidates;

    std::sort(candidates_copy.begin(), candidates_copy.end());

    generateSubsequences(candidates_copy, target, result, seq, 0, candidates_copy.size());
    return result;
}

// Striver's Solution
// void findCombination(int ind, int target, std::vector<int> &arr, std::vector<std::vector<int>> &ans, std::vector<int> &ds)
// {
//     // Base case: If the target becomes 0, we found a valid combination
//     if (target == 0)
//     {
//         ans.push_back(ds); // Add the current combination to the result
//         return;
//     }

//     // Loop through the elements starting from index 'ind'
//     for (int i = ind; i < arr.size(); i++)
//     {
//         // Skip duplicates to avoid repeating combinations
//         if (i > ind && arr[i] == arr[i - 1])
//             continue;

//         // If the current element is greater than the remaining target, break the loop
//         if (arr[i] > target)
//             break;

//         // Include the current element in the combination
//         ds.push_back(arr[i]);

//         // Recur with the updated target and next index (i + 1 to avoid repetition)
//         findCombination(i + 1, target - arr[i], arr, ans, ds);

//         // Backtrack by removing the last added element
//         ds.pop_back();
//     }
// }

// std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target)
// {
//     sort(candidates.begin(), candidates.end());      // Sort the candidates to handle duplicates
//     std::vector<std::vector<int>> ans;               // To store the final answer
//     std::vector<int> ds;                             // To store the current combination
//     findCombination(0, target, candidates, ans, ds); // Call the helper function
//     return ans;                                      // Return all valid combinations
// }

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
    std::vector<int> arr = {2, 5, 2, 1, 2};
    std::vector<std::vector<int>> result = combinationSum2(arr, 5);
    print(result);
    return 0;
}

// https://leetcode.com/problems/combination-sum-ii/description/