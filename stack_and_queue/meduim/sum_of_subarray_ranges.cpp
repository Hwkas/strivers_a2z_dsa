#include <iostream>

std::vector<int> findNGE(std::vector<int> &arr)
{
    int n = arr.size();
    std::vector<int> ans(n);
    std::stack<int> st;

    for (int i = n - 1; i >= 0; i--)
    {
        int currEle = arr[i];

        while (!st.empty() && arr[st.top()] < arr[i])
        {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : n;
        st.push(i);
    }

    return ans;
}

std::vector<int> findPGEE(std::vector<int> &arr)
{
    int n = arr.size();
    std::vector<int> ans(n);
    std::stack<int> st;

    for (int i = 0; i < n; i++)
    {
        int currEle = arr[i];

        while (!st.empty() && arr[st.top()] <= arr[i])
        {
            st.pop();
        }

        ans[i] = !st.empty() ? st.top() : -1;
        st.push(i);
    }

    return ans;
}

long long sumSubarrayMaxs(std::vector<int> &arr)
{
    std::vector<int> nse = findNGE(arr);
    std::vector<int> psee = findPGEE(arr);
    int n = arr.size();
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = left * right * 1LL;

        sum += (freq * arr[i] * 1LL);
    }

    return sum;
}

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

long long sumSubarrayMins(std::vector<int> &arr)
{
    std::vector<int> nse = findNSE(arr);
    std::vector<int> psee = findPSEE(arr);
    int n = arr.size();
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        int left = i - psee[i];
        int right = nse[i] - i;

        long long freq = left * right * 1LL;

        sum += (freq * arr[i] * 1LL);
    }

    return sum;
}

long long subArrayRanges(std::vector<int> &nums)
{
    return (sumSubarrayMaxs(nums) - sumSubarrayMins(nums));
}

int main()
{
    std::vector<int> nums = {4, -2, -3, 4, 1};
    std::cout << subArrayRanges(nums) << std::endl;
    return 0;
}

// https://leetcode.com/problems/sum-of-subarray-ranges/description/