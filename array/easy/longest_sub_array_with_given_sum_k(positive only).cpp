#include <iostream>
#include <map>

// Brute Force Approach
// int getLongestSubarray(std::vector<int> &arr, long long k)
// {
//     int size = arr.size(), max_length = 0;
//     long long sum = 0;

//     for (int i = 0; i < size; i++)
//     {
//         for (int j = i; j < size; j++)
//         {
//             sum = 0;
//             for (int l = i; l <= j; l++)
//             {
//                 sum += arr[l];
//             }
//             if (sum == k)
//             {
//                 max_length = std::max((j - i + 1), max_length);
//             }
//         }
//     }
//     return max_length;
// }

// Better Approach
// int getLongestSubarray(std::vector<int> &arr, long long k)
// {
//     std::unordered_map<long long, int> map;
//     int size = arr.size(), max_length = 0;
//     long long sum = 0;

//     for (int i = 0; i < size; i++)
//     {
//         sum += arr[i];
//         if (map.find(sum) == map.end())
//         {
//             map[sum] = i;
//         }

//         if (sum == k)
//         {
//             max_length = std::max(max_length, i + 1);
//         }
//         else if (map.find(sum - k) != map.end())
//         {
//             max_length = std::max(max_length, i - map[sum - k]);
//         }
//     }
//     return max_length;
// }

// Optimal Approach
int getLongestSubarray(std::vector<int> &arr, long long k)
{
    int size = arr.size(), max_length = 0, j = 0;
    long long sum = 0;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        while (sum > k)
        {
            sum -= arr[j++];
        }

        if (sum == k)
        {
            max_length = std::max((i - j + 1), max_length);
        }
    }
    return max_length;
}

int main()
{
    std::vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(5);
    v.push_back(1);
    v.push_back(9);

    std::cout << "ans: " << getLongestSubarray(v, 10) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/longest-subarray-with-sum-k_6682399