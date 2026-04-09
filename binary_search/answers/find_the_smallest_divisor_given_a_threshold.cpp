#include <iostream>

bool is_valid_divisor(const std::vector<int> &nums, int threshold, int divisor)
{
    int sum = 0;
    for (const auto &i : nums)
    {
        sum += std::ceil((double)i / (double)divisor);
    }
    return (sum <= threshold);
}

int smallestDivisor(std::vector<int> &nums, int threshold)
{
    int low = 1, mid = 0, high = *std::max_element(nums.begin(), nums.end());

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (is_valid_divisor(nums, threshold, mid))
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
    std::vector<int> nums = {44, 22, 33, 11, 1};
    int threshold = 5;
    std::cout << "Smallest Divisor is " << smallestDivisor(nums, threshold) << "." << std::endl;
    return 0;
}

// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/description/