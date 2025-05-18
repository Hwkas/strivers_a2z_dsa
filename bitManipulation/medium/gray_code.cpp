#include <iostream>

std::vector<int> grayCode(int n)
{
    std::vector<int> v;
    v.push_back(0);

    n = (1 << n);
    for (int i = 1; i < n; i <<= 1)
    {
        int size = v.size();
        for (int j = (size - 1); j >= 0; j--)
        {
            v.push_back(v[j] | i);
        }
    }
    return v;
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
    int n = 3;

    std::vector<int> ans = grayCode(n);

    print(ans);
    return 0;
}

// https://leetcode.com/problems/gray-code/submissions/1486486857/?envType=problem-list-v2&envId=bit-manipulation