#include <iostream>

// Solution O(n logn)
// std::vector<int> countBits(int n)
// {
//     std::vector<int> ans;
//     for (int i = 0; i <= n; i++)
//     {
//         int count = 0;
//         int temp = i;
//         while (temp > 0)
//         {
//             if (temp & 1)
//             {
//                 count++;
//             }
//             temp >>= 1;
//         }
//         ans.push_back(count);
//     }
//     return ans;
// }

// Solution O(n)
std::vector<int> countBits(int n)
{
    std::vector<int> ans;
    ans.push_back(0);
    int most_significant_bit = 1;
    for (int i = 1; i <= n; i++)
    {
        if (i == most_significant_bit << 1)
        {
            most_significant_bit <<= 1;
        }
        ans.push_back(1 + ans[i - most_significant_bit]);
    }
    return ans;
}

void print(std::vector<int> v)
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
    int n = 8;
    std::vector<int> v;
    v = countBits(n);
    std::cout << "Ans: ";
    print(v);
    return 0;
}

// https://leetcode.com/problems/counting-bits/description/?envType=problem-list-v2&envId=bit-manipulation&difficulty=EASY