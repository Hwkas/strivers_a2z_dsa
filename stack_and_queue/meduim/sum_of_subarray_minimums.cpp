#include <iostream>

// Brute Force
// int sumSubarrayMins(std::vector<int> &arr)
// {
//     int min_sum = 0;

//     for (int i = 0; i < arr.size(); i++)
//     {
//         int current_min = arr[i];

//         for (int j = i; j < arr.size(); j++)
//         {
//             current_min = std::min(current_min, arr[j]);
//             min_sum += current_min;
//         }
//     }

//     return min_sum;
// }

std::vector<int> findNSE(std::vector<int> &arr)
{
    int n = arr.size();
    std::vector<int> ans(n);
    std::stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        int currEle = arr[i];

        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }

    return ans;
}

std::vector<int> findPSEE(std::vector<int> &arr)
{
    int n = arr.size();
    std::vector<int> ans(n);
    std::stack<int> st;

    for (int i = 0; i < n; i++)
    {
        int currEle = arr[i];

        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }

    return ans;
}

int sumSubarrayMins(std::vector<int> &arr)
{
    std::vector<int> nse = findNSE(arr);
    std::vector<int> psee = findPSEE(arr);
    int n = arr.size();
    int mod = 1e9 + 7;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = left * right * 1LL;

        int val = (freq * arr[i] * 1LL) % mod;

        sum = (sum + val) % mod;
    }

    return sum;
}

int main()
{
    std::vector<int> arr = {3, 1, 2, 4};
    std::cout << sumSubarrayMins(arr) << std::endl;
    return 0;
}