#include <iostream>

int seriesSum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + seriesSum(n - 1);
}

int main()
{
    std::cout << "sum: " << seriesSum(6) << std::endl;
    return 0;
}

// https://www.geeksforgeeks.org/problems/sum-of-series2811/1