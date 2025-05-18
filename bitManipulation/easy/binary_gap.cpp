#include <iostream>

// Solution 1
// int binaryGap(int n)
// {
//     if ((n & (n - 1)) == 0)
//     {
//         return 0;
//     }

//     std::vector<int> v;
//     int index = 0;
//     while (n > 0)
//     {
//         if (n & 1)
//         {
//             v.push_back(index);
//         }
//         n >>= 1;
//         index++;
//     }

//     int max_gap = 0;
//     int size = v.size();
//     int distance = 0;
//     for (int i = 0; i < size - 1; i++)
//     {
//         distance = v[i + 1] - v[i];
//         if (distance > max_gap)
//         {
//             max_gap = distance;
//         }
//     }
//     return max_gap;
// }

// Solution 2
int binaryGap(int n)
{
    if ((n & (n - 1)) == 0)
    {
        return 0;
    }

    int last_set_bit_index = -1;
    int current_index = 0;
    int max_gap = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            if ((last_set_bit_index != -1) && (current_index - last_set_bit_index) > max_gap)
            {
                max_gap = current_index - last_set_bit_index;
            }
            last_set_bit_index = current_index;
        }
        n >>= 1;
        current_index++;
    }
    return max_gap;
}

int main()
{
    std::cout << "ans: " << binaryGap(15) << std::endl;
    return 0;
}

// https://leetcode.com/problems/binary-gap/description/?envType=problem-list-v2&envId=bit-manipulation