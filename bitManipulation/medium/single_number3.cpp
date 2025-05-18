#include <iostream>

// Solution (Concept of Bucket)
std::vector<int> singleNumber(std::vector<int> &nums)
{
    std::vector<int> ans(2);
    int n = nums.size(), xor_of_nums = 0;
    for (int i = 0; i < n; i++)
    {
        xor_of_nums ^= nums[i];
    }

    long right_most_set_bit = ((xor_of_nums & (long) xor_of_nums - 1) ^ xor_of_nums); // (xor_of_nums & -xor_of_nums)

    for (int i = 0; i < n; i++)
    {
        if ((nums[i] & right_most_set_bit) == right_most_set_bit)
        {

            ans[0] ^= nums[i]; // bucket with set bit
        }
        else
        {
            ans[1] ^= nums[i]; // bucket without set bit
        }
    }
    return ans;
}

void print(std::vector<int> v)
{
    std::cout << "[";
    int n = v.size();
    for (int i = 0; i < n; i++)
    {

        std::cout << v[i] << ((i != (n - 1)) ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(1);
    v.push_back(3);
    v.push_back(2);
    v.push_back(5);

    std::vector<int> ans = singleNumber(v);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/single-number-iii/description/?envType=problem-list-v2&envId=bit-manipulation