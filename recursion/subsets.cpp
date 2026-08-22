#include <iostream>

void generate(std::vector<std::vector<int>> &power_sets, std::vector<int> &nums, std::vector<int> &v, int start, int end)
{
    if (start == end)
    {
        power_sets.push_back(v);
        return;
    }

    generate(power_sets, nums, v, start + 1, end);
    v.push_back(nums[start]);
    generate(power_sets, nums, v, start + 1, end);
    v.pop_back();
}

std::vector<std::vector<int>> subsets(std::vector<int> &nums)
{
    std::vector<std::vector<int>> power_sets;
    std::vector<int> v = {};

    generate(power_sets, nums, v, 0, nums.size());
    return power_sets;
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
    std::vector<std::vector<int>> power_sets = subsets(v);
    print(power_sets);
    return 0;
}

// https://leetcode.com/problems/subsets/description/