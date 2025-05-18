#include <iostream>

std::vector<std::vector<int> > subsets(std::vector<int> &nums)
{
    std::vector<std::vector<int> > ans;
    int n = (1 << nums.size());

    for (int i = 0; i < n; i++)
    {
        std::vector<int> temp;
        int j = i, k = 0;
        while (j > 0)
        {
            if (j & 1)
            {
                temp.push_back(nums[k]);
            }
            k++;
            j >>= 1;
        }
        ans.push_back(temp);
    }
    return ans;
}

void print(std::vector<std::vector<int> > v)
{
    std::cout << "[";
    int n = v.size();
    for (int i = 0; i < n; i++)
    {
        std::cout << "[";
        int m = v[i].size();
        for (int j = 0; j < m; j++)
        {
            std::cout << v[i][j] << ((j != (m - 1)) ? ", " : "");
        }
        std::cout << "]" << ((i != (n - 1)) ? ", " : "");
    }
    std::cout << "]" << std::endl;
}

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(2);

    std::vector<std::vector<int> > ans = subsets(v);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/subsets/description/?envType=problem-list-v2&envId=bit-manipulation