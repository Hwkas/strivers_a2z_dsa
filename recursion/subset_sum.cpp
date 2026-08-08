#include <iostream>

void generateSubsetSum(std::vector<int> &num, std::vector<int> &result, int sum, int start, int end)
{
    if (start >= end)
    {
        result.push_back(sum);
        return;
    }

    // Not Include
    generateSubsetSum(num, result, sum, start + 1, end);

    // Include
    generateSubsetSum(num, result, (sum + num[start]), start + 1, end);
}

std::vector<int> subsetSum(std::vector<int> &num)
{
    std::vector<int> result;

    generateSubsetSum(num, result, 0, 0, num.size());

    std::sort(result.begin(), result.end());

    return result;
}

void print(std::vector<int> &arr)
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
    std::vector<int> num = {1, 2, 3};
    std::vector<int> result = subsetSum(num);
    print(result);
    return 0;
}

// https://www.naukri.com/code360/problems/subset-sum_3843086