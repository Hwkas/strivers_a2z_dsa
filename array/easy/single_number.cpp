#include <iostream>

int singleNumber(std::vector<int> &nums)
{
    int single_numer = 0;
    for (auto i : nums)
    {
        single_numer ^= i;
    }
    return single_numer;
}

int main()
{
    std::vector<int> v;
    v.push_back(2);
    v.push_back(2);
    v.push_back(1);

    std::cout << "ans: " << singleNumber(v) << std::endl;
    return 0;
}

// https://leetcode.com/problems/single-number/