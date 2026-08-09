#include <iostream>

// My Solution
void generateValidCombinations(
    int k,
    int n,
    std::vector<std::vector<int>> &result,
    std::vector<int> seq,
    int sum,
    int start)
{
    if ((start > 9))
    {
        if ((seq.size() == k) && (sum == n))
        {
            result.push_back(seq);
        }
        return;
    }

    // Include
    if ((sum + start) <= n)
    {
        seq.push_back(start);
        generateValidCombinations(k, n, result, seq, (sum + start), start + 1);
        seq.pop_back();
    }

    // Not Include
    generateValidCombinations(k, n, result, seq, sum, start + 1);
}

std::vector<std::vector<int>> combinationSum3(int k, int n)
{
    std::vector<std::vector<int>> result;
    std::vector<int> seq;

    generateValidCombinations(k, n, result, seq, 0, 1);

    return result;
}

// Striver's Solution
// void func(int sum, int last, std::vector<int> &nums, int k, std::vector<std::vector<int>> &ans)
// {
//     if (sum == 0 && nums.size() == k)
//     {
//         ans.push_back(nums);
//         return;
//     }

//     if (sum <= 0 || nums.size() > k)
//         return;

//     for (int i = last; i <= 9; i++)
//     {
//         if (i <= sum)
//         {
//             nums.push_back(i);

//             func(sum - i, i + 1, nums, k, ans);

//             nums.pop_back();
//         }
//         else
//         {
//             break;
//         }
//     }
// }

// std::vector<std::vector<int>> combinationSum3(int k, int n)
// {
//     std::vector<std::vector<int>> ans;
//     std::vector<int> nums;
//     func(n, 1, nums, k, ans);
//     return ans;
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
    std::vector<std::vector<int>> result = combinationSum3(3, 9);
    print(result);
    return 0;
}

// https://leetcode.com/problems/combination-sum-iii/submissions/2100000819/