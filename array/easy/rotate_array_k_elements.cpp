#include <iostream>
#include <map>

// Brute Force Approach
// void rotate(std::vector<int> &nums, int k)
// {
//     int size = nums.size();
//     k %= size;

//     for (int i = 0; i < k; i++)
//     {
//         for (int j = size - 1; j > 0; j--)
//         {
//             std::swap(nums[j], nums[j - 1]);
//         }
//     }
// }

// Better Approach
// void rotate(std::vector<int> &nums, int k)
// {
//     int size = nums.size();
//     k %= size;
//     int shift_index;
//     int element;

//     std::unordered_map<int, int> map;

//     for (int i = 0; i < size; i++)
//     {
//         shift_index = (i + k) % size;
//         element = (map.find(i) == map.end()) ? nums[i] : map[i];
//         map[shift_index] = nums[shift_index];
//         nums[shift_index] = element;
//     }
// }

// Optimal Approach (Recursion)
// void solve(std::vector<int> &nums, int k, int i, int size)
// {
//     if (i == size)
//     {
//         return;
//     }

//     int element = nums[i];
//     solve(nums, k, i + 1, size);

//     int shift_index = (i + k) % size;
//     nums[shift_index] = element;
// }

// void rotate(std::vector<int> &nums, int k)
// {
//     solve(nums, k, 0, nums.size());
// }

// Optimal Approach (Reversal Algorithm)
void reverse(std::vector<int> &nums, int start, int end)
{
    while (start <= end)
    {
        std::swap(nums[start++], nums[end--]);
    }
}

void rotate(std::vector<int> &nums, int k)
{
    int size = nums.size();
    k %= size;

    reverse(nums, 0, size - k - 1);
    reverse(nums, size - k, size - 1);
    reverse(nums, 0, size - 1);
}

void print(std::vector<int> &arr)
{
    int size = arr.size();

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] " << std::endl;
}

int main()
{
    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);

    rotate(v, 5);
    std::cout << "ans: ";
    print(v);
    return 0;
}

// https://leetcode.com/problems/rotate-array/description/