#include <iostream>

bool findSubsequence(
    std::vector<std::vector<int>> &result,
    std::vector<int> &nums,
    std::vector<int> &subseq,
    int k,
    int sum,
    int start,
    int end)
{
    if (start >= end)
    {
        if (sum == k)
        {
            result.push_back(subseq);
            return true;
        }
        return false;
    }

    // Not Include
    if (findSubsequence(result, nums, subseq, k, sum, start + 1, end))
    {
        return true;
    }
    subseq.push_back(nums[start]);
    sum += nums[start];

    // Include
    if (findSubsequence(result, nums, subseq, k, sum, start + 1, end))
    {
        return true;
    }
    subseq.pop_back();
    sum -= nums[start]; // This line has no effect on the function.

    return false;
}

std::vector<std::vector<int>> AnySubsequenceWithSumK(
    std::vector<int> &nums,
    int k)
{
    std::vector<std::vector<int>> result;
    std::vector<int> subseq;

    findSubsequence(result, nums, subseq, k, 0, 0, nums.size());

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
    std::vector<int> v = {1, 2, 3};
    std::vector<std::vector<int>> result = AnySubsequenceWithSumK(v, 3);
    print(result);
    return 0;
}