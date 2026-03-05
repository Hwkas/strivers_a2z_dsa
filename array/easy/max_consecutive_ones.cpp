#include <iostream>

int findMaxConsecutiveOnes(std::vector<int> &nums)
{
    int max = 0, current = 0;

    for (auto i : nums)
    {
        if (i == 1)
        {
            current++;
        }
        else
        {
            max = std::max(max, current);
            current = 0;
        }
    }
    return std::max(max, current);
}

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);

    std::cout << "ans: " << findMaxConsecutiveOnes(v) << std::endl;
    return 0;
}

// https://leetcode.com/problems/max-consecutive-ones/