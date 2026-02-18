#include <iostream>

// // Brute Force Approach
// std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
// {
//     std::vector<std::vector<int>> merged_intervals;
//     int n = intervals.size();
//     int start = 0, end = 0;

//     std::sort(intervals.begin(), intervals.end());

//     for (int i = 0; i < n; i++)
//     {
//         start = intervals[i][0];
//         end = intervals[i][1];

//         if (!merged_intervals.empty() && end <= merged_intervals.back()[1])
//         {
//             continue;
//         }

//         for (int j = i + 1; j < n; j++)
//         {
//             if (end >= intervals[j][0])
//             {
//                 end = std::max(end, intervals[j][1]);
//             }
//             else
//             {
//                 break;
//             }
//         }

//         merged_intervals.push_back({start, end});
//     }

//     return merged_intervals;
// }

// Optimal Approach
std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
{
    std::vector<std::vector<int>> merged_intervals;
    std::sort(intervals.begin(), intervals.end());

    for (const auto &v : intervals)
    {
        if (merged_intervals.empty() || v[0] > merged_intervals.back()[1])
        {
            merged_intervals.push_back(v);
        }
        else
        {
            merged_intervals.back()[1] = std::max(v[1], merged_intervals.back()[1]);
        }
    }

    // int n = intervals.size();
    // for (int i = 0; i < n; i++)
    // {
    //     if (merged_intervals.empty() || intervals[i][0] > merged_intervals.back()[1])
    //     {
    //         merged_intervals.push_back(intervals[i]);
    //     }
    //     else
    //     {
    //         merged_intervals.back()[1] = std::max(intervals[i][1], merged_intervals.back()[1]);
    //     }
    // }

    return merged_intervals;
}

void print(std::vector<std::vector<int>> &arr)
{

    for (auto temp : arr)
    {
        int size = temp.size();
        std::cout << "[";
        for (int i = 0; i < size; i++)
        {
            std::cout << temp[i] << ((i == (size - 1)) ? "" : ", ");
        }
        std::cout << "] " << std::endl;
    }
}

int main()
{
    std::vector<std::vector<int>> nums = {{2, 3}, {4, 5}, {6, 7}, {8, 9}, {1, 10}};
    std::vector<std::vector<int>> ans = merge(nums);
    print(ans);
    return 0;
}

// https://leetcode.com/problems/merge-intervals/description/