#include <iostream>

// Time - O(n), Space O(n)
// int removeDuplicates(std::vector<int> &nums)
// {
//     int size = nums.size();

//     if (size == 1)
//     {
//         return 1;
//     }

//     int count = 1;
//     std::vector<int> temp;

//     temp.push_back(nums[0]);

//     for (int i = 1; i < size; i++)
//     {
//         if (nums[i - 1] != nums[i])
//         {
//             temp.push_back(nums[i]);
//             count++;
//         }
//     }
//     nums = temp;
//     return count;
// }

int removeDuplicates(std::vector<int> &nums)
{
    int size = nums.size();
    int i = 0;

    for (int j = 1; j < size; j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
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
    v.push_back(8);
    v.push_back(8);
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);

    std::cout << "ans: " << removeDuplicates(v) << std::endl;

    print(v);

    return 0;
}

// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/