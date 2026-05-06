#include <iostream>

int next_valid_stall(const std::vector<int> &sorted_stalls, int low, int x)
{
    int mid = 0, high = (sorted_stalls.size() - 1);
    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (sorted_stalls[mid] == x)
        {
            return mid;
        }

        if (sorted_stalls[mid] > x)
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

bool valid_distance(const std::vector<int> &sorted_stalls, int k, int distance)
{
    int j = 0, n = sorted_stalls.size();
    for (int i = 1; i < k; i++)
    {
        j = next_valid_stall(sorted_stalls, (j + 1), (sorted_stalls[j] + distance));

        if (j == n)
        {
            return false;
        }
    }
    return true;
}

int aggressiveCows(std::vector<int> &stalls, int k)
{
    std::vector<int> sorted_stalls = stalls;
    std::sort(sorted_stalls.begin(), sorted_stalls.end());

    int n = stalls.size();
    int low = 1, mid = 0, high = sorted_stalls[n - 1];

    while (low <= high)
    {
        mid = low + (high - low) / 2;

        if (valid_distance(sorted_stalls, k, mid))
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
    std::vector<int> stalls = {87, 93, 51, 81, 68, 99, 59};
    int k = 4;
    std::cout << "Maximum possible minimum distance is " << aggressiveCows(stalls, k) << "." << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/aggressive-cows_1082559?leftPanelTabValue=PROBLEM