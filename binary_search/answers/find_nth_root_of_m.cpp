#include <iostream>

int NthRoot(int n, int m)
{
    int low = 0, high = m;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        double temp = mid;
        for (int i = 1; i < n; i++)
        {
            temp *= mid;
        }

        if (temp == m)
        {
            return mid;
        }

        if (temp < m)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}

int main()
{
    int n = 9, m = 1953125;
    std::cout << n << "th root of " << m << " is: " << NthRoot(n, m) << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/nth-root-of-m_1062679?leftPanelTabValue=PROBLEM