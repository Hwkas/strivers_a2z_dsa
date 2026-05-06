#include <iostream>

int mySqrt(int x)
{
    int low = 0, high = x;
    long long mid = 0;

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if ((mid * mid) <= x)
        {

            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int x = 30;
    std::cout << "Square root of " << x << " is: " << mySqrt(x) << std::endl;
    return 0;
}

// https://leetcode.com/problems/sqrtx/