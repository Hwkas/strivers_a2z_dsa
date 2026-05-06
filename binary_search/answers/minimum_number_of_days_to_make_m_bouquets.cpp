#include <iostream>

bool is_valid_days(const std::vector<int> &bloomDay, int m, int k, int days)
{
    int bouquets_formed = 0, adjacent_flowers = 0;

    for (auto &i : bloomDay)
    {
        if (days >= i)
        {
            adjacent_flowers++;
        }
        else
        {
            adjacent_flowers = 0;
        }

        if (adjacent_flowers == k)
        {
            bouquets_formed++;
            adjacent_flowers = 0;
        }
    }
    return (bouquets_formed >= m);
}

int minDays(std::vector<int> &bloomDay, int m, int k)
{
    long long total_flowers = (long long)m * k;

    if (total_flowers > bloomDay.size())
    {
        return -1;
    }

    int low = 1, mid = 0, high = *std::max_element(bloomDay.begin(), bloomDay.end());

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (is_valid_days(bloomDay, m, k, mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    std::vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;
    std::cout << "Minimum Number of Days to Make " << m << " Bouquets is " << minDays(bloomDay, m, k) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/description/