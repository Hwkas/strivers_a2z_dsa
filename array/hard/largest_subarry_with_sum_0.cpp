#include <iostream>

// Brute Force Approach
// int maxLen(std::vector<int> &arr)
// {
//     int size = arr.size(), max_len = 0;

//     for (int i = 0; i < size; i++)
//     {
//         int sum = 0;
//         for (int j = i; j < size; j++)
//         {
//             sum += arr[j];
//             if (sum == 0)
//             {
//                 max_len = std::max(max_len, (j - i + 1));
//             }
//         }
//     }
//     return max_len;
// }

// Optimized Approach
int maxLen(std::vector<int> &arr)
{
    int size = arr.size(), max_len = 0, sum = 0;
    std::unordered_map<int, int> map;

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
        if (sum == 0)
        {
            max_len = i + 1;
        }
        else if (map.find(sum) != map.end())
        {
            max_len = std::max(max_len, (i - map[sum]));
        }
        else
        {
            std::cout << "i: " << i << std::endl;
            map[sum] = i;
        }
    }
    return max_len;
}

int main()
{
    std::vector<int> v = {1, -1, 2, -2};
    // {15, -2, 2, -8, 1, 7, 10, 23};
    std::cout << maxLen(v) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/longest-subset-zero-sum_920321?leftPanelTabValue=SUBMISSION