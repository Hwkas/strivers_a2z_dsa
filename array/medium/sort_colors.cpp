#include <iostream>

// void sortColors(std::vector<int> &nums)
// {
//     int zerores_count = 0, ones_count = 0;

//     for (auto i : nums)
//     {
//         if (i == 0)
//         {
//             zerores_count++;
//         }
//         else if (i == 1)
//         {
//             ones_count++;
//         }
//     }

//     for (auto &i : nums)
//     {
//         if (zerores_count-- > 0)
//         {
//             i = 0;
//         }
//         else if (ones_count-- > 0)
//         {
//             i = 1;
//         }
//         else
//         {
//             i = 2;
//         }
//     }
// }

void sortColors(std::vector<int> &nums)
{
    /*
              l-1    m                 h    n-1
        [0, 0, 1, 1, 2, 1, 1, 2, 0, 1, 2, 2, 2]
            l                      h-1

        Step-by-step execution of the Dutch National Flag Algorithm:
        Starting with the unsorted array [0, 0, 1, 1, 2, 1, 1, 2, 0, 1, 2, 2, 2],
        the pointers l (low), m (mid), and h (high) work together to sort the array into three partitions:

        - The partition 0 -> (l-1) holds the 0s,
        - The partition l -> (m-1) contains the 1s,
        - The partition (m-1) -> (h-1) contains the 0s, 1s & 2s.
        - The partition (h-1) -> (n-1) contains the 2s.
        - At this stage of the algorithm:

        l points to the next position to place a 0,
        m is at the current element under examination,
        h points to the next position to place a 2.
        The algorithm processes the array by swapping elements and adjusting the pointers,
        gradually segregating the 0s, 1s, and 2s into their respective partitions.
    */
    int size = nums.size();
    int low = 0, mid = 0, high = size - 1;

    while (mid <= high)
    {
        if (nums[mid] == 0)
        {
            std::swap(nums[low++], nums[mid++]);
        }
        else if (nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            std::swap(nums[high--], nums[mid]);
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
    v.push_back(2);
    v.push_back(0);
    v.push_back(2);
    v.push_back(1);
    v.push_back(1);
    v.push_back(0);

    sortColors(v);
    std::cout << "ans: ";
    print(v);
    return 0;
}

// https://leetcode.com/problems/sort-colors/