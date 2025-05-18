#include <iostream>

int main()
{
    std::vector<int> nums;
    nums.push_back(4);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(2);
    int temp = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++)
    {
        temp ^= nums[i];
    }
    std::cout << "Unique number is: " << temp << std::endl;
    return 0;
}

// https://leetcode.com/problems/single-number/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY