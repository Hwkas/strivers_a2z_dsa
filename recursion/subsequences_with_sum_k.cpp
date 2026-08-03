#include <iostream>

void findSubsequences(
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
        }
        return;
    }

    // Not Include
    findSubsequences(result, nums, subseq, k, sum, start + 1, end);
    subseq.push_back(nums[start]);
    sum += nums[start];

    // Include
    findSubsequences(result, nums, subseq, k, sum, start + 1, end);
    subseq.pop_back();
    sum -= nums[start]; // This line has no effect on the function.
}

std::vector<std::vector<int>> subsequencesWithSumK(
    std::vector<int> &nums,
    int k)
{
    std::vector<std::vector<int>> result;
    std::vector<int> subseq;

    findSubsequences(result, nums, subseq, k, 0, 0, nums.size());

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
    std::vector<std::vector<int>> result = subsequencesWithSumK(v, 3);
    print(result);
    return 0;
}