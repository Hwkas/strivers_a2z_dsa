#include <iostream>
#include <numeric>

bool is_valid_capacity(const std::vector<int> &weights, int days, int capacity)
{
    int days_count = 1, capacity_sum = 0;
    for (const auto &weight : weights)
    {
        if ((capacity_sum + weight) <= capacity)
        {
            capacity_sum += weight;
        }
        else
        {
            capacity_sum = weight;
            days_count++;
        }
    }
    return (days_count <= days);
}

int shipWithinDays(std::vector<int> &weights, int days)
{
    int low = *std::max_element(weights.begin(), weights.end()), mid = 0, high = std::accumulate(weights.begin(), weights.end(), 0);

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (is_valid_capacity(weights, days, mid))
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
    std::vector<int> weights = {1, 2, 3, 1, 1};
    int days = 4;
    std::cout << "Least Capacity Needed To Ship Packages Within " << days << " Days is " << shipWithinDays(weights, days) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/