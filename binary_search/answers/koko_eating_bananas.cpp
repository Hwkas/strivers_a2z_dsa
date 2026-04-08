#include <iostream>

bool is_valid_speed(std::vector<int> &piles, int speed, int hours)
{
    int n = piles.size();
    long long total_hours = 0;
    for (int pile : piles)
    {
        total_hours += std::ceil((double)pile / (double)speed);
        // // FIX 2: Faster integer-based ceiling division
        // total_hours += (pile + (long long)speed - 1) / speed;
    }
    return (total_hours <= (long long)hours);
}

int minEatingSpeed(std::vector<int> &piles, int h)
{
    int low = 1, mid = 0, high = *std::max_element(piles.begin(), piles.end());

    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (is_valid_speed(piles, mid, h))
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
    std::vector<int> piles = {805306368, 805306368, 805306368};
    int hours = 1000000000;
    std::cout << "The Minimum eating speed should be " << minEatingSpeed(piles, hours) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/koko-eating-bananas/description/