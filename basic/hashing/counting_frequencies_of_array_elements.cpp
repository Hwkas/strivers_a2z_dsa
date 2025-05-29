#include <iostream>

// using arry to store map
// void count_frequencies(int *arr, int n)
// {
//     std::vector<int> map(16);
//     for (int i = 0; i < n; i++)
//     {
//         map[arr[i]]++;
//     }

//     for (int i = 0; i < map.size(); i++)
//     {
//         if (map[i] > 0)
//         {
//             std::cout << i << " -> " << map[i] << std::endl;
//         }
//     }
// }

// using unordered map
void count_frequencies(int *arr, int n)
{
    std::unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        map[arr[i]]++;
    }

    for (auto i : map)
    {
        std::cout << i.first << " -> " << i.second << std::endl;
    }
}

int main()
{
    int arr[] = {10, 5, 10, 15, 10, 5};
    int n = 6;
    count_frequencies(arr, n);
    return 0;
}
