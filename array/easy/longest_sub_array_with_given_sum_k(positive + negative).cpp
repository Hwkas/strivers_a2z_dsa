#include <iostream>

// Optimal Approach
int longestSubarray(std::vector<int> &arr, int k)
{
    std::unordered_map<long long, int> map;
    int size = arr.size(), max_length = 0;
    long long sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (map.find(sum) == map.end())
        {
            map[sum] = i;
        }

        if (sum == k)
        {
            max_length = std::max(max_length, i + 1);
        }
        else if (map.find(sum - k) != map.end())
        {
            max_length = std::max(max_length, i - map[sum - k]);
        }
    }
    return max_length;
}

int main()
{
    std::vector<int> v;
    v.push_back(10);
    v.push_back(5);
    v.push_back(2);
    v.push_back(7);
    v.push_back(1);
    v.push_back(-10);

    std::cout << "ans: " << longestSubarray(v, 15) << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/longest-sub-array-with-sum-k0809/1