#include <iostream>

std::vector<bool> prefixesDivBy5(std::vector<int> &nums)
{
    std::vector<bool> ans;
    int temp = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++)
    {
        temp = ((temp << 1) | nums[i]) % 5;
        // temp <<= 1;
        // temp |= nums[i];
        ans.push_back((temp == 0) ? true : false);
    }
    return ans;
}

void print(std::vector<bool> v)
{
    std::cout << "[";
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << v[i] << ", ";
    }
    std::cout << v[n - 1] << "]" << std::endl;
}

int main()
{
    std::vector<bool> ans;
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(1);
    ans = prefixesDivBy5(nums);
    std::cout << "ans: ";
    print(ans);
    return 0;
}

// https://leetcode.com/problems/binary-prefix-divisible-by-5/description/?envType=problem-list-v2&envId=bit-manipulation