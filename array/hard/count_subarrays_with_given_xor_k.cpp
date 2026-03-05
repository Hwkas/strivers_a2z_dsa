#include <iostream>

// Brute Force Approach
// int subarraysWithXorK(std::vector<int> &nums, int k)
// {
//     int size = nums.size(), count = 0;
//     for (int i = 0; i < size; i++)
//     {
//         int temp_xor = 0;
//         for (int j = i; j < size; j++)
//         {
//             temp_xor ^= nums[j];
//             if (temp_xor == k)
//             {
//                 count++;
//             }
//         }
//     }
//     return count;
// }

// Optimal Approach (My Approach)
// int subarraysWithXorK(std::vector<int> &nums, int k)
// {
//     int size = nums.size(), count = 0, temp_xor = 0;
//     std::unordered_map<int, int> map;

//     for (int i = 0; i < size; i++)
//     {
//         temp_xor ^= nums[i];
//         if (temp_xor == k)
//         {
//             count++;
//         }
//         if (map.find(temp_xor ^ k) != map.end())
//         {
//             count += map[temp_xor ^ k];
//         }
//         map[temp_xor]++;
//     }
//     return count;
// }

// Optimal Approach (Strivers Approach)
int subarraysWithXorK(std::vector<int> &nums, int k)
{
    int size = nums.size(), count = 0, temp_xor = 0;
    std::unordered_map<int, int> map;

    map[temp_xor]++;
    for (int i = 0; i < size; i++)
    {
        temp_xor ^= nums[i];
        count += map[temp_xor ^ k];
        map[temp_xor]++;
    }
    return count;
}

int main()
{
    std::vector<int> v = {4, 2, 2, 6, 4};
    std::cout << subarraysWithXorK(v, 6) << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/count-subarray-with-given-xor/1