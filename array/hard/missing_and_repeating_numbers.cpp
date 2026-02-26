#include <iostream>

// Brute Force Approach
// std::pair<int, int> missingAndRepeating(std::vector<int> &arr, int n)
// {
//     int missing_number = -1, repeating_number = -1;

//     for (int i = 1; i <= n; i++)
//     {
//         int counter = 0;
//         for (int j = 0; j < n; j++)
//         {
//             if (arr[j] == i)
//             {
//                 counter++;
//             }
//         }
//         if (counter == 0)
//         {
//             missing_number = i;
//         }
//         else if (counter == 2)
//         {
//             repeating_number = i;
//         }
//         else if (missing_number != -1 && repeating_number != -1)
//         {
//             break;
//         }
//     }
//     return {missing_number, repeating_number};
// }

// Optimized
// std::pair<int, int> missingAndRepeating(std::vector<int> &arr, int n)
// {
//     std::vector<int> hash_arr(n + 1, 0);
//     int missing_number = -1, repeating_number = -1;

//     for (int i = 0; i < n; i++)
//     {
//         hash_arr[arr[i]]++;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (hash_arr[i] == 0)
//         {
//             missing_number = i;
//         }
//         else if (hash_arr[i] == 2)
//         {
//             repeating_number = i;
//         }
//         else if (missing_number != -1 && repeating_number != -1)
//         {
//             break;
//         }
//     }

//     return {missing_number, repeating_number};
// }

// Mathematical Solution
// std::pair<int, int> missingAndRepeating(std::vector<int> &arr, int n)
// {
//     long long N = n; // Use long long to prevent overflow in formulas

//     // Sum of first N natural numbers: n(n+1)/2
//     long long sum_n = (N * (N + 1)) / 2;
//     // Sum of squares of first N natural numbers: n(n+1)(2n+1)/6
//     long long sum_n_sq = (N * (N + 1) * (2 * N + 1)) / 6;

//     long long sum_arr = 0;
//     long long sum_arr_sq = 0;

//     for (int i = 0; i < n; i++)
//     {
//         sum_arr += (long long)arr[i];
//         sum_arr_sq += (long long)arr[i] * (long long)arr[i];
//     }

//     // Let x be the repeating number and y be the missing number
//     // eq1: sum_arr - sum_n = x - y
//     long long val1 = sum_arr - sum_n;

//     // eq2: sum_arr_sq - sum_n_sq = x^2 - y^2 = (x - y)(x + y)
//     long long val2 = sum_arr_sq - sum_n_sq;

//     // Find x + y by: (x^2 - y^2) / (x - y)
//     val2 = val2 / val1;

//     // x = ((x + y) + (x - y)) / 2
//     int x = (int)((val1 + val2) / 2);
//     // y = (x + y) - x
//     int y = (int)(val2 - x);

//     // Return {Missing, Repeating} based on your function signature requirement
//     // Usually, problems ask for {Repeating, Missing}, but following your {y, x} return:
//     return {y, x};
// }

// XOR Solution
std::pair<int, int> missingAndRepeating(std::vector<int> &arr, int n)
{
    int _xor = 0;
    for (int i = 0; i < n; i++)
    {
        _xor ^= arr[i] ^ (i + 1);
    }

    int set_bit = _xor & (-_xor);

    int g0 = 0, g1 = 0;

    for (int i = 0; i < n; i++)
    {
        (arr[i] & set_bit) ? (g1 ^= arr[i]) : (g0 ^= arr[i]);
        ((i + 1) & set_bit) ? (g1 ^= (i + 1)) : (g0 ^= (i + 1));
    }

    for (int i = 0; i < n; i++)
        if (arr[i] == g0)
            return {g1, g0};

    return {g0, g1};
}

int main()
{
    std::vector<int> arr = {1, 4, 2, 3, 1};
    int n = 5;
    std::pair<int, int> ans = missingAndRepeating(arr, n);
    std::cout << "Missing Number: " << ans.first << ", Repeating Number: " << ans.second << std::endl;
    return 0;
}

// https://www.naukri.com/code360/problems/missing-and-repeating-numbers_873366