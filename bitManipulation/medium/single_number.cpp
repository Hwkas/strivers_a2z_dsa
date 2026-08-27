#include <iostream>

int singleNumber(std::vector<int> &nums)
{
    int single_number = 0;

    for (const auto &i : nums)
    {
        single_number ^= i;
    }

    return single_number;
}

int main()
{
    std::vector<int> nums = {2, 2, 1};
    std::cout << singleNumber(nums) << std::endl;
    return 0;
}