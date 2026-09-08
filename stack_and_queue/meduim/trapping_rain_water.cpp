#include <iostream>

// My Solution
int trap(std::vector<int> &height)
{
    std::stack<int> s;
    int current_max = 0;
    int water = 0;

    for (const auto &i : height)
    {
        if (i < current_max)
        {
            s.push(i);
        }
        else
        {
            while (!s.empty())
            {
                water += current_max - s.top();
                s.pop();
            }
            current_max = i;
            s.push(i);
        }
    }

    current_max = 0; // right_max

    while (!s.empty())
    {
        current_max = std::max(current_max, s.top());
        water += current_max - s.top();
        s.pop();
    }

    return water;
}

// Striver's Solution
// int trap(std::vector<int> &height)
// {
//     int n = height.size();

//     int left = 0;
//     int right = n - 1;

//     int maxLeft = 0;
//     int maxRight = 0;

//     int totalWater = 0;

//     while (left <= right)
//     {
//         if (height[left] <= height[right])
//         {
//             if (height[left] >= maxLeft)
//             {
//                 maxLeft = height[left];
//             }
//             else
//             {
//                 totalWater += maxLeft - height[left];
//             }
//             left++;
//         }
//         else
//         {
//             if (height[right] >= maxRight)
//             {
//                 maxRight = height[right];
//             }
//             else
//             {
//                 totalWater += maxRight - height[right];
//             }
//             right--;
//         }
//     }

//     return totalWater;
// }

int main()
{
    std::vector<int> height = {2, 0, 2, 1};
    // {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    std::cout << trap(height) << std::endl;
    return 0;
}

// https://leetcode.com/problems/trapping-rain-water/description/