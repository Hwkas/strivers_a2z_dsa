#include <iostream>

// Brute Force Approach
// std::vector<int> minAnd2ndMin(std::vector<int> &arr)
// {
//     int size = arr.size();
//     if (size <= 1)
//     {
//         return {-1};
//     }

//     std::sort(arr.begin(), arr.end());

//     int temp = arr[0];

//     for (int i : arr)
//     {
//         if (temp != i)
//         {
//             return {temp, i};
//         }
//     }
//     return {-1};
// }

// Better Approach
// std::vector<int> minAnd2ndMin(std::vector<int> &arr)
// {
//     int size = arr.size();
//     if (size <= 1)
//     {
//         return {-1};
//     }

//     int smallest = INT_MAX;
//     int second_smallest = INT_MAX;

//     for (int i : arr)
//     {
//         if (i < smallest)
//         {
//             smallest = i;
//         }
//     }

//     for (int i : arr)
//     {
//         if (i < second_smallest & i != smallest)
//         {
//             second_smallest = i;
//         }
//     }
//     if (second_smallest == INT_MAX)
//     {
//         return {-1};
//     }
//     return {smallest, (second_smallest != INT_MAX) ? second_smallest : -1};
// }

// Optimal Approach
std::vector<int> minAnd2ndMin(std::vector<int> &arr)
{
    int size = arr.size();
    if (size <= 1)
    {
        return {-1};
    }

    int smallest = INT_MAX;
    int second_smallest = INT_MAX;

    for (int i : arr)
    {
        if (i < smallest)
        {
            second_smallest = smallest;
            smallest = i;
        }
        else if (i < second_smallest && i != smallest)
        {
            second_smallest = i;
        }
    }
    if (second_smallest == INT_MAX)
    {
        return {-1};
    }
    return {smallest, second_smallest};
}

void print(std::vector<int> &arr)
{
    int size = arr.size();

    std::cout << "[";
    for (int i = 0; i < size; i++)
    {
        std::cout << i << ((i == (size - 1)) ? "" : ", ");
    }
    std::cout << "] ";
}

int main()
{
    std::vector<int> v;
    v.push_back(8);
    v.push_back(8);
    v.push_back(7);
    v.push_back(6);
    v.push_back(5);

    std::vector<int> ans = minAnd2ndMin(v);

    std::cout << "ans: " << ans[0] << ", " << ans[1] << std::endl;
    return 0;
}