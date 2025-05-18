#include <iostream>

// solution 1
// void generate_set_bits_n_no_map(std::vector<int> &arr, std::unordered_map<int, std::vector<int> > &map)
// {
//     int size = arr.size();
//     int temp = 0, no_of_set_bits = 0;

//     for (int i = 0; i < size; i++)
//     {
//         temp = arr[i];
//         no_of_set_bits = 0;
//         while (temp > 0)
//         {
//             if (temp & 1)
//             {
//                 no_of_set_bits++;
//             }
//             temp >>= 1;
//         }
//         map[no_of_set_bits].push_back(arr[i]);
//     }
// }

// std::vector<int> sortByBits(std::vector<int> &arr)
// {
//     std::unordered_map<int, std::vector<int> > map;

//     generate_set_bits_n_no_map(arr, map);

//     std::vector<int> sorted_arr;
//     int size = 0;
//     for (int i = 0; i < 32; i++)
//     {
//         size = map[i].size();
//         std::sort(map[i].begin(), map[i].end());
//         for (int j = 0; j < size; j++)
//         {
//             sorted_arr.push_back(map[i][j]);
//         }
//     }
//     return sorted_arr;
// }

// Solution 2 time complexity O(NLogN)
// static int noOfSetBits(int n)
// {
//     int count = 0;
//     while (n > 0)
//     {
//         if (n & 1)
//         {
//             count++;
//         }
//         n >>= 1;
//     }
//     return count;
// }

// static bool compare(int a, int b)
// {
//     if (noOfSetBits(a) == noOfSetBits(b))
//     {
//         return a < b;
//     }
//     return noOfSetBits(a) < noOfSetBits(b);
// }

// std::vector<int> sortByBits(std::vector<int> &arr)
// {
//     std::sort(arr.begin(), arr.end(), compare);
//     return arr;
// }

// Solution 3
int noOfSetBits(int n)
{
    int count = 0;
    while (n > 0)
    {
        if (n & 1)
        {
            count++;
        }
        n >>= 1;
    }
    return count;
}

std::vector<int> sortByBits(std::vector<int> &arr)
{
    int constant_no = 100000;
    int size = arr.size();
    for (int i = 0; i < size; i++)
    {
        arr[i] += noOfSetBits(arr[i]) * constant_no;
    }

    std::sort(arr.begin(), arr.end());

    for (int i = 0; i < size; i++)
    {
        arr[i] %= constant_no;
    }
    return arr;
}

void print(std::vector<int> v)
{
    std::cout << "[";
    int n = v.size();
    for (int i = 0; i < n - 1; i++)
    {
        std::cout << v[i] << ", ";
    }
    std::cout << v[n - 1] << "]" << std::endl;
}

int main()
{
    std::vector<int> arr;
    // arr.push_back(0);
    // arr.push_back(1);
    // arr.push_back(2);
    // arr.push_back(3);
    // arr.push_back(4);
    // arr.push_back(5);
    // arr.push_back(6);
    // arr.push_back(7);
    // arr.push_back(8);

    arr.push_back(1024);
    arr.push_back(512);
    arr.push_back(256);
    arr.push_back(128);
    arr.push_back(64);
    arr.push_back(32);
    arr.push_back(16);
    arr.push_back(8);
    arr.push_back(4);
    arr.push_back(2);
    arr.push_back(1);

    std::vector<int> sorted_arr = sortByBits(arr);
    std::cout << "ans: ";
    print(sorted_arr);
    return 0;
}

// https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/submissions/?envType=problem-list-v2&envId=bit-manipulation