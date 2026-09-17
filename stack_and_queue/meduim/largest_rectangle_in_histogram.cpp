#include <iostream>

// Better Approach
// std::vector<int> findNSE(std::vector<int> &arr)
// {
//     int n = arr.size();
//     std::vector<int> ans(n);
//     std::stack<int> st;

//     for (int i = n - 1; i >= 0; i--)
//     {
//         while (!st.empty() && arr[st.top()] >= arr[i])
//         {
//             st.pop();
//         }

//         ans[i] = !st.empty() ? st.top() : n;
//         st.push(i);
//     }

//     return ans;
// }

// std::vector<int> findPSE(std::vector<int> &arr)
// {
//     int n = arr.size();
//     std::vector<int> ans(n);
//     std::stack<int> st;

//     for (int i = 0; i < n; i++)
//     {
//         while (!st.empty() && arr[st.top()] >= arr[i])
//         {
//             st.pop();
//         }

//         ans[i] = !st.empty() ? st.top() : -1;
//         st.push(i);
//     }

//     return ans;
// }

// int largestRectangleArea(std::vector<int> &heights)
// {
//     std::vector<int> nse = findNSE(heights);
//     std::vector<int> psee = findPSE(heights);
//     int n = heights.size();
//     int max = 0;

//     for (int i = 0; i < n; i++)
//     {
//         int freq = nse[i] - psee[i] - 1;
//         max = std::max(max, (freq * heights[i]));
//     }

//     return max;
// }

// Optimal Approach
int largestRectangleArea(std::vector<int> &heights)
{
    std::stack<int> s;
    int max = 0, n = heights.size();

    for (int i = 0; i < n; i++)
    {
        while ((!s.empty()) && (heights[s.top()] > heights[i]))
        {
            int val = heights[s.top()];

            s.pop();

            int left = s.empty() ? -1 : s.top();

            max = std::max(max, val * (i - left - 1));
        }
        s.push(i);
    }

    while (!s.empty())
    {
        int val = heights[s.top()];

        s.pop();

        int left = s.empty() ? -1 : s.top();

        max = std::max(max, val * (n - left - 1));
    }

    return max;
}

int main()
{
    std::vector<int> heights = {2, 1, 5, 6, 2, 3};
    std::cout << largestRectangleArea(heights) << std::endl;
    return 0;
}

// https://leetcode.com/problems/largest-rectangle-in-histogram/submissions/2144762827/