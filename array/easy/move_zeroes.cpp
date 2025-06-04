#include <iostream>

// Time - O(n), Space worst case - O(n)
// void moveZeroes(std::vector<int> &nums)
// {
//     std::vector<int> temp;
//     int size = nums.size(), temp_size = 0;

//     for (int i = 0; i < size; i++)
//     {
//         if (nums[i] != 0)
//         {
//             temp.push_back(nums[i]);
//         }
//     }

//     temp_size = temp.size();

//     for (int j = 0; j < size; j++)
//     {
//         nums[j] = (j < temp_size) ? temp[j] : 0;
//     }
// }

// My Approach Optimal Approach
// void moveZeroes(std::vector<int> &nums)
// {
//     int j = 0, size = nums.size();

//     for (int i = 0; i < size; i++)
//     {
//         if (nums[i] != 0)
//         {
//             while (j < size && nums[j] != 0)
//             {
//                 j++;
//             }

//             if (j < size && j < i)
//             {
//                 std::swap(nums[j], nums[i]);
//             }
//         }
//     }
// }

void moveZeroes(std::vector<int> &nums)
{
    int j = -1, size = nums.size();

    for (int i = 0; i < size; i++)
    {
        if (nums[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
    {
        return;
    }

    for (int i = j + 1; i < size; i++)
    {
        if (nums[i] != 0)
        {
            std::swap(nums[i], nums[j]);
            j++;
        }
    }
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
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(3);
    v.push_back(12);

    moveZeroes(v);
    std::cout << "ans: ";
    print(v);
    return 0;
}

// https://leetcode.com/problems/move-zeroes/description/