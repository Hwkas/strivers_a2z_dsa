#include <iostream>

// Brute Force Approach
// double minimiseMaxDistance(std::vector<int> &arr, int k)
// {
//     int n = arr.size();
//     std::vector<int> distances_list(n - 1, 0);

//     for (int i = 0; i < k; i++)
//     {
//         long double max_distance = -1;
//         int max_distance_index = -1;

//         for (int j = 0; j < (n - 1); j++)
//         {
//             long double current_distance = ((arr[j + 1] - arr[j]) / (long double)(distances_list[j] + 1));
//             if (current_distance > max_distance)
//             {
//                 max_distance = current_distance;
//                 max_distance_index = j;
//             }
//         }
//         distances_list[max_distance_index]++;
//     }

//     long double max_distance = -1;

//     for (int i = 0; i < (n - 1); i++)
//     {
//         max_distance = std::max(max_distance, ((arr[i + 1] - arr[i]) / (long double)(distances_list[i] + 1)));
//     }
//     return max_distance;
// }

// Optimized Solution - Heap
// double minimiseMaxDistance(std::vector<int> &arr, int k)
// {
//     int n = arr.size();
//     std::vector<int> distances_list(n - 1, 0);
//     std::priority_queue<std::pair<long double, int>> pq;

//     for (int i = 0; i < (n - 1); i++)
//     {
//         pq.push({(arr[i + 1] - arr[i]), i});
//     }

//     for (int i = 0; i < k; i++)
//     {
//         int max_distance_index = pq.top().second;
//         distances_list[max_distance_index]++;
//         pq.pop();
//         long double new_distance = ((arr[max_distance_index + 1] - arr[max_distance_index]) / (long double)(distances_list[max_distance_index] + 1));
//         pq.push({new_distance, max_distance_index});
//     }
//     return pq.top().first;
// }

// Optimal Solution

bool is_valid_distance(const std::vector<int> &arr, int k, long double distance)
{
    int n = arr.size(), gap_stations_palces = 0;
    for (int i = 0; i < (n - 1); i++)
    {
        int number_in_between = ((arr[i + 1] - arr[i]) / distance);
        if (((arr[i + 1] - arr[i]) / distance) == (number_in_between * distance))
        {
            number_in_between--;
        }
        gap_stations_palces += number_in_between;
    }
    return (gap_stations_palces <= k);
}

double minimiseMaxDistance(std::vector<int> &arr, int k)
{
    long double low = 0, mid = 0, high = INT_MIN, n = arr.size();

    for (int i = 0; i < (n - 1); i++)
    {
        high = std::max(high, (long double)(arr[i + 1] - arr[i]));
    }

    while ((high - low) > (1e-6))
    {
        mid = low + (high - low) / 2.0;

        if (is_valid_distance(arr, k, mid))
        {
            high = mid;
        }
        else
        {
            low = mid;
        }
    }
    return high;
}

int main()
{
    std::vector<int> arr = {1, 4, 6, 10, 11};
    int k = 1;
    std::cout << "Minimum value of dist is " << minimiseMaxDistance(arr, k) << "." << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/minimise-max-distance_7541449?leftPanelTabValue=SUBMISSION