#include <iostream>

// Brute Force Approach
// int secondLargestElement(std::vector<int> &nums)
// {
//     int size = nums.size();
//     if (size == 1)
//     {
//         return -1;
//     }

//     std::sort(nums.begin(), nums.end());

//     for (int i = size - 1; i > 0; i--)
//     {
//         if (nums[i] != nums[i - 1])
//         {
//             return nums[i - 1];
//         }
//     }
//     return -1;
// }

// Better Approach
// int secondLargestElement(std::vector<int> &nums)
// {
//     int size = nums.size();
//     if (size == 1)
//     {
//         return -1;
//     }

//     int largest = INT_MIN;
//     int second_largest = INT_MIN;

//     for (int i : nums)
//     {
//         if (i > largest)
//         {
//             largest = i;
//         }
//     }

//     for (int i : nums)
//     {
//         if (i > second_largest and i != largest)
//         {
//             second_largest = i;
//         }
//     }
//     return (second_largest != INT_MIN) ? second_largest : -1;
// }

// Optimal Approach
int secondLargestElement(std::vector<int> &nums)
{
    int size = nums.size();
    if (size == 1)
    {
        return -1;
    }

    int largest = INT_MIN;
    int second_largest = INT_MIN;

    for (int i : nums)
    {
        if (i > largest)
        {
            second_largest = largest;
            largest = i;
        }
        else if (i > second_largest && i != largest)
        {
            second_largest = i;
        }
    }
    return (second_largest != INT_MIN) ? second_largest : -1;
}

int main()
{
    std::vector<int> v;
    v.push_back(8);
    v.push_back(8);
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);

    std::cout << "ans: " << secondLargestElement(v) << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/second-largest3735/1